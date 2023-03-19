#include <iostream>
#include <fstream>
#include <string>

#include "filereader.h"
#include "lexer.h"
#include "parser.h"

int main( int argc, char *argv[] ){
  std::string filename = "example.c";
  if( argc != 1 ){
    filename = argv[ 1 ];
  }
  
  std::ifstream *inputfile = new std::ifstream( filename );
  filereader fr( inputfile, filename );
  Lexer l( std::move( fr ) );
  parser p( l );
  //p. debug = 3;

  auto res = p.parse( sym_program );
  std::cout << res. get< ast::program_p >() -> to_string( "" ) << '\n';
  return 0;
}
