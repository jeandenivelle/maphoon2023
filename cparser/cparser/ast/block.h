#ifndef AST_STMT_BLOCK_H
#define AST_STMT_BLOCK_H

#include "base.h"

#include <memory>
#include <string>
#include <vector>

#include "stmt.h"

namespace ast {

struct block : stmt {

  statements insts;

  block(){}
  block( statements i ) : insts{ i } {}

  std::string to_string( std::string pref ) const override {
    auto res = pref + "[block]\n";
    for( auto x : insts ){
      res += x -> to_string( pref + "  " ) + '\n';
    }
    return res;
  }
};

using block_p = std::shared_ptr< block >;

}

#endif

