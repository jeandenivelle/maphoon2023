
#ifndef PARSING_TOKENIZER_
#define PARSING_TOKENIZER_

#include "symbol.h" 
#include "../../filereader.h"
#include "../../../lexing2023/includes.h"

#include "symbol.h"

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

      symbol read( );
 
      void printstate( std::ostream& out ) const;
         // Prints the file reader. 

      void test( );
         // Keep on reading symbols until EOF or %end is encountered. 
   };

}

#endif


