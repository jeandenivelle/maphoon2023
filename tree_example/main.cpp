#include <cstring>
#include <memory>

#include "symbol.h"
#include "syntaxerror.h" 
#include "topdownparser.h"
#include "parser.h" 

int main( int argc, char* argv[] )
{
   tree tr( (std::string) "aaa", { tree(4), tree( (std::string)"aa" ), tree( 2.1 ) } );
   std::cout << tr << "\n";
   tr. print( std::cout );

   
   filereader read( &std::cin, "stdin" );

   constexpr bool bottomup = true;
 
   if( bottomup )
   {
      std::cout << "this is the bottom up parser\n\n";
 
      std::cout << ":- "; 
      parser prs( read );
      auto result = prs. parse( sym_mainloop );
   }
   else 
   {
      std::cout << "this is the top down parser\n\n";
      while( true )
      {
         std::cout << ":- ";
         topdownparser prs( read ); 
         prs. show = true; 

         try {
            auto result = prs.parseE( );
            std::cout << "this was the input: " << result << "\n\n";

            if( prs. peek(). type != sym_DOT ){
               std::string msg = "expected a dot, ";
               msg += "but instead found ";
               msg += getcstring( prs. peek( ). type );
               throw syntaxerror( msg, read. line, read. column );
            }

            prs. move( ); 

            if( result. nrsubtrees() == 0 && 
                result. hasstring() && result. getstring() == "quit" )
            {
               std::cout << "Quitting\n";
               return 0; 
            }
         }
         catch( const syntaxerror& err )
         {
            std::cout << err. what( ) << "\n"; 
         }
      }
   }
   return 0;
}

