#ifndef AST_GOTO_H
#define AST_GOTO_H

#include "stmt.h"

#include <string>

namespace ast {

struct go_to : stmt {
  std::string label;

  go_to() = delete;
  go_to( std::string s ): label{ s } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[goto " + label + "]\n";
  }
};

}

#endif
