
#ifndef PROLOG_TOKENIZER_
#define PROLOG_TOKENIZER_    1

#include "../filereader.h"

#include "../../lexing2022/includes.h"

#include "symbol.h"

namespace prolog
{

   struct tokenizer
   {
      filereader read;

      enum context { ct_list, ct_func, ct_par, ct_glued };
         // ct_list : inside [ ... ]
         // ct_func:  inside f( ... )
         // ct_par:   inside ( ... )
         // ct_glued:  after f in f( ... ).

      static const char* getcstring( context c );
  
      std::vector< context > contextstack; 
         // This is used for characters like | . and , 

      
      tokenizer( ) 
         : read( filereader( ))
      { }

      tokenizer( filereader&& read )
         : read( std::move( read ))
      { }

      symbol get( const syntax& synt );

      void print( std::ostream& out ) const; 

      void test( const syntax& synt );
         // Keep on reading and printing symbols until we reach EOF. 
   }; 

   inline 
   std::ostream& operator << ( std::ostream& out, const tokenizer& tok )
   {
      tok. print( out );
      return out;
   }

}

#endif

