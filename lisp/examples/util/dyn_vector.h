
#ifndef UTIL_DYNAMIC_VECTOR
#define UTIL_DYNAMIC_VECTOR 1

#include <algorithm>

   // In C++, std::string is implemented like this, it is called
   // SSO. (small string optimization).

   // The question is: Do we want this for all our data in Easy?
   // Implement it, see if it is faster (at least for bigint).
   // If yes, it has consequences for all data. 
   // I think i should just finish this. I is maybe on hour work.

namespace util
{
   // We would need two verions of std::copy and std::init,
   // with signature std::copy( p1, len, p2 )
   // Or maybe destroy( p1, len ) and init(  .. ).

   struct dyn_vector
   {
      using D = unsigned short int;

      static constexpr size_t maxlocal = 4;

      struct heap
      {
         D* p;
         size_t ss;
         size_t cc;
      };

      struct local
      {
         D p[ maxlocal ];
         short unsigned ss; 
      };

      union
      {
         heap hp;
         local loc;
      };

      bool onheap; 


      // The nearest power of 2 that is >= c:

      static constexpr size_t nearest2pow( size_t c )
      {
         size_t res = 4;
         while( res < c )
            res <<= 1;
         return res; 
      }


      void reserve( size_t c )
      { 
         if( c > capacity( )) 
         {
            size_t newcap = nearest2pow(c); 
            std::cout << "newcap = " << newcap << "\n";

            D* newp = new D[ newcap ];
            if( onheap )
            {
               std::copy( hp.p, hp.p + hp.ss, newp );
               delete[] hp.p;
               hp.p = newp;
               hp.cc = newcap;
            } 
            else
            {
               size_t s = loc.ss;
               std::copy( loc.p, loc.p + s, newp );
               onheap = true;
               hp.p = newp;
               hp.ss = s;
               hp.cc = newcap; 
            }
         }
      }


      dyn_vector( )
         : onheap( false )
      { 
         loc.ss = 0;
      } 

      dyn_vector( std::initializer_list<D> init ) 
         : dyn_vector( )
      {
         reserve( init. size( ));
         for( auto s : init )
            push_back(s);
      }

      dyn_vector( size_t s, D init )
         : dyn_vector( )
      {
         reserve(s);
         if( onheap )
         {
            for( size_t i = 0; i != s; ++ i )
               hp.p[i] = init;
            hp.ss = s;
         } 
         else
         {
            for( size_t i = 0; i != s; ++ i )
               loc.p[i] = init;
            loc.ss = s;
         }
      }
 
         
      size_t size( ) const 
      {
         return onheap ? hp.ss : loc.ss;
      }

      size_t capacity( ) const
      {
         return onheap ? hp.cc : maxlocal;
      }

      using iterator = D* ;
      using const_iterator = const D* ;
 
      iterator begin( ) 
         { return onheap ? hp.p : loc.p; }

      const_iterator begin( ) const
         { return onheap ? hp.p : loc.p; }

      iterator end( ) 
         { return onheap ? hp.p + hp.ss : loc.p + loc.ss; }

      const_iterator end( ) const 
         { return onheap ? hp.p + hp.ss : loc.p + loc.ss; }


      const D& back( ) const 
         { return onheap ? hp.p[ hp.ss - 1 ] : loc.p[ loc.ss - 1 ]; }

      const D& front( ) const
         { return onheap ? hp.p[0] : loc.p[0]; }

      void push_back( D d )
      {
         size_t s = size( );
         reserve(s+1);
         begin()[s] = d;
         if( onheap )
            ++ hp.ss;
         else
            ++ loc.ss;
      }

      void pop_back( )
      {
         if( onheap )
            -- hp.ss;
         else
            -- loc.ss;
      }

      D& operator[]( size_t i )
      {
         return begin()[i];
      }

      const D& operator[] ( size_t i ) const
      {
         return begin()[i];
      }

      dyn_vector( dyn_vector&& vect )
         : onheap( vect. onheap )
      {
         if( onheap )
         {
            hp.p = vect.hp.p; 
            hp.ss = vect.hp.ss;  
            hp.cc = vect.hp.cc;
            
            vect.onheap = false;
            vect.loc.ss = 0; 
         }
         else
         {
            std::move( vect.loc.p, vect.loc.p + vect.loc.ss, loc.p );
            loc.ss = vect.loc.ss;
         }
      } 


      dyn_vector( const dyn_vector& vect )
      {
         auto p1 = vect. begin( ); 
         auto p2 = vect. end( ); 
         size_t s = vect. size( );

         if( s <= maxlocal )
         {
            onheap = false;
            loc.ss = s;
            std::copy( p1, p2, loc.p );
         }
         else
         {
            onheap = false;
            loc.ss = 0;
               // This is necessary, because the allocation may throw.
   
            size_t c = nearest2pow(s);  
            D* p = new D[c];

            onheap = true;
            hp.p = p; 
            hp.ss = s;
            hp.cc = c;
            std::copy( p1, p2, hp.p );
         }
      }

         
      dyn_vector& operator = ( const dyn_vector& vect )
      {
         if( this == &vect ) return *this;

         if( vect. size( ) <= maxlocal )
         {
            if( onheap )
            {
               delete[] hp.p;
               onheap = false;
            }
            std::copy( vect. begin(), vect. end( ), loc.p ); 
            loc.ss = vect. size( );
            return *this; 
         }
         else
         {
            // We will need to destroy if we are local. 

            if( !onheap )
               loc.ss = 0; 
            else
               hp.ss = 0;   

            reserve( vect. size( ));
            std::copy( vect. begin( ), vect. end( ), hp.p );
            hp.ss = vect. size( ); 
            return *this;  
         }
      }
  
 
      dyn_vector& operator = ( dyn_vector&& vect )
      {
         if( vect. onheap ) 
         {
            if( !onheap ) 
            {
               loc. ss = 0; 
               onheap = true;

               hp.p =  vect.hp.p;
               hp.ss = vect.hp.ss;
               hp.cc = vect.hp.cc;

               vect. onheap = false;
               vect. loc. ss = 0;  
            }
            else
            {
               std::swap( hp.p, vect.hp.p );
               std::swap( hp.ss, vect.hp.ss );
               std::swap( hp.cc, vect.hp.cc );
            }
            return *this; 
         }
         else
            return *this = vect;  
      }
          
      ~dyn_vector( )
      {
         if( onheap ) 
            delete[] hp.p;
      }

   };


   inline std::ostream& operator << ( std::ostream& out, const dyn_vector& v )
   {
      if( v. onheap ) 
         out << "heap{";
      else
         out << "stack{";

      for( auto p = v. begin( ); p != v. end( ); ++ p )
      {
         if( p != v. begin( ))
            out << ", "; 
         else 
            out << " ";

         out << *p; 
      }
      out << " }";
      if( v. end( ) - v. begin( ) != v. size( ))
         std::cout << "NOT RIGHT\n";

      return out; 
   }

}

#endif

