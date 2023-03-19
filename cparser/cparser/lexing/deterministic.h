
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



// Code written by Hans de Nivelle and Dina Muktubayeva
// May 2021.

// deterministic implements a deterministic classifier by means
// of tables.

#ifndef MAPH_LEXING_DETERMINISTIC_
#define MAPH_LEXING_DETERMINISTIC_  1

namespace lexing
{

   template< typename C, typename T >
   struct deterministic
   {
      constexpr static unsigned int blocked = 
           std::numeric_limits< unsigned > :: max( );

      struct state_info
      {
         unsigned int start;
         T token;

         state_info( unsigned int s, const T& t ) : 
            start(s), token(t) {}
      };


      struct trans
      {
         C c;
         unsigned int next;  // blocked, or a state.

         trans( C c, unsigned int next ) : 
            c(c), next( next ) { }
      };


      std::vector< state_info > states; 
      std::vector< trans > transitions;

      deterministic( const std::vector<state_info> & states, 
                     const std::vector<trans> & transitions ) 
          : states( states ), 
            transitions( transitions )
      { }

      deterministic( std::vector<state_info> && states, 
                     std::vector<trans> && transitions ) 
          : states( std::move( states )),  
            transitions( std::move( transitions )) 
      { }

      state transition( state st, C c ) const 
      {
         // Lower bound and strict upper bound:

         typename std::vector< trans > :: const_iterator low = 
            transitions. begin( ) + states[ st.nr ]. start;

         typename std::vector< trans > :: const_iterator upp = 
            ( st.nr + 1 == states. size( )) ?
                        transitions. end( ) :
                        transitions. begin( ) + states[ st.nr + 1 ]. start;

         // We use binary search until the interval is small enough: 

         while( low + 3 < upp ) 
         {
            auto mid = low + ( ( upp - low ) >> 1 );

            if( c < mid -> c ) 
               upp = mid;
            else
               low = mid;             
         }
 
         while( upp > low )
         {
            -- upp;

            if( upp -> c <= c ) 
               return state( upp -> next ); 
         }
         throw std::runtime_error( "deterministic: should be unreachable" ); 
      }


      void printstate( state st, std::ostream& out ) const
      {
         unsigned int start = states[ st.nr ]. start; 
         unsigned int end = ( st.nr + 1 == states. size( )) ? 
                                transitions. size( ) : 
                                states[ st.nr + 1 ]. start; 

         out << st << " :   "; 
         for( size_t i = start; i < end; ++ i ) 
         {
            if( i != start )
               out << ", ";

            out << transitions[i]. c << " / " ;
            if( transitions[i]. next == blocked )
               out << "blocked";
            else
               out << state( transitions[i]. next ); 
         }
         out << "\n";
      }


      void print( std::ostream& out ) const
      {
         out << "Deterministic:\n";
         for( size_t s = 0; s != nrstates( ); ++ s )
         {
            printstate( s, out );
         }
      }

      size_t nrstates( ) const { return states. size( ); } 

      const T& errorclass( ) const { return states[0]. token; } 

   };


   // We did not try to make this readable.

   template< typename C, typename T >
   std::ostream& 
   operator << ( std::ostream& out, const deterministic<C,T> & det )
   {
      det. print( out );
      return out;
   }


   // A member function may be more natural, but we want the
   // same interface as the other readandclassify in algorithms,
   // so that it will be more easy for the user to replace. 

   template< typename C, typename T, typename S >  
   std::pair<T, size_t > 
   readandclassify( const deterministic<C,T> & det, S& inp ) 
   {
      // std::cout << "deterministic read and classify\n";

      state s = 0;

      // The token class of state 0 is always the error class:

      std::pair<T,size_t> latest = std::make_pair( det. errorclass( ), 0 );
         
      if( !inp. has(1))
         return latest; 

      size_t i = 0;

      while( true )
      {
         if( det.states[ s.nr ]. token != det. errorclass( ))
         {
            latest. first = det. states[ s. nr ]. token;
            latest. second = i;
         }

         if( !inp. has( i + 1 ))
            return latest;

         C c = inp. peek(i);

         // std::cout << s << " / " << c << "\n";

         s = det. transition( s, c );
         
         if( s == det.blocked )
            return latest;

         ++ i;
      }
   }
}

#endif


