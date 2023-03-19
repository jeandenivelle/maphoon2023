
#include "tokenizer.h"

const char* 
prolog::tokenizer::getcstring( context c )
{
   switch(c)
   {
   case ct_list:  return "list";
   case ct_func:  return "func";
   case ct_par:   return "par";
   case ct_glued: return "glued";
   }
   return "???"; 
}


namespace prolog 
{
   namespace 
   {

      lexing::classifier< char, prolog::symboltype > buildclassifier( ) 
      {
         lexing::classifier< char, symboltype > cls( sym_ERROR ); 

         auto idfirst = lexing::range('a','z');
         auto varfirst = lexing::range('A','Z') | lexing::just( '_' );

         auto idnext = lexing::range('a','z') | lexing::range('A','Z') | 
                          lexing::just('_') | lexing::range('0','9');

         cls. insert( idfirst * idnext. star( ), sym_IDENTIFIER );

         std::string inop = 
            "~ ! @ # $ ^ & * - + = \\ / : ; | { } [ ] < > ? . "; 
               // Spaces will not be considered.

         auto op = lexing::empty< char > ( ); 
         for( char c : inop )
         {
            if( c != ' ' )
               op |= lexing::just(c);
         }

         cls. insert( op. without( '[' ). without( ']' ) * op. star( ), 
                      sym_IDENTIFIER );

         cls. insert( lexing::just( ',' ), sym_IDENTIFIER );

         cls. insert( varfirst * idnext. star( ), sym_VARIABLE );

         auto number = lexing::just('0') |
                      ( lexing::range('1','9') *
                              lexing::range('0','9'). star());
 
         auto exp = ( lexing::just( 'e' ) | lexing::just( 'E' )) *
                    ( lexing::just( '-' ) | lexing::just( '+' )). optional( ) *
                 ( lexing::range( '0', '9' ). optional( ) *
                   lexing::range( '0', '9' ). optional( ) *
                   lexing::range( '0', '9' ). optional( ));

         auto doubleconst = number *
                      ( lexing::just( '.' ) * 
                      ( lexing::range( '0', '9' ). plus() )). optional( ) *
                        exp. optional( );

         cls.insert( lexing::just( '-' ). optional( ) * doubleconst, sym_DOUBLE );
 
         cls. insert( lexing::just( '-' ). optional( ) * number, sym_INTEGER ); 

         cls. insert( lexing::just( '(' ), sym_LPAR );
         cls. insert( lexing::just( ')' ), sym_RPAR );
         cls. insert( lexing::just( '[' ), sym_LSQBRACKET );
         cls. insert( lexing::just( ']' ), sym_RSQBRACKET );

         std::string quotes = " \' \" ` ";
            // Spaces will be ignored below.
 
         auto inquote = lexing::every<char>( ).without( '\n' ).without( '\\' ); 

         auto escape = lexing::just( '\\' ) * 
              ( lexing::every<char> ( ). without( '\n' )); 

         for( auto q : quotes ) 
         {
            if( q != ' ' ) 
            {
               auto str = lexing::just(q) * 
                          ( inquote. without(q) | escape ). star( ) * 
                          lexing::just(q); 
      
               cls. insert( str, sym_QUOTEDIDENTIFIER ); 
            }
         }

         // Whitespace, and the likes of it: 

         cls. insert( ( lexing::just(' ') | lexing::just('\t') | 
                        lexing::just('\n') | lexing::just('\v') | 
                        lexing::just('\f') | lexing::just('\r')). plus( ), 
                      sym_WHITESPACE );

         cls. insert( lexing::word( "%" ) *
                ( lexing::every<char>( ). without( '\n' )). star( ) * 
                lexing::just( '\n' ), sym_COMMENT );

         cls. insert( lexing::word( "/*" ) *
            ( lexing::every<char>( ). without( '*' ) |
              ( lexing::just('*'). plus( ) * 
                lexing::every<char> (). without('/'). without('*' )). star( )
            ). star( ) * 
            lexing::just( '*' ). plus( ) * lexing::just( '/' ), sym_COMMENT );

         cls. insert( lexing::just( '#' ), sym_EOF );

         cls = make_deterministic( cls );
         cls = minimize( cls );
         // std::cout << "automaton " << cls << "\n";

#if 1
         std::ofstream file( "DFA.h" );
         lexing::printcode<char, symboltype> (
           "char", "symboltype", { "prolog" },
            cls, file,
            []( std::ostream& out, char c ) { out << (int)c; },
            []( std::ostream& out, const symboltype t ) 
                                         { out << "sym_" << t; } );
         file. close( );
#endif

         return cls;
      }
}}

