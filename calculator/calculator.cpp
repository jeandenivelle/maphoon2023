
#include "symbol.h" 
#include "tokenizer.h"
#include "parser.h"

void testtokenizer( tokenizer& tok )
{

   symbol sym = tok. read( );
   while( sym. type != sym_EOF )
   {
      std::cout << sym << "\n";
      sym = tok. read( );
   }
   std::cout << "that's end of file\n";
}


int main( int argc, char* argv [] )
{
   varstore<double> vs;
   vs. assign( "e", 2.71828182845904523536 );
   vs. assign( "pi", 3.14159265358979323846264338327950288 ); 

   std::cout << vs << "\n";

   lexing::filereader read( &std::cin, "stdin" );
   tokenizer tok( std::move( read ));

   std::vector< std::string > errorlog;

   parser prs( vs, errorlog, tok );
 
   prs. debug = 1;  
   prs. maxtrialperiod = 0;
   auto sym = prs. parse( sym_Session );
   std::cout << "parser returned " << sym << "\n";
   return 0;
}


