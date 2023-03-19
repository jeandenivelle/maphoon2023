#ifndef AST_BREAK_H
#define AST_BREAK_H

#include "stmt.h"

#include <string>

namespace ast {

struct brk : stmt {

  std::string to_string( std::string pref ) const override {
    return pref + "[break]\n";
  }

};

}

#endif
