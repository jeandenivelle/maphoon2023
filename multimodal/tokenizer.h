
#ifndef TOKENIZER_
#define TOKENIZER_   1

#include "../filereader.h"

#include "symbol.h"

struct tokenizer
{
   filereader read;

   tokenizer( ) 
      : read( filereader( ))
   { }

   tokenizer( filereader&& read )
      : read( std::move( read ))
   { }

   symbol get( );

   void print( std::ostream& out ) const; 

   void test( );
      // Keep on reading and printing symbols until we reach EOF
      // or SEMICOLON.
}; 

inline std::ostream& operator << ( std::ostream& out, const tokenizer& tok )
{
   tok. print( out );
   return out;
}

#endif

