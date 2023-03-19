
#ifndef LIST_CONS_
#define LIST_CONS_

#include "list.h"

namespace list
{

   struct cons : public listbase
   {
      list first;
      list rest;

      cons( ) = delete;

      cons( const list& first, const list& rest )
         : first( first ), rest( rest )
      { }

      cons( list&& first, list&& rest )  
         : first( std::move( first )),
           rest( std::move( rest ))
      { } 

      bool equal_to( const list& ) const override;
      void print( std::ostream& out ) const override;
      void prettyprint( std::ostream& out, indentation ) const override;

      bool iscons( ) const override { return true; }  
   };

}

#endif

