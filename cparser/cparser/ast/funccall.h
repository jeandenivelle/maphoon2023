#ifndef AST_FUNCCALL_H
#define AST_FUNCCALL_H

#include "expr.h"

#include <string>

namespace ast {

struct funccall : expr {

  expr_p id;
  expressions args;

  funccall() = delete;
  funccall( expr_p i ): id{ i } {}
  funccall( expr_p i, expressions a ): id{ i }, args{ a } {}

  std::string to_string( std::string pref ) const override {
    auto res = pref + "[funccall]\n" + id -> to_string( pref + "  " ) + '\n';
    for( auto x : args ){ res += x -> to_string( pref + "  " ) + '\n'; }
    return res;
  }

};

}

#endif
