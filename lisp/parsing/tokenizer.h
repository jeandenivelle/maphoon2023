
#ifndef PARSING_TOKENIZER_
#define PARSING_TOKENIZER_ 

#include "symbol.h"
#include "../../filereader.h"
#include "../../../lexing2022/includes.h"


namespace parsing
{

   class tokenizer
   {
      filereader inp; 

   public:
      tokenizer( ) = delete;

      tokenizer( filereader&& inp ) 
         : inp( std::move( inp ))
      { }
 
      static lexing::classifier< char, symboltype > buildclassifier( );

      location getlocation( ) const
         { return { inp. line, inp. column }; }

      symbol read( );

      void test( ); 
   };
}

#endif

