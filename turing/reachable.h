
// Written by Hans de Nivelle. This code can be used freely for
// teaching and studying purposes.

#ifndef REACHABLE_
#define REACHABLE_  1

#include <vector>
#include <queue> 
#include <map>
#include <unordered_map>
#include <algorithm>

template< typename C, typename Cmp > 
struct reachable
{
   struct data;

   using maptype = std::map< C, data, Cmp > ;

   struct data
   {
      typename maptype :: const_iterator parent; 
      unsigned int level; 

      // If level == 0, then the parent is a nonsense iterator!

      data( typename maptype :: const_iterator parent,
            unsigned int level )
         : parent( parent ),
           level( level )
      { } 

   };

   maptype all;
   std::queue< typename maptype :: const_iterator > unch;
      // These are iterators of all, which are permanent. 

   reachable( const Cmp& cmp ) 
      : all( cmp )
   { }
 
   size_t nrunchecked( ) const 
      { return unch. size( ); }

   
   typename maptype :: const_iterator pop_unchecked( ) 
      { auto p = unch. front( ); unch. pop( ); return p; }

   std::vector<C> 
   getpathtowards( typename maptype :: const_iterator it ) const; 
      // Gets the path towards it.
       
   size_t totalsize( ) const { return all. size( ); }  
      // Total number of reached Cs. 

   bool addinitial( const C& c );
      // True if the insertion took place. 

   // Add c as child of parent:

   std::pair< typename maptype :: const_iterator, bool >
   addchild( const C& c, typename maptype :: const_iterator parent );

   void print( std::ostream& out ) const
   {
      out << "Unchecked( " << unch. size( ) << " )\n";
      if( unch. size( ))
      {
         out << "   first = " << unch. front( ) -> first << "\n";
         out << "   last =  " << unch. back( ) -> first << "\n";
         out << "\n";
      }
 
      out << "Reachable:\n";
      for( const auto& d : all )
      {
         out << "   " << d. second. level << " :         " << d. first;
         if( d. second. level ) 
            out << "      reached from " << d. second. parent -> first << "\n";
         else
            out << "      (no parent)\n";
      }
   }

   std::vector< std::set< C, Cmp >> getall( ) const; 
      // Returns all, sorted by level. 

};


template< typename C, typename Cmp > 
std::ostream& operator << ( std::ostream& out, const reachable<C,Cmp> & r )
{
   r. print( out );
   return out;
}


template< typename C, typename Cmp > 
std::vector<C> 
reachable<C,Cmp> :: getpathtowards( typename maptype :: const_iterator it ) const
{
   std::vector<C> res;

   while( it -> second. level )
   {
      res. push_back( it -> first );
      it = it -> second. parent;
   }

   res. push_back( it -> first ); 
   std::reverse( res. begin( ), res. end( )); 
   return res; 
}


template< typename C, typename Cmp >
bool reachable<C,Cmp> :: addinitial( const C& c )
{
   auto p = all. insert( std::pair< C, data > ( c, data( all. end( ), 0 ))); 
   if( p. second || p. first -> second. level > 0 ) 
   {
      p. first -> second. level = 0;
      unch. push( p. first ); 
      return true;
   }
   else 
      return false; 
}


template< typename C, typename Cmp >
std::pair< typename reachable< C, Cmp > :: maptype :: const_iterator, bool >
reachable<C,Cmp> :: addchild( const C& c, 
                              typename maptype :: const_iterator parent )
{
   // std::cout << c << " as child of " << ( parent -> first ) << "\n";

   if( parent == all. end( ))
      throw std::runtime_error( "addchiled( ) : no parent" );

   auto p = all. insert( std::pair< C, data > ( c, data( parent, 0 )));

   if( p. second )
   {
      p. first -> second. level = parent -> second. level + 1;
      unch. push( p. first );
      return p;  
   }
   else
   {
      if( p. first -> second. level > parent -> second. level + 1 ) 
         throw std::runtime_error( "i think this cannot happen" ); 
            // Because of breadth-first search.

      return p;
   } 
}

template< typename C, typename Cmp >
std::vector< std::set< C, Cmp >> 
reachable< C, Cmp > :: getall( ) const
{
   std::vector< std::set< C, Cmp >> res; 

   for( const auto& a : all )
   {
      unsigned int lev = a. second. level;       
      while( lev >= res. size( ))
      {
         res. push_back( std::set< C, Cmp > ( all. key_comp() ));
      }

      res[ lev ]. insert( a. first ); 
   }

   return res; 
}

#endif 


