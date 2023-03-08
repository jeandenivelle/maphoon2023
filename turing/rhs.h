
#ifndef RHS_
#define RHS_

#include <iostream>
#include "state.h"

// The rhs of a transition has form Q X Gamma* X Z. 
// Z = 1 means 'R'
// Z = 0 means 'S'
// Z = -1 means 'L'. 
// Other numbers are possible as well.

struct rhs
{
   state q;
   std::string repl;  
      // The required character req is replaced by the string repl.

   int movedist;    
      // Distance over which tape head will be moved. 
      // +1 means one position to the right.
      // 0 means stay on the place
      // -1 means one position to the left.

   rhs( ) = delete;

   rhs( const state& q,
        const std::string& repl,
        int movedist )
       : q(q),
         repl( repl ),
         movedist( movedist )
   { }

};

std::ostream& operator << ( std::ostream&, const rhs& );

#endif


