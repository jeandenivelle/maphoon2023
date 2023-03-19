
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



#include <iostream>
#include <vector>

#ifndef MAPH_LEXING_FLATMAP_
#define MAPH_LEXING_FLATMAP_  1

// C must have an order < defined. There are no requirements on
// S.
// Do you know a better name?

namespace lexing
{

   template <typename C, typename S >
   struct flatmap
   {
      std::vector<std::pair<const C, S>> repr;
	// Must be sorted by increasing C.

      flatmap( ) = default;
      flatmap( const flatmap& ) = default;
      flatmap( flatmap&& ) = default;
      flatmap& operator = ( const flatmap& ) = default;
      flatmap& operator = ( flatmap&& ) = default;
      ~flatmap( ) = default;


      flatmap( std::initializer_list<std::pair<const C, S>> init)
      {
         repr. reserve( init. size( ));
         for( auto p : init )
            append( p.first, p.second );
      }

      // c must be bigger than everything encountered so far.

      void append( const C& c, const S& s )
      {
         if( !repr. empty( ))
         {
            if( !( repr. back( ). first < c ))
               throw std::runtime_error( "flatmap append: not increasing" );
                  // check if the transition is already there

            if( repr. back( ). second == s )
               return; 
                  // The addition is redundant, so we don't add. 
         }

         repr. push_back( std::make_pair(c,s) );
      }

      using iterator =
         typename std::vector<std::pair<const C, S>>::iterator;
      using const_iterator =
         typename std::vector<std::pair<const C, S>>::const_iterator;

      iterator begin() { return repr.begin(); }
      iterator end() { return repr.end(); }

      const_iterator cbegin() const { return repr.begin(); }
      const_iterator cend() const { return repr.end(); }
      const_iterator begin() const { return repr.begin(); }
      const_iterator end() const { return repr.end(); }

      // Uses binary search : 

      const_iterator find( const C& c ) const 
      {
         const_iterator low = begin( );
         const_iterator upp = end( );

         while( low + 3 < upp )
         {
            const_iterator mid = low + (( upp - low ) >> 1 );

            if( mid -> first <= c )
               low = mid;
            else
               upp = mid;
         }

         // When the interval is small enough, we search backwards:

         while( upp > low )
         {
            -- upp;
            if( upp -> first <= c )
               return upp;
         }

         return end( );
      }

      void clear() { repr.clear(); }
      size_t size() const { return repr. size(); }
      bool empty() const { return repr. empty( ); }
   };


   template< typename C, typename R, typename S1, typename S2, typename F >
   flatmap<C,R> 
   transform( const flatmap<C,S1> & m1, const flatmap<C,S2> & m2, const F& f ) 
   {
      auto p1 = m1. begin( );
      auto p2 = m2. begin( );
      if( p1 == m1. end( ) || p2 == m2. end( ))
         throw std::runtime_error( "transform, size cannot be zero" );
      if( p1 -> first != p2 -> first )
         throw std::runtime_error( "transform, maps must start at same C" );

      flatmap<C,R> res;
 
      C c = p1 -> first;

      // c is the point that we are looking at.
      // p1,p2 are positions that determine the value of c.
      // p1,p2 reach the end at the same time.

      while( p1 != m1. end( ) || p2 != m2. end( ))
      {
         // std::cout << "c = " << c << "\n"; 
         // std::cout << "f = " << f( p1 -> second, p2 -> second ) << "\n";

         res. append( c, f( p1 -> second, p2 -> second ));
      
         ++ p1; 
         if( p1 == m1. end( ))
         {
            -- p1;
            ++ p2;
            if( p2 == m2. end( ))
               ++ p1;    // that's the end. 
            else
               c = p2 -> first;
         }
         else
         {
            ++ p2;
            if( p2 == m2. end( ))
            { 
               -- p2;
               c = p1 -> first;
            }
            else
            {
               if( p1 -> first == p2 -> first )
               {
                  c = p1 -> first;
               }
               else
               {
                  if( p1 -> first < p2 -> first )
                  {
                     -- p2;
                     c = p1 -> first;
                  }
                  else
                  {
                     -- p1;
                     c = p2 -> first;
                  }
               }
            }
         }
      }

      return res;
   }

}

#endif


