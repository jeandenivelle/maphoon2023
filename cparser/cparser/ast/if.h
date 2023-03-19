#ifndef AST_IF_H
#define AST_IF_H

#include "stmt.h"
#include "expr.h"

#include "none.h"

#include <string>

namespace ast {

struct if_else : stmt {

  expr_p cond;
  stmt_p truth;
  stmt_p flaws;
  
  if_else() = delete;
  if_else( expr_p c, stmt_p t ) : cond{ c }, truth{ t }, flaws{ stmt_p( new none() ) } {}
  if_else( expr_p c, stmt_p t, stmt_p f ) : cond{ c }, truth{ t }, flaws{ f } {}

  std::string to_string( std::string pref ) const override {
    return pref + "[if]\n" + 
                      cond  -> to_string( pref + "  " ) + '\n' +
                      truth -> to_string( pref + "  " ) + '\n' +
                      flaws -> to_string( pref + "  " );
  }
};

}

#endif
