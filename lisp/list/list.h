
#ifndef LIST_LIST_
#define LIST_LIST_

#include "../../../easycomp2022a/util/shared_ptr.h"
#include "../../indentation.h"

namespace list 
{
   struct listbase;

   using list = util::shared_ptr< listbase >;

   struct listbase 
   {
      listbase() noexcept = default;
      virtual ~listbase( ) = default;

      virtual bool equal_to( const list& ) const = 0;
      virtual void print( std::ostream& out ) const = 0;
      virtual void prettyprint( std::ostream& out, 
                                indentation ind = indentation( )) const = 0;

      virtual bool isnil( ) const { return false; }
      virtual bool iscons( ) const { return false; }
   };

   inline std::ostream& operator << ( std::ostream& out, const list& lst )
   {
      lst -> print( out );
      return out;
   }

   list build( std::initializer_list< list > sub );

} 

#include "atom.h"
#include "string.h"
#include "character.h"
#include "integer.h"
#include "floating.h" 
#include "quote.h" 
#include "nil.h"
#include "cons.h"

#endif


