#ifndef AST_UNARYEXPR_H
#define AST_UNARYEXPR_H

#include "expr.h"

#include <memory>
#include <string>

namespace ast {

struct unary : expr {
  std::string op;
  expr_p val;

  unary() = delete;
  unary( std::string o, expr_p v ) : op{ o }, val{ v } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[" + op + "]\n" + val -> to_string( pref + "  " );
  }
};

struct szof : expr {
  std::string op;
  type_p val;

  szof() = delete;
  szof( std::string o, type_p v ) : op{ o }, val{ v } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[" + op + "]\n" + val -> to_string( pref );
  }
};

}

#endif
