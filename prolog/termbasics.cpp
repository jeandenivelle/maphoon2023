
#include "termbasics.h"

std::ostream& 
prolog::operator << ( std::ostream& out, const prolog::term& t )
{

   switch( t. sel( ))
   {
   case sel_double:
      {
         auto p = t. view_double( );
         out << "double " << p. d( ); 
      }
      return out; 
   case sel_int:
      {
         auto p = t. view_int( );
         out << "int " << p. i( );
      }
      return out;
   case sel_bigint:
      {
         auto p = t. view_bigint( );
         out << "bigint( " << p. i( ) << " )";
      }
      return out;
   case sel_atom:
      {
         auto p = t. view_atom( );
         out << "atom( " << p. name( ) << " )";
      }
      return out;
   case sel_string:
      {
         auto p = t. view_string( );
         out << "string( " << p. s( ) << " )"; 
      }
      return out; 
   case sel_functional:
      {
         auto p = t. view_func( );
         out << p. f( ). getstring( ) << "(";
         for( size_t i = 0; i != p. size( ); ++ i )
         {
            if(i) 
               out << ", ";
            else
               out << " ";
            out << p. sub(i);
         }
         out << " )";
      }
      return out; 
   default:
      out << "print not implemented for " << t. sel( ) << "\n";
   }

   return out; 
}

