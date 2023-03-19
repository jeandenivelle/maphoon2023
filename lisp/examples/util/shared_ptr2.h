
// Written by Hans de Nivelle, 17 march 2021.
// A better shared_ptr. I dislike std::shared_ptr.

// The last word is not yet spoken about this implementation.

#ifndef UTIL_SHARED_PTR_INCLUDED
#define UTIL_SHARED_PTR_INCLUDED  1

#include <iostream>

namespace util
{

   template< typename D > 
   struct shared_ptr
   {
      D* p;
      size_t* counter;

      shared_ptr( D* p ) 
         : p(p),
           counter( nullptr ) 
      { 
         counter = new size_t(1); 
            // It must be like this, because the allocation may throw. 
      }

      shared_ptr( const shared_ptr& sh ) noexcept
         : p( sh. p ), 
           counter( sh. counter ) 
      {
         ++ * ( sh. counter ); 
      }

      shared_ptr& operator = ( shared_ptr&& sh ) noexcept
      {
         std::swap( p, sh. p );
         std::swap( counter, sh. counter );
         return *this; 
      }

      shared_ptr& operator = ( const shared_ptr& sh ) noexcept
      {
         *this = shared_ptr( sh );
         return *this; 
      }

      ~shared_ptr( ) noexcept
      {
         if( counter )
         {
            if( ! -- * counter )
            {
               delete counter; 
               delete p; 
            }
         }
         else
            delete p; 
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


