#ifndef AST_FUNCDEF_H
#define AST_FUNCDEF_H

#include "base.h"

#include <memory>
#include <vector>

#include "stmt.h"
#include "expr.h"

namespace ast {

struct funcdef : stmt {

  //type_p rettype;
  decl_p d;
  statements body;

  funcdef( type_p r, decl_p d, statements b ): d{ d }, body{ b } {
    this -> d -> tp = r;
  }

  funcdef( decl_p d, statements b ): d{ d }, body{ b } {
    this -> d -> tp = type_p( new void_type() );
  }

  std::string to_string( std::string pref ) const override {
    auto res = pref + "[funcdef]\n";
    res += d -> to_string( pref + "  " ) + '\n';
    for( auto x : body ){
      res += x -> to_string( pref + "  " ) + '\n';
    }
    return res;
  }

};

using function_p = std::shared_ptr< funcdef >;
using functions = std::vector< function_p >;

}

#endif
