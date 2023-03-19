#ifndef AST_VARIADIC_H
#define AST_VARIADIC_H

#include "expr.h"

namespace ast {

struct variadic : expr {

  variadic(){}
  
  std::string to_string( std::string pref ) const override {
    return pref + "...";
  }

};

}

#endif 
