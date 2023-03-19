#ifndef AST_INITLIST_H
#define AST_INITLIST_H

#include "expr.h"

namespace ast {

struct initializer_list : expr {
  expressions vals;

  initializer_list( expressions e ): vals{ e } {}
  initializer_list( std::initializer_list< expr_p > e ) {
    expressions _vals;
    for( auto x : e ){ _vals. push_back( x ); }
    vals = std::move( _vals );
  }

  std::string to_string( std::string pref ) const override {
    auto res = pref + "[initializer_list]";
    for( auto x : vals ){ res += x -> to_string( pref + "  " ); }
    return res;
  }
};

}

#endif
