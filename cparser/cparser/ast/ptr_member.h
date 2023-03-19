#ifndef AST_PTRMEMBERACCESS_H
#define AST_PTRMEMBERACCESS_H

#include "expr.h"

#include <string>

namespace ast {

struct ptr_memacc : expr {

  expr_p ptr;
  expr_p id;

  ptr_memacc() = delete;
  ptr_memacc( expr_p p, expr_p i ): ptr{ p }, id{ i } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[ptr_memacc]\n" + ptr -> to_string( pref + "  " ) + id -> to_string( pref + "  " );
  }

};

}

#endif
