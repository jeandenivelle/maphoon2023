
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



// Code written by Hans de Nivelle, May 2021.

#include "partition.h"
#include <algorithm>

void lexing::partition::refine( const stateset& filter, 
                                std::stack< size_t > & unchecked )
{
   for( state s : filter )
   {
      stateset& overlap = eqclass[ index[ s. nr ]]; 
         // The equivalence class of s. 
         // s is a shared element between filter and overlap. 

      if( !subset( overlap, filter ))
      {
         // std::cout << "filter " << filter << " refines " << overlap << "\n";

         stateset removed; 

         for( state s : filter )
         {
            if( overlap. erase(s)) 
               removed. insert(s); 
         }
 
         if( overlap. size( ) < removed. size( ))
            std::swap( removed, overlap ); 

         // std::cout << "the result is " << overlap << " + " << removed << "\n";

         for( state s : removed )
         {
            index[ s. nr ] = eqclass. size( );
         } 
         unchecked. push( eqclass. size( )); 

         eqclass. push_back( std::move( removed ));
           // At this point, overlap is spoilt, but it does not matter. 

      }
   }   

}


namespace
{
   lexing::state minimum( const lexing::stateset& s )
   {
      return *s. begin( );
   }
}


void lexing::partition::sortbyminimum( )
{
   std::sort( eqclass. begin( ), eqclass. end( ),
              []( const stateset& s1, const stateset& s2 )
                  { return minimum(s1) < minimum(s2); } ); 

   // And we need to correct the indices:

   setindex( );
}


void lexing::partition::setindex( )
{
   for( size_t c = 0; c != eqclass. size( ); ++ c )
   {
      for( state s : eqclass[c] )
      {
         // If s not yet in index, we create undefined values 
         // until we have place for it.

         while( s. nr >= index. size( ))
            index. push_back( eqclass. size( ));
         index[ s. nr ] = c; 
      }      
   }
}


bool lexing::partition::wellformed( ) const
{
   unsigned int err = 0; 

   for( size_t i = 0; i != index. size( ); ++ i )
   {
      size_t c = index[i];
      if( c >= eqclass. size( ))
      {
         std::cout << "index[" << i << "] >= eqclass. size( )\n";
         ++ err;
      }
      else
      { 
         if( !eqclass[c]. contains(i) )
         {
            std::cout << i << " not in eqclass[ " << c << " ]\n";
            ++ err;
         }
      }
   }

   for( size_t cl = 0; cl != eqclass. size( ); ++ cl )
   {
      for( state s : eqclass[ cl ] )
      {
         if( s. nr > index. size( ))
         {
            std::cout << s << " bigger than index\n";
            ++ err;
         }
        
         if( index[ s. nr ] != cl )
         {
            std::cout << s << " not in index[" << s. nr << "]\n";
            ++ err;
         }
      }
   }

   return err == 0; 
}

void lexing::partition::print( std::ostream& out ) const
{
   out << "Equivalence Classes:\n";
   for( size_t i = 0; i != eqclass. size( ); ++ i )
      out << i << "   : " << eqclass[i] << "\n";
   out << "\n";

   if constexpr( true )
   {
      out << "Index:\n";
      for( size_t i = 0; i != index. size( ); ++ i )
      {
         out << "   " << i << " -> " << index[i] << "\n";
      }
      out << "\n";
   }
}



