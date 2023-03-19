#ifndef AST_BINARYEXPR_H
#define AST_BINARYEXPR_H

#include "expr.h"

#include <memory>
#include <string>

namespace ast {

struct binary : expr {
  std::string op;
  expr_p left;
  expr_p right;

  binary() = delete;
  binary( std::string o, expr_p l, expr_p r ) : op{ o }, left{ l }, right{ r } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[" + op + "]\n" + left -> to_string( pref + "  " ) + '\n' + right -> to_string( pref + "  " );
  }
};

}

#endif
