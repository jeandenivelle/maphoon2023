#ifndef AST_ARRACC_H
#define AST_ARRACC_H

#include "expr.h"

#include <string>

namespace ast {

struct array_access : expr {
  expr_p arr;
  expr_p pos;

  array_access() = delete;
  array_access( expr_p a, expr_p p ): arr{ a }, pos{ p } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[arr_acc]\n" + arr -> to_string( pref + "  " ) + pos -> to_string( pref + "  " );
  }
};

}

#endif
