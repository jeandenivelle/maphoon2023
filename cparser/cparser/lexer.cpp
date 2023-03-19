#include "lexer.h"

#include <functional>
#include <numeric>

#include "symbol.h"

lexing::classifier< char, symboltype > Lexer::buildclassifier(){
  lexing::classifier< char, symboltype > tknzr( sym_ERROR );
  add_comments( tknzr );
  add_strings ( tknzr );
  add_numbers ( tknzr );
  add_chars   ( tknzr );
  add_identifr( tknzr );
  add_keywords( tknzr );
  add_specials( tknzr );
  return tknzr;
}

void Lexer::add_comments( lexing::classifier< char, symboltype > &t ){
  using namespace lexing;

  auto single_line_comment = word( "//" ) * ( every< char >(). without( '\n' ) ). star();
  auto multi_line_comment = word( "/*" ) * ( every< char >(). without( '*' ) | just( '*' ) * every< char >(). without( '/' ) ). star() * word( "*/" );
  auto comments = ( single_line_comment | multi_line_comment );

  auto spacechar = just( ' ' ) | just( '\t' ) | just( '\n' ) | just( '\r' );
  auto space = spacechar. plus();

  t. insert( comments, sym_COMMENTS );
  t. insert( space, sym_SPACE );

  return;
}

void Lexer::add_identifr( lexing::classifier< char, symboltype > &t ){
  using namespace lexing;

  auto letter = range( 'a', 'z' ) | range( 'A', 'Z' ) | just( '_' );
  auto digit = range( '0', '9' );
  auto identfr = letter * ( letter | digit ). star();

  t. insert( identfr, sym_IDENTIFIER );
  return;
}

void Lexer::add_numbers( lexing::classifier< char, symboltype > &t ){
  using namespace lexing;

  auto digit = range( '0', '9' );
  auto number = just( '0' ). plus() | ( range( '1', '9' ) * digit. star() );

  t. insert( number, sym_CONSTANT );
  return;
}

void Lexer::add_chars( lexing::classifier< char, symboltype > &t ){
  using namespace lexing;

  auto simple = every< char >().
                without( '\'' ).
                without( '\n' ).
                without( '\\' ).
                without( '\r' ).
                without( '\t' ).
                without( '\a' ).
                without( '\b' );

  auto special = just( '\\' ) * ( just( '\'' ) | just( 'n' ) | just( 'r' ) | just( 't' ) | just( 'a' ) | just( 'b' ) );

  auto charpat = just( '\'' ) * ( simple | special ) * just( '\'' );
  t. insert( charpat, sym_CHARLIT );
  return;
}

void Lexer::add_strings( lexing::classifier< char, symboltype > &t ){
  using namespace lexing;

  auto simple = every< char >().
                without( '"'  ).
                without( '\\' ).
                without( '\r' ).
                without( '\t' ).
                without( '\a' ).
                without( '\b' );

  auto special = just( '\\' ) * ( just( '"' ) | just( 'n' ) | just( 'r' ) | just( 't' ) | just( 'a' ) | just( 'b' ) );

  auto strpat = just( '"' ) * ( simple | special ). star() * just( '"' );

  t. insert( strpat, sym_STRING_LITERAL );
  return;
}

void Lexer::add_keywords( lexing::classifier< char, symboltype > &t ){
  using namespace lexing;

  t. insert( word( "auto" ),     sym_AUTO     );
  t. insert( word( "break" ),    sym_BREAK    );
  t. insert( word( "case" ),     sym_CASE     );
  t. insert( word( "char" ),     sym_CHAR     );
  t. insert( word( "const" ),    sym_CONST    );
  t. insert( word( "continue" ), sym_CONTINUE );
  t. insert( word( "default" ),  sym_DEFAULT  );
  t. insert( word( "do" ),       sym_DO       );
  t. insert( word( "double" ),   sym_DOUBLE   );
  t. insert( word( "else" ),     sym_ELSE     );
  t. insert( word( "enum" ),     sym_ENUM     );
  t. insert( word( "extern" ),   sym_EXTERN   );
  t. insert( word( "float" ),    sym_FLOAT    );
  t. insert( word( "for" ),      sym_FOR      );
  t. insert( word( "goto" ),     sym_GOTO     );
  t. insert( word( "if" ),       sym_IF       );
  t. insert( word( "int" ),      sym_INT      );
  t. insert( word( "long" ),     sym_LONG     );
  t. insert( word( "register" ), sym_REGISTER );
  t. insert( word( "return" ),   sym_RETURN   );
  t. insert( word( "short" ),    sym_SHORT    );
  t. insert( word( "signed" ),   sym_SIZEOF   );
  t. insert( word( "static" ),   sym_STATIC   );
  t. insert( word( "struct" ),   sym_STRUCT   );
  t. insert( word( "switch" ),   sym_SWITCH   );
  t. insert( word( "typedef" ),  sym_TYPEDEF  );
  t. insert( word( "union" ),    sym_UNION    );
  t. insert( word( "unsigned" ), sym_UNSIGNED );
  t. insert( word( "void" ),     sym_VOID     );
  t. insert( word( "volatile" ), sym_VOLATILE );
  t. insert( word( "while" ),    sym_WHILE    );
  return;
}

