#ifndef AST_NONE_H
#define AST_NONE_H

#include "expr.h"

#include <string>

namespace ast {

struct none : expr {

  std::string to_string( std::string pref ) const override {
    auto x = pref; // to silence the unused arg warning
    return "";
  }

};

}

#endif
