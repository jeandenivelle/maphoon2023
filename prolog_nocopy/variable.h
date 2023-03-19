
// Written by Hans de Nivelle, September 2021.

#ifndef PROLOG_VARIABLE_
#define PROLOG_VARIABLE_   1

#include <iostream>
#include <vector>


namespace prolog
{

   struct variable : public termbase 
   {
      std::string s;       // The string is not part of the identity. 

      variable( const std::string& s )
         : s(s)
      { }
      
      bool equal_to( const term& t ) const override
      {
         auto* p = t. try_cast< variable > ();
         return p && ( s == p -> s );
      }

      void print( std::ostream& out ) const override
         { out << s; } 

      void printhash( util::hashbuilder& b ) const override
         { std::hash< std::string > hv; b << hv(s); } 

      ~variable( ) = default; 
   };

}

#endif


