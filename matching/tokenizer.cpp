
#include "tokenizer.h"
#include "../../lexing2022/includes.h"


lexing::classifier< char, symboltype > buildclassifier( )
{
   using namespace lexing;

   classifier< char, symboltype > cls( sym_ERROR );

   cls. insert( just( ';' ), sym_SEMICOLON );
   cls. insert( word( "%end" ), sym_END );

   auto val = range('a','z') | range('A','Z') | range('0','9') |
              just( '-' ) | just( '+' ) | just( '_' );

   cls. insert( val. plus( ), sym_VALUE );

   auto whitespace = ( just( ' ' ) | just( '\t' ) | just( '\v' ) |
                       just( '\f' ) | just( '\r' )). plus( );
         // Whitespace that stays on the same line.

   cls. insert( whitespace, sym_WHITESPACE );
   
   cls. insert( just( '\n' ), sym_NEWLINE );
   cls. insert( word( "//" ) * ( every<char>( ). without( '\n' )). star( ), sym_COMMENT );

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
   std::cout << cls << "\n";

   return cls;

}


symbol tokenizer::get( )
{
   static auto cls = buildclassifier( );
   // static auto cls = 33;

restart:
   // Restart after whitespace, or comment

   if( !inp. has(1) )
      return symbol( sym_END );

   auto p = readandclassify( cls, inp );
   std::cout << "p = " << p. first << "/" << p. second << "\n";

   if( p. second == 0 )
   {
      inp. commit(1);
      return symbol( sym_ERROR );
   }

   if( p. first == sym_WHITESPACE ) 
   {
      inp. commit( p. second );
      goto restart;
   }

   if( p. first == sym_VALUE )
   {
      std::string attr = std::string( inp. view( p. second )); 
      inp. commit( p. second );
      return symbol( sym_VALUE, std::move( attr )); 
   }

   if( p. first == sym_COMMENT )
   {
      inp. commit( p. second );
      return symbol( sym_COMMENT );
   }

   inp. commit( p. second ); 
   return symbol( p. first ); 
}


void tokenizer::test( )
{
   symbol sym = get( );
   while( sym.type != sym_END )
   {
      std::cout << sym << "\n";
      sym = get( );
   }
   std::cout << "that's the end of the file\n";
}


