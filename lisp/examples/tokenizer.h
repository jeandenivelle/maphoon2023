#pragma once

#include <filereader.h>
#include "symbol.h"
#include "lexing/classifier.h"

class tokenizer {
  filereader &fr;
  std::string filename;
  symbol cur_symbol;
  location loc;
  lexing::classifier< char, symboltype > cls;

  public:

  tokenizer() = delete;
  tokenizer( filereader &fr, std::string filename ) 
    : fr{ fr }, 
      filename{ filename }, 
      cur_symbol{ symbol( sym_EMPTY, {} ) },
      cls{ buildclassifier() }
  {}

  symbol read_symbol();
  symbol get_new_symbol();
  void commit_symbol();

  std::pair< symboltype, unsigned long> skip_whitespace();

  lexing::classifier< char, symboltype > buildclassifier();

};
