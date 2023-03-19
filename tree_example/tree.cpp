
#include "tree.h"

size_t tree::size( ) const 
{
   size_t s = 1;
   for( const auto& t : subtrees ) 
      s += t. size();

   return s;
}

std::ostream& tree::printtop( std::ostream& out ) const
{
   if( hasinteger( ))
   {
      out << getinteger( );
      return out; 
   }
   if( hasdouble( ))
   {
      out << getdouble( );
      return out; 
   }
   if( hasstring( ))
   {
      out << getstring( );
      return out; 
   }
   out << "???"; return out; 
}

std::ostream& tree::flatprint( std::ostream& out ) const 
{
   printtop( out );
   if( nrsubtrees())
   {
      out << "( ";
      for( size_t i = 0; i < nrsubtrees(); ++ i)
      {
         if( i > 0 ) out << ", ";
         out << subtrees[i];  
      }
      out << " )"; 
   } 
   return out; 
}

std::ostream& 
tree::print( std::ostream& out, indentation ind ) const 
{
   out << ind; 
   printtop( out ); 
   out << '\n';

   for( const auto& subtree : subtrees )
      subtree.print( out, ind + 3 );

   return out;
}

bool tops_equal( const tree& t1, const tree& t2 ) 
{
   if( t1. hasinteger( ))
      return t2. hasinteger( ) && t1. getinteger( ) == t2. getinteger( );

   if( t1. hasdouble( ))
      return t2. hasdouble( ) && t1. getdouble( ) == t2. getdouble( );

   if( t1. hasstring( ))
      return t2. hasstring( ) && t1. getstring( ) == t2. getstring( ); 

   return false; // undefined is not equal? 
}

bool operator == ( const tree& t1, const tree& t2 ) 
{
   if( t1. nrsubtrees( ) == t2. nrsubtrees( ) &&
       tops_equal( t1, t2 ))
   {
      for( size_t i = 0; i != t1. nrsubtrees( ); ++ i )
      {
         if( !( t1[i] == t2[i] ))
            return false; 
      }
      return true; 
   }
   return false;
}


