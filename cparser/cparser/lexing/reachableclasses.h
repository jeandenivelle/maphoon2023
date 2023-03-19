
//  Copyright <2021> <Hans de Nivelle>
//
//  This software is released with the 3-clause BSD license, which 
//  is given below: 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions are met:

//  Redistributions of source code must retain the above copyright notice, 
//  this list of conditions and the following disclaimer:

//  Redistributions in binary form must reproduce the above copyright notice, 
//  this list of conditions and the following disclaimer in the documentation 
//  and/or other materials provided with the distribution.
//  Neither the name of the copyright holder nor the names of its contributors 
//  may be used to endorse or promote products derived from this software 
//  without specific prior written permission.

//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS 
//  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED 
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.



// Written by Hans de Nivelle, May 2021.

#ifndef MAPH_LEXING_REACHABLECLASSES_
#define MAPH_LEXING_REACHABLECLASSES_  1

namespace lexing
{

   template< typename T > 
   struct reachableclasses
   {
      // Pairs of distance and T,
      // sorted by T.

      static constexpr size_t maxsize = 2;

      std::vector< std::pair< size_t, T >> reach;

      reachableclasses( ) = default;

      reachableclasses( T t )  
      {
         reach. push_back( std::make_pair( 0, t ));
      }

      void add1( )
      {
         for( auto& p : reach )
            ++ p. first;
      }

      void print( std::ostream& out ) const
      {
         out << "( ";
         for( auto p = reach. begin( ); p != reach. end( ); ++ p )
         {
            if( p != reach. begin( ))
               out << ", ";
            out << ( p -> first ) << "/" << ( p -> second );
         }
         out << " )";
      }

      size_t size( ) const { return reach. size( ); }

      using iterator = 
         typename std::vector< std::pair< size_t, T >> :: iterator;

      using const_iterator = 
          typename std::vector< std::pair< size_t, T >> :: const_iterator; 

      iterator begin( ) { return reach. begin( ); }
      iterator end( ) { return reach. end( ); }

      const_iterator begin( ) const { return reach. cbegin( ); }
      const_iterator end( ) const { return reach. cend( ); }

      void push_back( const std::pair< size_t, T > & p )
         { reach. push_back(p); } 
   };

 
   template< typename T >
   reachableclasses<T>
   merge( const reachableclasses<T> & r1, const reachableclasses<T> & r2 )
   {
      reachableclasses<T> res;

      auto p1 = r1. begin( );
      auto p2 = r2. begin( );

      while( p1 != r1. end( ) && p2 != r2. end( ) && 
             res. size( ) <= reachableclasses<T> :: maxsize )
      {
         if( p1 -> second == p2 -> second )
         {
            size_t d1 = p1 -> first;
            size_t d2 = p2 -> first;
            
            res. push_back( 
                   std::make_pair( d1 < d2 ? d1 : d2, p1 -> second ));

            ++ p1; ++ p2;
         }
         else
         {
            if( p1 -> second < p2 -> second )
               res. push_back( *p1 ++ );
            else
               res. push_back( *p2 ++ );
         }
      }

      while( p1 != r1. end( ) && 
             res. size( ) <= reachableclasses<T> :: maxsize )
      {
         res. push_back( *p1 ++ );
      }

      while( p2 != r2. end( ) && 
             res. size( ) <= reachableclasses<T> :: maxsize ) 
      {
         res. push_back( *p2 ++ );
      }

      return res;  
   }

   template< typename T > 
   bool 
   operator == ( const reachableclasses<T> & r1, const reachableclasses<T> & r2 )
   {
      if( r1. size( ) == r2. size( ))
      {
         auto p1 = r1. begin( );
         auto p2 = r2. begin( );

         while( p1 != r1. end( ))
         {
            if( p1 -> first != p2 -> first || p1 -> second != p2 -> second )
               return false;

            ++ p1; ++ p2;
         }
         return true;
      }
      else
         return false; 
   }

   template< typename T >
   bool 
   operator != ( const reachableclasses<T> & r1, const reachableclasses<T> & r2 )
      { return ! ( r1 == r2 ); }  


   template< typename T >
   bool
   operator < ( const reachableclasses<T> & r1, const reachableclasses<T> & r2 )
   {
      if( r1. size( ) != r2. size( )) 
         return r1. size( ) < r2. size( ); 

      auto p1 = r1. begin( );
      auto p2 = r2. begin( );

      while( p1 != r1. end( ))
      {
         if( p1 -> first != p2 -> first )
            return ( p1 -> first ) < ( p2 -> first );

         if( p1 -> second != p2 -> second )
            return ( p1 -> second ) < ( p2 -> second );

         ++ p1; ++ p2;
      }
      return false;
   }

   template< typename T > 
   inline std::ostream& 
   operator << ( std::ostream& out, const lexing::reachableclasses<T> & rc )
   {
      rc. print( out );
      return out;
   }

}

#endif


