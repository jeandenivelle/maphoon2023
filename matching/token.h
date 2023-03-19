
#ifndef TOKEN_
#define TOKEN_

#include <iostream>

enum token
{
   tok_value, tok_semicolon, 
   tok_comment, tok_whitespace, tok_newline, 
   tok_begin, tok_end
};

const char* getcstring( token t );

#endif

