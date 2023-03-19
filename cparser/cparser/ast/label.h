#ifndef AST_LABEL_H
#define AST_LABEL_H

#include "stmt.h"
#include "expr.h"

#include <string>

namespace ast {

struct label : stmt {
  std::string l;
  stmt_p insts;

  label() = delete;
  label( std::string s, stmt_p i ): l{ s }, insts{ i } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[label]\n" + pref + "  " + l + '\n' + insts -> to_string( pref + "  " );
  }
};

}

#endif
