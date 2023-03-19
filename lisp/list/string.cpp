
#include "string.h"

namespace
{
   void hexdigit( std::ostream& out, int x )
   {
      x &= 0XF;

      if( x >= 10 )
         out. put( 'A' + x - 10 );
      else
         out. put( '0' + x );
   }

   void print( std::ostream& out, char c )
   {
      switch(c)
      {
      case '\t':
         out << "\\t"; return;
      case '\n':
         out << "\\n"; return; 
      case '\"':
         out << "\\\""; return; 
      } 
     
      if( isprint(c))
      {
         out. put(c); 
         return;
      }

      out << "\\x";
      hexdigit( out, c >> 4 ); hexdigit( out, c);  
   }
}

void list::string::print( std::ostream& out ) const 
{
   out << '\"';
   for( char c : s )
      ::print( out, c );
   out << '\"'; 
}

