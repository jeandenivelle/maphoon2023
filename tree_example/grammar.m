%startsymbol mainloop EOF
%keepclosures

%symbol{} LOOKAHEAD_EMPTY

%symbol{} ASSIGN
%symbol{} EOF ERROR
%symbol{} LPAR RPAR COMMA DOT
%symbol{} PLUS MINUS TIMES DIVIDES
%symbol{} BLOCKCOMMENT WHITESPACE

%symbol{ bigint      } INTEGER 
%symbol{ double      } DOUBLE 
%symbol{ std::string } STRING

%symbol{ tree } expr expr1 expr2 expr3
%symbol{ util::shared_vector< tree > } exprlist

%symbol{} mainloop

%symbolcode_h  { #include "tree.h" }

%parameter{ filereader } r

%symbolcode_cpp{

namespace {

  std::ostream& operator << ( std::ostream& out,
                              const util::shared_vector< tree > & vect )
  {
    out << "( ";
    for( size_t i = 0; i != vect. size( ); ++ i )
    {
      if( i != 0 ) out << ", ";
      out << vect[i];
    }
    out << ")";
    return out;
  }

}}

%parsercode_h { 
#include "tokenizing.h" 
}

%source { readsymbol( r ); }

%rules

mainloop => mainloop expr:e DOT
{
   std::cout << "RESULT:\n" << e << '\n';
   if( e. nrsubtrees( ) == 0 && e. hasstring( ) && e. getstring( ) == "quit" )
   {
      std::cout << "quitting\n"; 
      timetosaygoodbye = true; 
   }
   // print a prompt: 
   std::cout << ":- "; 
}

|
;

expr => expr1:e
{
  return e;
}
| expr1:e1 PLUS expr1:e2
{
  return tree( std::string( "+" ), { e1, e2 } );
}
| expr1:e1 MINUS expr1:e2
{
  return tree( std::string( "-" ), { e1, e2 } );
}
;

expr1 => expr2:e
{
   return e;
}
| expr1:e1 TIMES expr2:e2
{
   return tree( std::string( "*" ), { e1, e2 } );
}
| expr1:e1 DIVIDES expr2:e2
{
   return tree( std::string( "/" ), { e1, e2 } );
}
;

expr2 => expr3:e
{
  return e;
}
| MINUS expr2:e
{
  return tree( std::string( "-" ), { e } );
}
;

expr3 => INTEGER:i
{
  return tree( i );
}
| DOUBLE:d
{
  return tree( d );
}
| STRING:s
{
  return tree( s );
}
| STRING:s LPAR exprlist:list RPAR
{
  return tree( s, list );
}
| LPAR expr:e RPAR
{
  return e;
}
;

exprlist => expr:e
{
  util::shared_vector< tree > vec;
  vec. push_back( e );
  return vec;
}
| exprlist:a COMMA expr:e
{
  a. push_back( e );
  return a;
}
;
