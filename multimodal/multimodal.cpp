#include <iostream>
#include <fstream>
#include "../filereader.h"
#include "tokenizer.h"
#include "parser.h"

#include "form.h"
#include "../calculator/varstore.h"


int main( int argc, char* argv[] )
{
   varstore< form > vs;

   tokenizer tok( filereader( &std::cin, "stdin") );
   std::cout << tok << "\n";

   std::cout << "type a modal formula followed by (;), or # to quit\n\n";

   parser prs( tok, vs );

   prs. debug = 1;
   prs. checkattrtypes = 2;
   auto res = prs. parse( sym_Session );

   std::cout << "did return\n\n";
   std::cout << "parser returned " << res << "\n";
}


