
%startsymbol Start EOF 

%symbol Start 
%symbol { term } Term OneTerm 

%symbol ERROR 
%symbol COMMENT WHITESPACE   
%symbol EOF 
%symbol { std::string } IDENTIFIER GLUEDIDENTIFIER
%symbol { std::string } QUOTEDIDENTIFIER GLUEDQUOTEDIDENTIFIER
%symbol LPAR RPAR
%symbol LSQBRACKET RSQBRACKET
%symbol { std::string } VARIABLE 
%symbol { double } DOUBLE 
%symbol { bigint } INTEGER 
%symbol { std::vector< term > } MaybeTerms SomeTerms
%symbol { term } ListEnd

%symbol { opdef } Prefix 
%symbol { opdef } Infix 
%symbol { opdef } Postfix

%symbol COMMA BAR TERMINATOR

%reductionseq Prefix Term  
%reductionseq Infix Postfix 

// %usererror    
   // Means that the user prefer to define their own error. 

%symbolcode_h{ #include "term.h" }
%symbolcode_h{ #include "syntax.h" }
%symbolcode_h{ #include "listconstr.h" }

%symbolcode_cpp
{ 
   void 
   print_attr( const std::vector< prolog::term > & vect, std::ostream& out ) 
   {
      print_range( vect. begin( ), vect. end( ), '{', '}', out );
   }

   void 
   print_attr( const prolog::term& trm, std::ostream& out )
   { 
      out << trm; 
   } 
}

%parsercode_h{ #include "tokenizer.h" }
%parsercode_h{ #include "../calculator/varstore.h" }

%parsercode_cpp{ 

namespace
{

   bool canbeprefix( const syntax& syntdefs, const symbol& sym )
   {
      std::cout << "can be prefix " << sym << " ?\n";
      if( sym. type != sym_IDENTIFIER ) return false;
      const auto& s = sym. get< std::string > ( );
      return syntdefs. hasprefixdef(s); 
   }

   bool canbeinfix( const syntax& syntdefs, const symbol& sym )
   {
      std::cout << "can be infix " << sym << " ?\n";
      if( sym. type != sym_IDENTIFIER ) return false;
      const auto& s = sym. get< std::string > ( );    
      return syntdefs. hasinfixdef(s); 
   } 

   bool canbepostfix( const syntax& syntdefs, const symbol& sym )
   {
      std::cout << "can be postfix " << sym << " ?\n";
      if( sym. type != sym_IDENTIFIER ) return false;
      const auto& s = sym. get< std::string > ( );    
      return syntdefs. haspostfixdef(s);
   } 

   bool canstartterm( const symbol& sym )
   {
      std::cout << "can start term " << sym << "\n";
      return sym.type == sym_IDENTIFIER ||
             sym.type == sym_GLUEDIDENTIFIER ||
             sym.type == sym_QUOTEDIDENTIFIER ||
             sym.type == sym_GLUEDQUOTEDIDENTIFIER || 
             sym.type == sym_LPAR ||
             sym.type == sym_LSQBRACKET ||
             sym.type == sym_VARIABLE ||
             sym.type == sym_INTEGER ||
             sym.type == sym_DOUBLE;
   }

   short int canreduce( const syntax& syntdefs,
                        const opdef& op, const symbol& sym )
   {
      std::cout << "deciding priorities between " << op << " and " << sym << "\n";
      if( sym. type != sym_IDENTIFIER )
         return 1;   // reduce.

      const std::string& str = sym. get< std::string > ( );

      // We do not really know what to do when there are
      // conflicting priorities. I suppose it should not happen. 

      if( syntdefs. haspostfixdef( str ))
      { 
         auto op2 = syntdefs. postfixdef( str );
         auto dir = op. decide( op2 );
         if( dir == -1 ) return 1;
         if( dir == 1 ) return 0;
         return -1;
      }

      if( syntdefs. hasinfixdef( str )) 
      { 
         auto op2 = syntdefs. infixdef( str );
         auto dir = op. decide( op2 );
         if( dir == -1 ) return 1;
         if( dir == 1 ) return 0;
         return -1;
      }

      return 1;
   }
}
}



%parameter { tokenizer } tok 
%parameter { varstore< term > } vs
%parameter { syntax } syntdefs 
%parameter { listconstr } list

%symbolspace prolog
%parserspace prolog

%source { tok. get( syntdefs ); }

%rules

Start => OneTerm:t TERMINATOR ;

OneTerm => Term:t  { timetosaygoodbye = true; return std::move(t); } ;

Term => 
   VARIABLE:v { return new variable(v); } 

|  DOUBLE : d { return new constant< double > (d); } 

|  INTEGER : i { return new constant< bigint > (i); } 

|  IDENTIFIER : id { return new functional( function( id, 0 )); } 

|  QUOTEDIDENTIFIER : id { return new functional( function( id, 0 )); } 

|  GLUEDIDENTIFIER : id LPAR MaybeTerms : args RPAR 
      { size_t ar = args. size( );
        return new functional( function( id, ar ), std::move( args ));
      }

|  GLUEDQUOTEDIDENTIFIER : id LPAR MaybeTerms : args RPAR
      { size_t ar = args. size( );
        return new functional( function( id, ar ), std::move( args ));
      }

|  Prefix:op Term:t
%requires
   { return canreduce( syntdefs, op, getlookahead( )); }
%reduces 
   { return new functional( function( op. str, 1 ), std::move(t) ); } 

|  Term:t1 Infix:op Term:t2 
%requires
   { return canreduce( syntdefs, op, getlookahead( )); }
%reduces 
   { return new functional( function( op. str, 2 ), std::move(t1), std::move(t2) ); }    

|  Term:t Postfix:op 
%reduces
   { return new functional( function( op. str, 1 ), std::move(t) ); }

|  LPAR Term:t RPAR { return std::move(t); } 

|  LSQBRACKET MaybeTerms :args ListEnd :end RSQBRACKET
   { auto res = std::move( end );
     size_t i = args. size( );
     while( i -- )
        res = new functional( list. cons, std::move( args[i] ), std::move( res ));
     return std::move( res );    
   }
;

MaybeTerms => 
   { return std::vector<term> ( );         /* empty rhs. */  }
   | SomeTerms : terms { return std::move(terms); } 
   ;

SomeTerms 
=> Term : t 
%requires 
   { return !canbeinfix( syntdefs, lookahead. value( )) &&
            !canbepostfix( syntdefs, lookahead. value( )); 
   }
%reduces
   { auto res = std::vector< term > ( ); res. push_back( std::move(t)); return res; } 


| SomeTerms : some  COMMA  Term : onemore
%requires
   { return !canbeinfix( syntdefs, lookahead. value( )) &&
            !canbepostfix( syntdefs, lookahead. value( )); 
   }
%reduces 
   { some. push_back( std::move( onemore )); return std::move( some ); } 
;

ListEnd => 
   { return new functional( list. nil ); } 
|
   BAR Term:t { return std::move(t); } 
;

Prefix => IDENTIFIER : id 
%requires
   { return syntdefs. hasprefixdef( id ) && canstartterm( lookahead. value( )); }
%reduces
   { return syntdefs. prefixdef(id); }  
;

Infix => IDENTIFIER : id  
%requires 
   { return syntdefs. hasinfixdef(id) && canstartterm( lookahead. value( )); }
%reduces 
   { return syntdefs. infixdef(id); }
;

Postfix => IDENTIFIER : id
%requires 
   { return syntdefs. haspostfixdef(id); }
%reduces  
   { return syntdefs. postfixdef(id); }  
;

%end

