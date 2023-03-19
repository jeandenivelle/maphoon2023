
#ifndef UTIL_SIMPLE_MAP_
#define UTIL_SIMPLE_MAP_   1

// This incredibly primitive implementation of map is designed
// for use in the construction of trees, as in (for example): 
// 
// struct tree
// {
//    int node;
//
//    util::simple_map< std::string, tree > sub; 
// };
//
// This would be possible with std::map, but impossible with
// std::unordered_map. I am not sure if the standard guarantees
// that it is possible with std::map. 
// Moreover, some types have no order defined on them. 
// In order to avoid all problems, I define this simple map. 

#include <list>

namespace util
{
   template< typename D, typename R, typename E = std::equal_to<D> >
   class simple_map 
   {
      std::list< std::pair<D,R>> lst;
      E eq; 
         // Because vector may move things. We don't want that. 
      
    
   public: 
      simple_map( ) = default; 
      
      using value_type = std::pair<D,R> ; 
      using iterator = typename std::list<value_type> :: iterator;
      using const_iterator = typename std::list<value_type> :: const_iterator;

      std::pair< iterator, bool > insert( const value_type& val )
      {
         for( auto p = lst. begin( ); p != lst. end( ); ++ p ) 
         { 
            if( eq( p -> first, val. first ))
               return std::pair< iterator, bool > ( p, false );
         }
         auto p = lst. insert( lst. end( ), val );
         return std::pair< iterator, bool > ( p, true ); 
      }

      std::pair< iterator, bool > insert( value_type&& val )
      {
         for( auto p = lst. begin( ); p != lst. end( ); ++ p )
         {
            if( eq( p -> first, val. first ))
               return std::pair< iterator, bool > ( p, false );
         }
         auto p = lst. insert( lst. end( ), std::move( val ));
         return std::pair< iterator, bool > ( p, true );
      }

      iterator erase( iterator pos ) 
         { return lst. erase( pos ); }

      iterator erase( const_iterator pos )
         { return lst. erase( pos ); }

      iterator begin( ) { return lst. begin( ); }
      iterator end( ) { return lst. end( ); }
  
      const_iterator begin( ) const { return lst. begin( ); }
      const_iterator end( ) const { return lst. end( ); }

      const_iterator cbegin( ) const { return lst. cbegin( ); }
      const_iterator cend( ) const { return lst. cend( ); }

      iterator find( const D& d ) 
      {
         for( auto p = lst. begin( ); p != lst. end( ); ++ p )
         {
            if( eq( p -> first, d ))
               return p;
         }
         return end( );
      }

      const_iterator find( const D& d ) const 
      {
         for( auto p = lst. begin( ); p != lst. end( ); ++ p )
         {
            if( eq( p -> first, d ))
               return p;
         }
         return end( );
      }

      R& operator[]( const D& d ) 
      {
         for( auto p = lst. begin( ); p != lst. end( ); ++ p )
         {
            if( eq( p -> first, d ))
               return p -> second;
         }
         auto p = lst. insert( lst. end( ), value_type( d, R( )));
         return p -> second;  
      }
 
      void clear( ) 
         { lst. clear( ); }

      void swap( simple_map& other ) noexcept
      {
         lst. swap( other. lst );
         std::swap( eq, other. eq );
      }

   };
}

#endif

