
#ifndef LIST_CHARACTER_
#define LIST_CHARACTER_

#include "list.h"

namespace list 
{

   struct character : listbase 
   {
      char c;

      character( ) = delete;

      character( char c ) 
         : c(c)
      { }

      bool equal_to( const list& lst ) const  
         { auto p = lst. try_cast< character > ( );
           return p && c == p -> c; } 
   
      void print( std::ostream& out ) const override; 
      void prettyprint( std::ostream& out, indentation ind ) const override
         { out << ind; print( out ); out << '\n'; } 
 
   };
} 

#endif

