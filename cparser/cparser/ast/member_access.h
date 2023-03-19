#ifndef AST_MEMBERACCESS_H
#define AST_MEMBERACCESS_H

#include "expr.h"

#include <string>

namespace ast {

struct member_access : expr {

  expr_p str;
  expr_p id;

  member_access() = delete;
  member_access( expr_p s, expr_p i ): str{ s }, id{ i } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[member]\n" + str -> to_string( pref + "  " ) + id -> to_string( pref + "  " );
  }
};

}

#endif
