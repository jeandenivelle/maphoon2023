
#include "opdef.h"


const char* prolog::getcstring( optag tag )
{
   switch( tag )
   {
   case fx:
      return "fx";
   case fy:
      return "fy";
   
   case xfx:
      return "xfx";
   case xfy:
      return "xfy";
   case yfx:
      return "yfx";

   case xf:
      return "xf";
   case yf:
      return "yf";

   }
   return "???";  
}


int prolog::opdef::decide( const opdef& other ) const
{
   // Smaller number means more attraction:

   if( attraction < other.attraction )
      return -1;

   if( attraction > other.attraction )
      return 1;

   if( type == fx || type == xfx || type == yfx ) 
   {
      if( other. type == yf || other. type == yfx )
         return -1;
      return 0;
   }

   if( type == fy || type == xfy )
   {
      if( other. type == xf || other. type == xfx || other. type == xfy )
          return 1;
      return 0;
   }

   return 0;
}


bool prolog::opdef::sameside( const opdef& other ) const
{
   if( type == fx || type == fy )
      return other. type == fx || other. type == fy;

   if( type == xfx || type == xfy || type == yfx )
      return other. type == xfx || other. type == xfy || other. type == yfx;

   if( type == xf || type == yf )
      return other. type == xf || other. type == yf; 

   return false;   // unreachable, but otherwise compiler cries.  
}


bool prolog::operator == ( const opdef& def1, const opdef& def2 )
{
   return def1. str == def2. str && 
          def1. type == def2. type &&  
          def1. attraction == def2. attraction; 
}


bool prolog::operator != ( const opdef& def1, const opdef& def2 ) 
{
   return def1. str != def2. str ||
          def1. type != def2. type ||
          def1. attraction != def2. attraction; 
}


std::ostream& prolog::operator << ( std::ostream& out, const opdef& def )
{
   out << "opdef( "; 
   out << def. str << ", " << def. type << ", " << def. attraction;
   out << " )";
   return out;
}


