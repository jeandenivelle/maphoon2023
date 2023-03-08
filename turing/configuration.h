
#ifndef CONFIGURATION_
#define CONFIGURATION_

#include <vector>
#include <iostream>

#include "rhs.h"

#include "turingmachine.h"
#include "reachable.h"

struct configuration
{
   std::vector<char> leftofhead;
   std::vector<char> rightofhead;
   state q;


   // rightofhead is in reversed order because operations at the end of
   // a vector are more efficient.

   // Configuration { a, b, c, d, e, f } with the tape head on d and
   // state q0 will be represented by

   // leftofhead = {a,b,c};
   // rightofhead = {f,e,d};
   // q = q0;

   configuration( ) = delete;
  
   configuration( const state& q, 
                  const std::string& left, const std::string& right );

   configuration( const state& q, const std::string& initial )
      : configuration( q, std::string( ), initial )
   { } 

   configuration& movehead( int dist, char blank );
      // The move always succeeds, because we insert
      // blanks if needed. Negative number means to the left. 
      // Usual notation L,R can be translated as -1, +1.

   bool applicable( const lhs& left, char blank ) const;
      // True if we are in the right state, and have the right
      // next symbol.

   configuration apply( const rhs& right, char blank ) const;
      // We don't check applicability.

   struct cmp
   {
      char blank;
         // cmp must ignore leading and trailing blank symbols, so we 
         // have to know what is blank.
 
      cmp( ) = delete;

      cmp( char blank )
         : blank( blank )
      { }

      int 
      threeway_ignore_leading_blanks( const std::vector< char > & v1,
                                      const std::vector< char > & w2 ) const;
         // 3-way compare, where leading blanks are ignored.

      bool operator( ) ( const configuration& conf1, 
                         const configuration& conf2 ) const;

   };

};

std::ostream& operator << ( std::ostream& out, const configuration& conf );

#endif

