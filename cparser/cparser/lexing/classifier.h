
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



#ifndef LEXING_CLASSIFIER_INCLUDED_
#define LEXING_CLASSIFIER_INCLUDED_  1

// Written by Hans de Nivelle and Dina Muktubayeva, 
// March/April 2021.

#include "acceptor.h"

namespace lexing
{

   // A classifying automaton is able to classify.
   // We assume that state 0, which recognizes the empty word,
   // defines the error class.

   template< typename C, typename T > 
   struct classifier
   {
      std::vector< deltafromstate<C>> delta;
      std::vector<T> classifications;
         // We always use classifications[0] as the error class. 

      classifier( ) = delete; 
         // Because we need to have the error in classifications[0].

      classifier( T error ) 
      {
         delta. push_back( deltafromstate<C> ( ));
       
         classifications. push_back( error ); 
      }

      const T& errorclass( ) const { return classifications[0]; }
         // classifications[0] is always the error class.

      void insert( acceptor<C> && acc, T tok )
      {
         delta. front( ). eps. insert( nrstates( ));

         for( size_t i = 0; i != acc. nrstates( ); ++ i ) 
         {
            delta. push_back( std::move( acc. delta[i] ));
            classifications. push_back( classifications. front( ));
         } 

         delta. push_back( deltafromstate<C> ( )); 
         classifications. push_back( tok );
      }

      void insert( const acceptor<C> & acc, T tok )
         { insert( acc. copy( ), tok ); }

      size_t nrstates( ) const { return delta. size( ); } 

      void print( std::ostream& out ) const
      {
         out << "Classifier:\n";
         for( size_t s = 0; s != delta. size(); ++ s )
         {
            state base(s);
            delta[s].print( out, base );

            if( classifications[s] != errorclass( ))
               out << "   " << classifications[s];
            out << "\n";
         }
      }

   };


   template< typename C, typename T >
   std::ostream& operator << ( std::ostream& out, 
                               const classifier< C, T > & cl )
   {
      cl. print( out ); 
      return out;
   }

}

#endif


