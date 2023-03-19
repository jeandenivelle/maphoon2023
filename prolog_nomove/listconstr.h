
#ifndef PROLOG_LISTCONSTR_
#define PROLOG_LISTCONSTR_   1

#include "function.h"

// Define which operators are used for constructing lists. 
// The defaults are dot (.) and nil ([]). 

namespace prolog 
{

   struct listconstr
   {
      const function nil;
      const function cons;

      listconstr( )
         : nil( function( "[]", 0 )),
           cons( function( ".", 2 )) 
      { } 

      listconstr( const function& nil, const function& cons )
         : nil( nil ), cons( cons )
      { 
         if( nil. getarity( ) != 0 ) 
            throw std::logic_error( "arity of nil not 0" );
         if( cons. getarity( ) != 2 ) 
            throw std::logic_error( "arity of cons not 2" );
      }

   };

   inline std::ostream& operator << ( std::ostream& out, listconstr c )
   {
      out << "nil = " << c. nil << ", " << "cons = " << c. cons << "\n";
      return out;
   } 
   
}

#endif

