
#include <iostream>
#include <string>
#include <fstream>

#include "../filereader.h"

#include "list/list.h"

#include "parsing/tokenizer.h"
#include "parsing/parser.h"

int main( int argc, char* argv[] )
{
#if 0
   list::list l = new list::nil( );

  l = new list::cons( new list::string( "xx\n\txx\x1F" ), l );
  l = new list::cons( new list::integer( std::string( "44444444444444444444444"  )), l );
  l = new list::cons( new list::atom( "xxx" ), l ); 
  
  list::list n = list::build( { 
      new list::atom( "a" ), l, new list::quote( ), new list::integer( "12345678" ) } );

  std::cout << ( list::build( { n, l, new list::integer(2) } ) -> 
                 equal_to( list::build( { n, l, new list::integer(2) } ))) << "\n";

  n -> prettyprint( std::cout );

  return 0;
#endif

   parsing::tokenizer tok( filereader( &std::cin, "std::cin" ));
   // tok. test( );
 
   parsing::parser pr( tok );
   pr. debug = 2;

   auto res = pr. parse( parsing::sym_Session );
   std::cout << res << '\n';

  // auto ptr = res.get< ast::listbp >();
  // std::cout << "HELLO WORLD: " << ptr << '\n';

  // ast::storage vars;
  // ast::storage funcs;
  // auto evalres = eval::eval( ptr, vars, funcs );

  // std::cout << evalres << '\n';

  return 0;
}
