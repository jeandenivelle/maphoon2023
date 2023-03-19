#ifndef LEXER_H
#define LEXER_H

#include "filereader.h"
#include "symbol.h"

#include "lexing/algorithms.h" 
#include "lexing/minimization.h"

using tok_type = lexing::classifier< char, symboltype >;

struct Lexer {

  using tokres = std::pair< symboltype, size_t >;

  filereader fr;

  tok_type tok;

  Lexer() = delete;
  Lexer( filereader f ): fr{ std::move( f ) }, tok{ tok_type{ sym_ERROR } } {
    tok = buildclassifier();
  }

  tokres   skipwhitespace( tok_type t );

  symbol   parse_number( tokres t );
  symbol   parse_string( tokres t );
  symbol   parse_char( tokres t );
  symbol   parse_identifier( tokres t );

  tok_type buildclassifier();
  void     add_comments( tok_type &t );
  void     add_identifr( tok_type &t );
  void     add_numbers ( tok_type &t );
  void     add_chars   ( tok_type &t );
  void     add_strings ( tok_type &t );
  void     add_keywords( tok_type &t );
  void     add_specials( tok_type &t );
  symbol   readtoken();
};

#endif
