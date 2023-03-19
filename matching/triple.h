
#include "ishash.h"
#include <iostream> 

template< typename X, typename Y, typename Z,
          typename XH = std::hash<X>, 
          typename YH = std::hash<Y>, 
          typename ZH = std::hash<Z>,
          typename XE = std::equal_to<X>, 
          typename YE = std::equal_to<Y>,
          typename ZE = std::equal_to<Z>>
requires ishash<X,XH,XE> && ishash<Y,YH,YE> && ishash<Z,ZH,ZE> 
struct triple
{
   X x;
   Y y;
   Z z;

   triple( ) = delete;

   triple( const X& x, const Y& y, const Z& z )
      : x(x), y(y), z(z)
   { }

   triple( X&& x, Y&& y, Z&& z )
      : x( std::move(x)), y( std::move(y)), z( std::move(z))
   { }
 
   void print( std::ostream& out ) const
   {
      out << "( " << x << ", " << y << ", " << z << " )";
   }

   struct hash
   {
      XH xh;
      YH yh;
      ZH zh;

      size_t operator( ) ( const triple& tr ) const
      {
          return 7 * xh( tr.x ) + 5 * yh( tr.y ) + zh( tr.z );
      }
   };

   struct equal_to 
   {
      XE xe;
      YE ye;
      ZE ze;

      equal_to( ) = default;
 
      bool operator( ) ( const triple& tr1, const triple& tr2 ) const
      {
         return xe( tr1.x, tr2.x ) && ye( tr1.y, tr2.y ) && ze( tr1.z, tr2.z );
      }
   };

};


template< typename X, typename Y, typename Z,
          typename XH, typename YH, typename ZH,
          typename XE, typename YE, typename ZE > 
inline std::ostream& operator << ( std::ostream& out, const triple< X,Y,Z, XH,YH,ZH, XE,YE,ZE > & tr )
{
   tr. print( out );
   return out;
}

