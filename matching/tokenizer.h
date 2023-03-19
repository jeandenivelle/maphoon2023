
#ifndef TOKENIZER_
#define TOKENIZER_

#include "filereader.h"
#include "symbol.h"

struct tokenizer
{
   filereader inp;

   tokenizer( ) = default;

   tokenizer( filereader&& inp )
      : inp( std::move( inp ))
   { }


   symbol get( );

   void test( );

};

#endif

