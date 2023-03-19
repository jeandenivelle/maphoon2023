#ifndef AST_CASEARM_H
#define AST_CASEARM_H

#include "stmt.h"
#include "expr.h"

#include <string>

namespace ast {

struct case_arm : stmt {
  expr_p cond;
  stmt_p insts;

  case_arm() = delete;
  case_arm( expr_p c, stmt_p i ): cond{ c }, insts{ i } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[case]\n"
        + cond -> to_string( pref + "  ") + '\n'
        + insts -> to_string( pref + "  " );
  }
};

}

#endif
