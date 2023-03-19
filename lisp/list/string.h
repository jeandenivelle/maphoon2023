
#ifndef LIST_STRING_
#define LIST_STRING_

#include <string>
#include "list.h"

namespace list 
{

   struct string : listbase 
   {
      std::string s;

      string() = delete; 

      string( const std::string& s )
         : s(s)
      { }

      string( std::string&& s ) 
         : s( std::move(s) )
      { }

      bool equal_to( const list& lst ) const  
         { auto p = lst. try_cast< string > ( );
           return p && s == p -> s; } 
   
      void print( std::ostream& out ) const override; 
      void prettyprint( std::ostream& out, indentation ind ) const override
         { out << ind; print( out ); out << '\n'; } 
   };
} 

#endif

