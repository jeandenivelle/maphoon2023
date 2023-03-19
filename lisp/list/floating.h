
// The name 'float' cannot be used for obvious reasons.

#ifndef LIST_FLOATING_
#define LIST_FLOATING_

#include "list.h"

namespace list 
{

   struct floating : listbase 
   {
      double d;

      floating( ) = delete; 
      floating( double d ) : d(d) {}

      bool equal_to( const list& lst ) const override 
      {
         auto p = lst. try_cast<floating> ( );
         return p && d == p -> d;
      }
 
      void print( std::ostream& out ) const override 
         { out << d; }
      void prettyprint( std::ostream& out, indentation ind ) const override
         { out << ind << d << '\n'; } 
   };

} 

#endif

