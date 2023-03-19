#ifndef AST_DECLARATION_H
#define AST_DECLARATION_H

#include "stmt.h"

#include <string>

namespace ast {

struct declaration : stmt {

  type_p t;
  stmt_p body; //function body

  declaration() = delete;
  declaration( type_p _t, stmt_p b ): t{ _t }, body{ b } {}

  std::string to_string( std::string pref ) const override {
    return t -> to_string( pref ) + "\n" + body -> to_string( pref );
  }

};

using declaration_p = std::shared_ptr< declaration >;

struct decl : stmt {
  declaration_p d;
  
  decl() = delete;
  decl( declaration_p d ) : d{ d } {}

  std::string to_string( std::string pref ) const override {
    return d -> to_string( pref );
  }

};

}

#endif
