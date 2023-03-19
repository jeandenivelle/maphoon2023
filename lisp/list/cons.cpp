
#include "cons.h"


// I think we are observing the complete collapse of C++ here:

bool list::cons::equal_to( const list& lst ) const
{
   const listbase* lst1 = this;
   const list* lst2 = & lst; 

   while( lst1 -> iscons( ) && (*lst2) -> iscons( )) 
   {
      auto p1 = dynamic_cast< const cons* > ( lst1 );
      auto p2 = lst2 -> try_cast< cons > ( ); 

      if( ! p1 -> first -> equal_to( p2 -> first ))
         return false; 

      lst1 = & * p1 -> rest; 
      lst2 = & p2 -> rest; 
   } 

   if( lst1 -> iscons( ) || (*lst2) -> iscons( ))
      return false;
   else
      return lst1 -> equal_to( *lst2 ); 
}


void list::cons::print( std::ostream& out ) const
{
   auto lst = *this; 
   out << "( ";
   while( lst. rest -> iscons( )) 
   {
      lst. first -> print( out );
      out << ' '; 

      lst = dynamic_cast< const cons & > ( * lst. rest );
   } 

   lst. first -> print( out );
   if( ! lst. rest -> isnil( ))
   {
      out << " . ";
      lst.rest -> print( out );
   }

   out << " )"; 
}


void list::cons::prettyprint( std::ostream& out, indentation ind ) const
{
   auto lst = *this;
   out << ind << "(\n";
   while( lst. rest -> iscons( ))
   {
      lst. first -> prettyprint( out, ind + 3 );

      lst = dynamic_cast< const cons & > ( * lst. rest );
   }

   lst. first -> prettyprint( out, ind + 3 );
   if( ! lst. rest -> isnil( ))
   {
      out << ( ind + 3 ) << ". "; 
      lst.rest -> print( out );
      out << '\n';
   }

   out << ind << ')' << '\n';
}


