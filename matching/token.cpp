
#include "token.h"

const char* getcstring( token t )
{
   switch( t )
   {
   case tok_value:
      return "value"; 
   case tok_semicolon:
      return "semicolon";
   case tok_comment:
      return "comment";
   case tok_whitespace:
      return "whitespace";
   case tok_newline:
      return "newline";
   case tok_begin:
      return "begin";
   case tok_end:
      return "end";
   default:
      return "???";
   }
}


