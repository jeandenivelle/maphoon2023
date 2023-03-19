
#ifndef INSTANCE_
#define INSTANCE_

#include "triple.h" 
#include <unordered_set>

// An instance of the matching problem:

template< typename X, typename Y, typename Z,
          typename XH = std::hash<X>, 
          typename YH = std::hash<Y>, 
          typename ZH = std::hash<Z>,
          typename XE = std::equal_to<X>, 
          typename YE = std::equal_to<Y>,
          typename ZE = std::equal_to<Z>>
requires ishash<X,XH,XE> && ishash<Y,YH,YE> && ishash<Z,ZH,ZE> 
struct instance 
{

   using tripletype = triple<X,Y,Z,XH,YH,ZH,XE,YE,ZE> ;
   using settype = std::unordered_set< tripletype, typename tripletype::hash, typename tripletype :: equal_to > ;
   using setX = std::unordered_set<X,XH,XE> ;
   using setY = std::unordered_set<Y,YH,YE> ;
   using setZ = std::unordered_set<Z,ZH,ZE> ;

   typename triple<X,Y,Z,XH,YH,ZH,XE,YE,ZE> :: hash h;
   typename triple<X,Y,Z,XH,YH,ZH,XE,YE,ZE> :: equal_to eq;

   settype set; 
   setX allX;
   setY allY;
   setZ allZ; 
  
   instance( ) = default; 

   void insert( const tripletype& tr )
   {
      set. insert( tr );
   }

   using const_iterator = typename settype::const_iterator;

   const_iterator begin( ) const { return set. begin( ); }
   const_iterator end( ) const { return set. end( ); }

};


template< typename X, typename Y, typename Z,
          typename XH, typename YH, typename ZH,
          typename XE, typename YE, typename ZE > 
inline std::ostream& operator << ( std::ostream& out, const instance< X,Y,Z, XH,YH,ZH, XE,YE,ZE > & inst )
{
   out << "{"; 
   for( auto p = inst. begin( ); p != inst. end( ); ++ p ) 
   {
      if( p != inst. begin( ))
         out << ", ";
      out << *p;
   }
   out << " }"; 
   return out; 
}


template< typename X, typename Y, typename Z,
          typename XH, typename YH, typename ZH,
          typename XE, typename YE, typename ZE >
void solve( const instance<X,Y,Z,XH,YH,ZH,XE,YE,ZE> & inst,
            std::unordered_set<X,XH,ZE> & xset,
            std::unordered_set<Y,YH,YE> & yset, 
            std::unordered_set<Z,ZH,ZE> & zset )
{
}

#endif

