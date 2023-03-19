
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

#ifndef MAPH_LEXING_PARTITION_
#define MAPH_LEXING_PARTITION_  1

#include <vector> 
#include <stack> 
#include <map>

#include "stateset.h"

// `partition' means 'state partition'.
// The implementation follows the paper very accurately.

namespace lexing
{

   struct partition
   {

      std::vector< stateset > eqclass;
         // The equivalence classes.

      std::vector< size_t > index;
         // Maps states into their eqclass.

      partition( ) = default;

      template< typename K, typename O > 
      partition( std::map<K,stateset,O> && part )
      {
         for( auto& p : part )
            eqclass. push_back( std::move( p. second ));
       
         part. clear( );
            // To remove the last remaining doubt about
            // our destructiveness.
 
         setindex( );
      }
  
      void refine( const stateset& filter, 
                   std::stack< size_t > & unchecked );
         // If s1 in filter, and s2 not in filter, then 
         // s1 and s2 cannot be in the same equivalence class.
         // We check all eqclasses for which this happens 
         // and split them into two classes. 
         // If we split a class, we append the smaller
         // to eqclass, and put its index on unchecked. 

      void sortbyminimum( ); 
         // Sort eqclass by minimum elements in the classes.
         // This is useful for two reasons: 
         // The initial state must be Q0. This means that
         // Q0 of the old automaton must be in class 0 of 
         // the new automaton. Sorting by smallest element 
         // ensures this.  
         // It is easier to read the new automaton when it  
         // is similar to the old. Sorting somewhat preserves
         // the order of states in the original, 
         // nondeterministic classifier, which preserves
         // readability. 

      void print( std::ostream& out ) const; 

      void setindex( );
         // Set the index from the classes.  
         // Note that if there are open places, their index 
         // will be eqclass. size( ), which means undefined. 

      bool wellformed( ) const;
         // Check if the partition is well-formed,
         // and complain if it is not.
   };


   inline 
   std::ostream& operator << ( std::ostream& out, const partition& part )
   {
      part. print( out );
      return out;
   }

}

#endif


