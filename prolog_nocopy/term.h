
// Written by Hans de Nivelle, Sept 2021.
//
// Modified to be move only.

#ifndef PROLOG_TERM_
#define PROLOG_TERM_  1

#include "../../easycomp2022a/util/unique_ptr.h"
#include "../../easycomp2022a/util/hashbuilder.h"


namespace prolog
{
   struct termbase;

   using term = util::unique_ptr< termbase > ; 

   struct termbase
   {
      // Only move, no copy:

      termbase( ) = default; 
      termbase( termbase&& ) noexcept = default; 
      termbase( const termbase& ) = delete;
      termbase& operator = ( termbase&& ) noexcept = default; 
      termbase& operator = ( const termbase& ) = delete;
      virtual ~termbase( ) = default; 

      virtual bool equal_to( const term& ) const = 0; 
      virtual void print( std::ostream& out ) const = 0; 
      virtual void printhash( util::hashbuilder& hh ) const = 0;
   };

   inline std::ostream& operator << ( std::ostream& out, const term& t )
   {
      t -> print( out );
      return out;
   }

   inline 
   util::hashbuilder& operator << ( util::hashbuilder& hh, const term& t )
   {
      t -> printhash( hh );
      return hh;
   }

   struct term_hash
   {
      size_t operator( ) ( const term& t ) const
         { util::hashbuilder b; t -> printhash(b); return b.val; }
   };

   struct term_equal_to
   {
      bool operator( ) ( const term& t1, const term& t2 ) const
         { return t1 -> equal_to( t2 ); } 
   };

}

#include "variable.h" 
#include "constant.h"
#include "functional.h"

#endif 


