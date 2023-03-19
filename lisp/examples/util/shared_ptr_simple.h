
// Written by Hans de Nivelle, 17 march 2021.
// A better shared_ptr. I dislike std::shared_ptr.

#ifndef UTIL_SHARED_PTR_INCLUDED
#define UTIL_SHARED_PTR_INCLUDED  1

#include <iostream>

namespace util
{
   // D must have void print( std::ostream& ) const 
   // a clone method, and a moving clone method.
   // The current implementation is unsafe when it 
   // cannot allocate the size_t for the counter.
   // In that case, p will not be deleted.

   template< typename D > 
   struct shared_ptr
   {
      D* p;
      size_t* counter;
         // Unfortunately, they must be separate.

      shared_ptr( D* p ) 
         : p(p),
           counter( new size_t(1) )
      { }

      shared_ptr( const shared_ptr& sh ) noexcept 
         : p( sh. p ),
           counter( sh. counter ) 
      {
         ++ *counter;  
      }

      shared_ptr& operator = ( shared_ptr&& sh ) noexcept
      {
         std::swap( p, sh.p );
         std::swap( counter, sh.counter );
         return *this; 
      }

      shared_ptr& operator = ( const shared_ptr& sh )
      {
         *this = shared_ptr( sh );
         return *this; 
      }

      ~shared_ptr( )
      {
         if( ! -- * counter )
         {
            delete counter; 
            delete p; 
         }
      }

      // Completely unprotected:

      D& operator * ( ) 
      {   
         return *p;
      }

      const D& operator * ( ) const
      {
         return *p;
      }

      D* operator -> ( ) 
      {
         return p;
      }

      const D* operator -> ( ) const
      {
         return p;
      }

   };

}


#endif