void Lexer::add_specials( lexing::classifier< char, symboltype > &t ){
  using namespace lexing;

  t. insert( just( ';' ), sym_SEMICOLON );
  t. insert( just( '{' ), sym_LCUR      );
  t. insert( just( '}' ), sym_RCUR      );
  t. insert( just( ',' ), sym_COMMA     );
  t. insert( just( ':' ), sym_COLON     );
  t. insert( just( '=' ), sym_ASSIGN    );
  t. insert( just( '(' ), sym_LPAR      );
  t. insert( just( ')' ), sym_RPAR      );
  t. insert( just( '[' ), sym_LSQR      );
  t. insert( just( ']' ), sym_RSQR      );
  t. insert( just( '.' ), sym_DOT       );
  t. insert( just( '&' ), sym_AMP       );
  t. insert( just( '!' ), sym_NOT       );
  t. insert( just( '~' ), sym_NEG       );
  t. insert( just( '-' ), sym_SUB       );
  t. insert( just( '+' ), sym_ADD       );
  t. insert( just( '*' ), sym_MUL       );
  t. insert( just( '/' ), sym_DIV       );
  t. insert( just( '%' ), sym_MOD       );
  t. insert( just( '<' ), sym_LT_OP     );
  t. insert( just( '>' ), sym_GT_OP     );
  t. insert( just( '^' ), sym_CARET     );
  t. insert( just( '|' ), sym_PIPE      );
  t. insert( just( '?' ), sym_QUEST     );

  t. insert( word( "..." ), sym_ELLIPSIS     );
  t. insert( word( ">>=" ), sym_RIGHT_ASSIGN );
  t. insert( word( "<<=" ), sym_LEFT_ASSIGN  );
  t. insert( word( "+=" ), sym_ADD_ASSIGN    );
  t. insert( word( "-=" ), sym_SUB_ASSIGN    );
  t. insert( word( "*=" ), sym_MUL_ASSIGN    );
  t. insert( word( "/=" ), sym_DIV_ASSIGN    );
  t. insert( word( "%=" ), sym_MOD_ASSIGN    );
  t. insert( word( "&=" ), sym_AND_ASSIGN    );
  t. insert( word( "^=" ), sym_XOR_ASSIGN    );
  t. insert( word( "|=" ), sym_OR_ASSIGN     );

  t. insert( word( ">>" ), sym_RIGHT_OP );
  t. insert( word( "<<" ), sym_LEFT_OP  );
  t. insert( word( "++" ), sym_INC_OP   );
  t. insert( word( "--" ), sym_DEC_OP   );
  t. insert( word( "->" ), sym_PTR_OP   );
  t. insert( word( "&&" ), sym_AND_OP   );
  t. insert( word( "||" ), sym_OR_OP    );
  t. insert( word( "<=" ), sym_LE_OP    );
  t. insert( word( ">=" ), sym_GE_OP    );
  t. insert( word( "==" ), sym_EQ_OP    );
  t. insert( word( "!=" ), sym_NE_OP    );
  return;
}

using tokres = std::pair< symboltype, size_t >;

tokres Lexer::skipwhitespace( tok_type t ){
  using namespace lexing;

  if( fr. eof() ) { return tokres{ sym_EOF, 0 }; }
  auto res = readandclassify( t, fr );
  //std::cerr << "DEBUG: " << res. first << '\n';

  while( res. first == sym_COMMENTS || res. first == sym_SPACE ) {
    fr. commit( res. second );
    if( fr. eof() ) { return tokres{ sym_EOF, 0 }; }
    res = readandclassify( t, fr );
    //std::cerr << "DEBUG: " << res. first << '\n';
  }

  return res;
}

symbol Lexer::parse_number( tokres t ){
  auto str = fr. view( t. second );
  auto res = std::accumulate( str. begin(), str. end(), 0, []( int x, char c ) -> int { return x * 10 + c - '0'; });
  return symbol( sym_CONSTANT, res );
}

symbol Lexer::parse_string( tokres t ){
  auto str = fr. view( t. second );
  auto res = std::accumulate( str. begin() + 1, str. end() - 1, std::string(""), []( std::string x, char c ) -> std::string {
      return x + c; });
  return symbol( sym_STRING_LITERAL, res );
}

symbol Lexer::parse_char( tokres t ){
  char res = fr. peek( 0 );
  if( t. second != 1 ){
    auto c = fr. peek( 1 );
    if( c == '\\' ) res = '\\';
    if( c == '\'' ) res = '\'';
    if( c == '\n' ) res = '\n';
    if( c == '\t' ) res = '\t';
    if( c == '\r' ) res = '\r';
    if( c == '\a' ) res = '\a';
    if( c == '\b' ) res = '\b';
  }
  return symbol( sym_CHARLIT, res );
}

symbol Lexer::parse_identifier( tokres t ){
  auto str = fr. view( t. second );
  auto res = std::accumulate( str. begin(), str. end(), std::string(""), []( std::string x, char c ) -> std::string {
      return x + c; });
  return symbol( sym_IDENTIFIER, res );
}

symbol Lexer::readtoken(){
  auto res = skipwhitespace( tok );
  symbol sym( res. first );
  if( res. first == sym_CONSTANT ){
    sym = parse_number( res );
  } else
  if( res. first == sym_STRING_LITERAL ){
    sym = parse_string( res );
  } else
  if( res. first == sym_CHARLIT ){
    sym = parse_char( res );
  } else
  if( res. first == sym_IDENTIFIER ){
    sym = parse_identifier( res );
  }
  fr. commit( res. second );
  return sym;
}
