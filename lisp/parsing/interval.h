
#ifndef PARSING_INTERVAL_
#define PARSING_INTERVAL_

#include "location.h"

namespace parsing
{
   struct interval
   {
      location begin;
      location end;

      interval( const location& begin, const location& end )
         : begin( begin ),
           end( end )
      { }

      void merge( const interval& intv )
      {
         end = intv. end;
      }

   };

   inline
   std::ostream& operator << ( std::ostream& out, interval intv ) 
   {
      out << "[ " << intv. begin << " -- " << intv. end << " ]"; 
      return out;
   }

}


#endif


