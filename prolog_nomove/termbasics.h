
#ifndef TERMBASICS_
#define TERMBASICS_ 1

#include <iostream>
#include "term.h"

namespace prolog
{
   std::ostream& operator << ( std::ostream& out, const term& t ); 
}

#endif


