
// Code written by Hans de Nivelle, April 2021.

#include "agent.h"

void agent::printall( std::ostream& stream )
{
   stream << "Table of Agents = {";

   const auto& map = getmap( ); 

   for( auto p = map. begin( ); p != map. end( ); ++ p )
   {
      if( p != map. begin( ))
         stream << ", ";
      else
         stream << " ";
      stream << p -> first << "/" << p -> second; 
   }
   stream << " }\n";
}


