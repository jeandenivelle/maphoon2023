
// Written by Hans de Nivelle, September 2021.

#ifndef PROLOG_CONSTANT_
#define PROLOG_CONSTANT_   1

#include <iostream>
#include <vector>

#include "bigint.h" 

namespace prolog
{

   template< typename C > 
   struct constant : public termbase 
   {
      C c; 

      constant( ) = delete;

      constant( const C& c )  
         : c(c) 
      { }

      constant( C&& c ) noexcept 
         : c( std::move(c)) 
      { }

      bool equal_to( const term& t ) const override
      {
         auto* p = t. try_cast< constant<C>> ();
         return p && ( c == p -> c );
      }

      void print( std::ostream& out ) const override
         { out << c; }

      void printhash( util::hashbuilder& b ) const override;
         // Must be specialized for the concrete types.

      ~constant( ) = default; 
   };

   template<>
   inline void constant<bool> :: printhash( util::hashbuilder& hh ) const
      { hh << 1 << c; }

   template<> 
   inline void constant<size_t> :: printhash( util::hashbuilder& hh ) const
      { hh << 2 << c; }

   template<>
   inline void constant<double> :: printhash( util::hashbuilder& hh ) const
      { const std::hash<double> d; hh << 3 << d(c); } 

   template<>
   inline void constant<bigint> :: printhash( util::hashbuilder& hh ) const
      { hh << 4 << c. hash( ); }       

   template<>
   inline void constant<std::string> :: printhash( util::hashbuilder& hh ) const
      { const std::hash<std::string> s; hh << 5 << s(c); } 

}

#endif


