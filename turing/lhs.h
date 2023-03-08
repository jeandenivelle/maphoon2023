
#ifndef LHS_
#define LHS_   

#include <iostream>
#include "state.h"

// lhs has form Q times Gamma: 

struct lhs
{
   state q;
   char req;   // Symbol that has to be present. 

   lhs( ) = delete;

   lhs( const state& q, char req )
       : q(q), 
         req( req )
   { }

   lhs( const char* c, char req ) 
      : lhs( state(c), req )  
   { }

};

// So that lhs can be used as key in std::map:

struct lhs_cmp
{
   lhs_cmp( ) = default; 

   bool operator( ) ( const lhs& l1, const lhs& l2 ) const
   {
      if( l1.q == l2.q ) return l1.req < l2.req;
      return l1.q < l2.q; 
   }
};


inline std::ostream&
operator << ( std::ostream& out, const lhs& left )
{
   out << left.q << ", " << left.req;
   return out;
}

#endif

