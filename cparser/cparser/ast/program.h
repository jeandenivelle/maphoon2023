#ifndef AST_PROGRAM_H
#define AST_PROGRAM_H

#include "base.h"
#include "funcdef.h"
#include "decl.h"

namespace ast {

struct program : base {

  std::vector< stmt_p > decls;
  functions list;

  program( std::initializer_list< stmt_p > l ){ for( auto x : l ) decls. push_back( x ); }

  void add_decl( stmt_p d ){
    decls. push_back( d );
  }
  
  std::string to_string( std::string pref ) const override {
    auto res = pref + "[program]\n";
    for( auto x : decls ){ res += x -> to_string( pref + "  " ); }
    return res;
  }

};

using program_p = std::shared_ptr< program >;

}

#endif
