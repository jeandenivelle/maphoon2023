#ifndef AST_FUNCTYPE_H
#define AST_FUNCTYPE_H

#include "stmt.h"

#include <string>
#include <optional>

namespace ast {

struct func_type : base_type {

  std::optional< type_p > ad;
  std::optional< std::vector< type_p > > param;

  func_type(){}
  func_type( type_p t ): ad{ t } {}
  func_type( std::vector< type_p > p ): param{ p } {}
  func_type( type_p t, std::vector< type_p > p ): ad{ t }, param{ p } {}

  std::string to_string( std::string pref ) const {
    std::string res = pref;
    if( ad ){ res += (*ad) -> to_string(); } res += "(";
    if( param ){ 
      bool ok = false; 
      for( auto x : (*param) ){ 
        if( ok ) res += ", "; 
        res += pref + "  " + x -> to_string(); 
        ok = true; 
      } 
    } 
    res += pref + ")";
    return res;
  }

};

}

#endif
