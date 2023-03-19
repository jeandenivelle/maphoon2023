#ifdef AST_ABSTRACTARR_H
#define AST_ABSTRACTARR_H

#include "stmt.h"

#include <optional>

namespace ast {

struct abstract_array : base_type {

  std::optional< type_p > ad;
  std::optional< stmt_p > sz;

  abstract_array(){}
  abstract_array( stmt_p s ): sz{ s } {}
  abstract_array( type_p t ): ad{ t } {}
  abstract_array( type_p t, stmt_p s ): ad{ t }, sz{ s } {}

  std::string to_string( std::stringp pref ) const override {
    std::string res;
    if( ad ){ res += (*ad) -> to_string(    ); } res += "[";
    if( sz ){ res += (*sz) -> to_string( "" ); } res += "]";
    return res;
  }

};

}

#endif
