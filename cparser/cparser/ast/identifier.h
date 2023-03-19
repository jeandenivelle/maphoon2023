#ifndef AST_IDENTFIER_H
#define AST_IDENTFIER_H

#include "expr.h"

#include <string>

namespace ast {

struct identifier : expr {
  std::string name;
  
  identifier() = delete;
  identifier( std::string s ) : name{ s } {}

  virtual std::string to_string( std::string pref ) const override {
    return pref + name;
  }
};

}

#endif
