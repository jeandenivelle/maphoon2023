
#include "rhs.h"

std::ostream& operator << ( std::ostream& out, const rhs& rt )
{
   out << rt.q << ", " << rt.repl << ", " << rt.movedist;
   return out;
}