#include "DFA.h"

prolog::symbol 
prolog::tokenizer::get( const syntax& synt ) 
{
   static auto cls = buildclassifier( ); 
      // If you want to call buildclassifier, make sure that
      // the lexer is available in lexing2022. 

   // static auto cls = 33;

   if constexpr( false )
   {
      std::cout << "contextstack: ";
      for( const auto c : contextstack )
         std::cout << getcstring(c) << " ";
      std::cout << "\n";
   }
 
restart:
   // Restart after whitespace, or comment

   if( !read. has(1))
      return symbol( sym_EOF );

   auto p = readandclassify( cls, read );
   // std::cout << "p = " << p. first << "/" << p. second << "\n";   

   // I think it has to be done like this.
   // Or one creates a garbage token with lowest priority.
   // Explictly creating an error token of size 1 is wrong.

   if( p. second == 0 )
   {
      read. commit(1);
      return symbol( sym_ERROR );
   }

   // If whitespace or some other form of blabla, we restart:

   if( p. first == sym_WHITESPACE || p. first == sym_COMMENT )
   {
      read. commit( p. second );
      goto restart;
   }

   if( p. first == sym_INTEGER )
   {
      bigint val = read. view( p. second );
      read. commit( p. second );
      return symbol( sym_INTEGER, std::move( val ));
   }

   if( p. first == sym_DOUBLE )
   {
      double val = std::stod( std::string( read. view( p. second )));
      read. commit( p. second );
      return symbol( sym_DOUBLE, val );
   }

   if( p. first == sym_IDENTIFIER || p. first == sym_QUOTEDIDENTIFIER )  
   {
      // If we are quoted, we copy without the quotes:

      std::string_view v = read. view( p. second );
      if( p. first == sym_QUOTEDIDENTIFIER )
      {
         v. remove_prefix(1);
         v. remove_suffix(1);
      }

      std::string val = std::string(v); 
      read. commit( p. second );

      // We have to decide if we are glued:

      auto idtype = p. first;

      if( read.has(1) && read. peek(0) == '(' )
      {
         if( idtype == sym_IDENTIFIER )
            idtype = sym_GLUEDIDENTIFIER;
         if( idtype == sym_QUOTEDIDENTIFIER )
            idtype = sym_GLUEDQUOTEDIDENTIFIER;
      }

      if( idtype == sym_IDENTIFIER || idtype == sym_GLUEDIDENTIFIER )
      {
         if( contextstack. size( ) == 0 && synt. terminator == val )
            return sym_TERMINATOR;

         if( contextstack. size( ) != 0 && 
             ( contextstack. back( ) == ct_func || 
               contextstack. back( ) == ct_list ) &&
             val == "," )
         {
            return sym_COMMA;
         }

         if( contextstack. size( ) != 0 &&
             contextstack. back( ) == ct_list && val == "|" )
         {
            return sym_BAR;
         }
      }

      if( idtype == sym_GLUEDIDENTIFIER ||
          idtype == sym_GLUEDQUOTEDIDENTIFIER )
      {
         contextstack. push_back( ct_glued );
      }

      return symbol( idtype, std::move( val ));
   }

   if( p. first == sym_VARIABLE )
   {
      std::string val = std::string( read. view( p. second ));
      read. commit( p. second );
      return symbol( sym_VARIABLE, std::move( val ));
   }

   // Some context maintenance:

   if( p. first == sym_LPAR )
   {
      if( contextstack. size( ) == 0 )
         contextstack. push_back( ct_par );
      else
      {
         if( contextstack. back( ) == ct_glued )
            contextstack. back( ) = ct_func;
         else
            contextstack. push_back( ct_par );
      }
   }

   if( p. first == sym_LSQBRACKET )
      contextstack. push_back( ct_list );

   if( p. first == sym_RPAR && 
       contextstack. size( ) != 0 && 
       ( contextstack. back( ) == ct_func || contextstack. back( ) == ct_par ))
   {
      contextstack. pop_back( );
   }

   if( p. first == sym_RSQBRACKET &&
       contextstack. size( ) != 0 &&
       contextstack. back( ) == ct_list )
   {
      contextstack. pop_back( );
   }
    
   // All remaining symbols have no attribute:

   read. commit( p. second );
   return symbol( p. first ); 
}


void prolog::tokenizer::test( const syntax& synt ) 
{
   symbol sym = get( synt ); 
   while( sym.type != sym_EOF )
   {
      std::cout << sym << "\n";
      sym = get( synt ); 
   }
   std::cout << "that's the end of the file\n";
}


void prolog::tokenizer::print( std::ostream& out ) const
{
   out << "tokenizer: " << read;
}


