#ifndef AST_SWITCH_H
#define AST_SWITCH_H

#include "stmt.h"
#include "expr.h"

#include "none.h"

#include <string>

namespace ast {

struct swtch : stmt {

  expr_p cond;
  stmt_p insts;

  swtch() = delete;
  swtch( expr_p c, stmt_p i ) : cond{ c }, insts{ i } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[switch]\n" +
                      cond  -> to_string( pref + "  " ) + '\n' +
                      insts -> to_string( pref + "  " );
  }
};

}

#endif
