
// Written by Dina Muktubayeva and
// Hans de Nivelle, March/April 2021.

#ifndef MAPH_LEXING_MINMAX
#define MAPH_LEXING_MINMAX  1

#include <climits>
#include <iostream>
#include <set>
#include <stack>
#include "flatmap.h"
#include "state.h"

namespace lexing
{
   template< typename C > C minval( ) 
      { return std::numeric_limits<C> :: lowest( ); } 

   template< typename C > C maxval( ) 
      { return std::numeric_limits<C> :: max( ); } 

}

#endif

