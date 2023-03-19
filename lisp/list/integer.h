
#ifndef LIST_INTEGER_
#define LIST_INTEGER_

#include "list.h"

#include "../../../easycomp2022a/bigint.h" 

namespace list 
{

   struct integer : listbase 
   {
      bigint i;

      integer( ) = delete;

      integer( const bigint& i ) 
         : i(i)
      { }

      integer( bigint&& i )
         : i( std::move(i))
      { }

      bool equal_to( const list& lst ) const override
      {
         auto p = lst. try_cast< integer > ( );
         return p && i == p -> i;
      }

      void print( std::ostream& out ) const override
         { out << i; } 

      void prettyprint( std::ostream& out, indentation ind ) const override 
         { out << ind << i << '\n'; } 

   };

}

#endif


