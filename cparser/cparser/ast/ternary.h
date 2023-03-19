#ifndef AST_TERNARY_H
#define AST_TERNARY_H

#include "expr.h"

#include <string>

namespace ast {

struct ternary : expr {

  expr_p cond;
  expr_p tval;
  expr_p fval;
  
  ternary() = delete;
  ternary( expr_p c, expr_p t, expr_p f ): cond{ c }, tval{ t }, fval{ f } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[?]\n" + 
                      cond -> to_string( pref + "  " ) +
                      tval -> to_string( pref + "  " ) +
                      fval -> to_string( pref + "  " );
  }
};

}

#endif
