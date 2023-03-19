
#include "list.h"

list::list
list::build( std::initializer_list< list > args )
{
   list res = new nil( );
   auto p = args. end( );
   while( p -- != args. begin( ))
   {
      res = new cons( *p, res ); 
   }
   return res;
}

