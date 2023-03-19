#ifndef AST_CAST_H
#define AST_CAST_H

#include "stmt.h"

namespace ast {

struct cast : expr {

  type_p tp;
  expr_p exp;

  cast() = delete;
  cast( type_p t, expr_p e ): tp{ t }, exp{ e } {}

  std::string to_string( std::string pref ) const override {
    return "(" + tp -> to_string( pref ) + ")\n" + exp -> to_string( pref + "  " );
  }

};

}

#endif
