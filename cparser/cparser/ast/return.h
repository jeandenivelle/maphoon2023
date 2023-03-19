#ifndef AST_RETURN_H
#define AST_RETURN_H

#include "stmt.h"
#include "expr.h"

#include <string>

namespace ast {

struct ret : stmt {

  expr_p val;

  ret(): val{ expr_p( new none() ) }{}
  ret( expr_p v ): val{ v } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[return]\n" + val -> to_string( pref + "  " );
  }

};

}

#endif
