
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



// Written by Dina Muktubayeva, March/April 2021.

#ifndef MAPH_LEXING_STATE_
#define MAPH_LEXING_STATE_  1

#include <iostream>

// states are represented by unsigned int.
// In an acceptor, states are represented by
// (signed) integers, and relative to the
// present state. Because of that, we have operators
// + which adds an integer to a state
// - which subtracts an integer from a state
// and - which substracts to states and returns 
// a state. 

namespace lexing
{

   struct state
   {
      unsigned int nr;

      state(unsigned int nr)
         : nr(nr)
      { }

      state operator + ( int i ) const
      {
         return nr + i;
      }

      state& operator ++ () 
      {
         nr ++;
         return *this;
      }

      state& operator -- ()
      {
         nr --;
         return *this;
      }

      state operator ++ ( int ) 
      {
         state old = *this;
         nr++ ;
         return old;
      }

      state operator -- ( int ) 
      {
         state old = *this;
         nr --;
         return old;
      }

      state& operator += ( int i )
      {
         nr += i; return *this;
      }

      int operator - ( state s ) const
      {
         return (int)nr - (int)s. nr;
      }

   };

   inline bool operator < ( state s1, state s2 )
   {
      return s1. nr < s2. nr;
   }

   inline bool operator <= ( state s1, state s2 ) 
   {
      return s1. nr <= s2. nr;
   }

   inline bool operator > ( state s1, state s2 )
   {
      return s1. nr > s2. nr; 
   }

   inline bool operator >= ( state s1, state s2 )
   {
      return s1. nr >= s2. nr;
   }

   inline bool operator == ( state s1, state s2 ) 
   {
      return s1. nr == s2. nr;
   }

   inline bool operator != ( state s1, state s2 ) 
   {
      return s1. nr != s2. nr; 
   }


   inline std::ostream& operator<< ( std::ostream& out, const state& s )
   {
      out << "Q";
      if( s. nr < 10 ) out << '0';
      out << s. nr;
      return out;
   }

}

#endif



