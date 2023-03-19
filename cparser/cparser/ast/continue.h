#ifndef AST_CONTINUE_H
#define AST_CONTINUE_H

#include "stmt.h"

#include <string>

namespace ast {

struct cont : stmt {

  std::string to_string( std::string pref ) const override {
    return pref + "[continue]\n";
  }

};

}

#endif
