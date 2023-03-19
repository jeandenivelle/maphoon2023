
#include "tokenizer.h"

#include "../../lexing2022/includes.h"

#if 1

namespace
{

   lexing::classifier< char, symboltype > buildclassifier( ) 
   {
      using namespace lexing;

      classifier< char, symboltype > cls( sym_ERROR ); 

      cls. insert( just( ';' ), sym_SEMICOLON );
  
      auto idfirst = range('a','z') | range('A','Z');
      auto idnext = range('a','z') | range('A','Z') | just('_') | range('0','9');

      cls. insert( idfirst * idnext. star( ), sym_ID );

      cls. insert( just( '$' ) * idfirst * idnext. star( ), sym_METAVAR );

      auto number = just('0') | ( range('1','9') * range('0','9'). star());
  
      cls. insert( number, sym_NUMBER ); 
      cls. insert( word( "TRUE" ) | word( "true" ) |
                word( "FALSE" ) | word( "false" ), sym_CONST );

      cls. insert( word( "NNF" ), sym_NNF );
      cls. insert( word( "RETURN" ), sym_RETURN );

      cls. insert( just( '~' ), sym_NOT );
      cls. insert( just( '&' ), sym_AND );
      cls. insert( just( '|' ), sym_OR );
      cls. insert( word( "->" ), sym_IMP );
      cls. insert( word( "<->" ), sym_EQUIV ); 
      cls. insert( word( "[]" ), sym_BOX );
      cls. insert( word( "<>" ), sym_DIA );

      cls. insert( just( '(' ), sym_LEFTPAR );
      cls. insert( just( ')' ), sym_RIGHTPAR );
      cls. insert( just( '[' ), sym_BOXSTART );
      cls. insert( just( ']' ), sym_BOXEND );
      cls. insert( just( '<' ), sym_DIASTART );
      cls. insert( just( '>' ), sym_DIAEND );

      cls. insert( just( '=' ), sym_BECOMES );

      cls. insert( just( '#' ), sym_EOF );

      // Whitespace, and the likes of it: 

      cls. insert( ( just(' ') | just('\t') | 
                     just('\n') | just('\v') |
                     just('\f' ) | just('\r')). plus( ), sym_WHITESPACE );

      cls. insert( word( "//" ) *
                   ( every<char>( ). without( '\n' )). star( ) * 
                   just( '\n' ), sym_COMMENT );

      cls. insert( word( "/*" ) *
         ( every<char>( ). without( '*' ) |
           ( just('*'). plus( ) * 
             every<char> ( ). without( '/' ). without( '*' )). star( )
           ). star( ) * 
         just( '*' ). plus( ) * just( '/' ), sym_COMMENT );

      cls = make_deterministic( cls );
      std::cout << "automaton has " << cls. nrstates( ) << " states\n";
      cls = minimize( cls );
      std::cout << "after minimization " << cls. nrstates( ) << "\n";
      auto nrstates = cls. nrstates( );
      cls = minimize( make_deterministic( cls ));
      if( cls. nrstates( ) < nrstates )
      {
         std::cout << "it went further down to " << cls. nrstates( ) << "\n";
         std::cout << "that is a bug\n";
         throw std::runtime_error( "bug" ); 
      }
      std::cout << "automaton " << cls << "\n";

      std::ofstream file( "DFA.h" );
      printcode<char, symboltype> (
        "char", "symboltype", {},
         cls, file,
         []( std::ostream& out, char c ) { out << (int)c; },
         []( std::ostream& out, const symboltype t ) { out << "sym_" << t; } );
      file. close( );

      return cls;
   }
}

#endif

#include "DFA.h"

symbol tokenizer::get( ) 
{
   static auto cls = buildclassifier( ); 
   // static auto cls = 33;
 
restart:
   // Restart after whitespace, or comment

   if( !read. has(1) )
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

   // If whitespace or other forms of blabla, we restart:

   if( p. first == sym_WHITESPACE || p. first == sym_COMMENT )
   {
      read. commit( p. second );
      goto restart;
   }

   if( p. first == sym_NUMBER )
   {
      unsigned int val = std::stoul( std::string( read. view( p. second )));
      read. commit( p. second );
      return symbol( sym_NUMBER, val );
   }

   if( p. first == sym_ID || p. first == sym_METAVAR )  
   {
      std::string name = std::string( read. view( p. second ));
      read. commit( p. second );
      return symbol( p. first, name );
   }

   if( p. first == sym_CONST )
   {
      bool b = false;
      if( read. peek(0) == 't' || read. peek(0) == 'T' )
         b = true;
      read. commit( p. second );
      return symbol( sym_CONST, b );
   }

   // All remaining symbols have no attribute:

   read. commit( p. second );
   return symbol( p. first ); 
}


void tokenizer::test( ) 
{
   symbol sym = get( ); 
   while( sym.type != sym_EOF && sym.type != sym_SEMICOLON )
   {
      std::cout << sym << "\n";
      sym = get( ); 
   }
   std::cout << "that's the end of the file\n";
}


void tokenizer::print( std::ostream& out ) const
{
   out << "tokenizer: " << read;
}


