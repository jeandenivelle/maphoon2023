
#ifndef PROLOG_FUNCTIONAL_
#define PROLOG_FUNCTIONAL_  1

#include <iostream> 
#include <vector>

#include "term.h"
#include "function.h"

namespace prolog 
{

   class functional : public termbase
   {

      function f;
      std::vector< term > sub;

   public: 
      functional( const function& f, std::vector< term > && sub = { } )
         : f(f),
           sub( std::move( sub ))
      { }

      functional( const std::string& f, std::vector< term > && sub = { } )
         : f( function( f, sub. size( ))),
           sub( std::move( sub ))
      { }

      functional( const function& f, term&& sub1 )
         : functional(f) 
      {
         sub. push_back( std::move( sub1 ));
      }

      functional( const function& f, term&& sub1, term&& sub2 )
         : functional(f) 
      {
         sub. push_back( std::move( sub1 ));
         sub. push_back( std::move( sub2 ));
      }
 
      const function& getfunction( ) const { return f; }
      size_t getarity( ) const { return sub. size( ); }

      const term& operator[] ( size_t i ) const { return sub[i]; }

      bool equal_to( const term& t ) const override;
      void print( std::ostream& out ) const override;
      void printhash( util::hashbuilder& hh ) const override;

   };

}

#endif

