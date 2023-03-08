
// Hans de Nivelle, November 2017.
// Dinislam Madikhanov, Summer 2021.  
// Kenessary Myrzakul, Summer 2021.
// Dastan Sultanov, Summer 2021.
// Danel Batyrbek, February/March 2022

#include "turingmachine.h"
#include "configuration.h"

#include "parsing/tokenizer.h"
#include "parsing/parser.h"

#include <iostream>

bool 
computewith( const turingmachine& tm, const std::string& initial, size_t maxconf = 10000 )
{
   reachable< configuration, configuration::cmp > reached( tm. blank );

   configuration first( tm. starting, initial );

   // If the starting state of the TM is also an accepting state,
   // it accepts every word.

   if( tm. accepting. contains( tm. starting ))
   {
      std::cout << "the turing machine accepts every word\n";
      std::cout << "because the starting state is an accepting state\n"; 
      return true; 
   }

   reached. addinitial( first ); 

   while( reached. nrunchecked( ) && reached. totalsize( ) <= maxconf ) 
   {
      auto it = reached. pop_unchecked( );
      const configuration& conf = ( it -> first );

      lhs needed = { conf.q, tm. blank }; 
         // We assume there are blank symbols to the right of 
         // the tape head. 

      if( conf. rightofhead. size( ))
         needed. req = conf. rightofhead. back( );
 
      auto r = tm. delta. equal_range( needed );

      for( auto p = r. first; p != r. second; ++ p )
      {
         auto next = conf. apply( p -> second, tm. blank );
         auto ins = reached. addchild( next, it ); 
         if( tm. accepting. contains( next. q ))
         {
            auto path = reached. getpathtowards( ins. first ); 
            std::cout << "found accepting computation:\n";
            for( const auto& c : path )
               std::cout << "   " << c << "\n";
            std::cout << "\n";
            return true; 
         }
      }
   }

   auto all = reached. getall( );

   std::cout << "\n";
   std::cout << "no accepting computation found\n";
   std::cout << "these are the reachable configurations:\n";

   for( size_t i = 0; i < all. size( ); ++ i )
   {
      for( const auto& c : all[i] )
         std::cout << i << " :   " << c << "\n";
   }
   std::cout << "\n\n";

   return false;

}


int main( int argc, char *argv[] )
{
   parsing::tokenizer tok( filereader( &std::cin, "std::cin" ));

   parsing::parser prs( tok );
   prs. checkattrtypes = 1;
   prs. checkmovable = 0;

   prs. debug = 0;

   auto res = prs. parse( parsing::sym_MachineWithInputs );

   // std::cout << "parser returned " << res << "\n"; 

   if( res. type != parsing::sym_MachineWithInputs )
   {
      // This means that an error occurred.

      std::cout << "this means that the parse was not successful\n"; 
      return -1;
   }

   auto& attr = res. get< std::pair< turingmachine, std::vector< std::string >>> ( );

   turingmachine tm = std::move( attr. first ); 
   std::vector< std::string > inputs = std::move( attr. second ); 

   std::cout << tm << "\n";

   std::cout << "states " << tm. states( ) << "\n";
   std::cout << "left symbols " << tm. gamma_left( ) << "\n";
   std::cout << "right symbols " << tm. gamma_right( ) << "\n";

   if( inputs. size( ) == 0 )
   {
      std::cout << "no input words\n\n";
      return 0;
   }

   for( size_t i = 0; i != inputs. size( ); ++ i ) 
   {
      std::cout << "input #" << i << " :  " << inputs[i] << "\n"; 
      computewith( tm, inputs[i] );
   }

   return 0; 
}


