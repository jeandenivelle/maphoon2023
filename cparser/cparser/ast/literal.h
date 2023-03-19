#ifndef AST_LITERAL_H
#define AST_LITERAL_H

#include "expr.h"

#include <variant>
#include <memory>

namespace ast {

using literal_type = std::variant< std::monostate, bool, char, int, float, double, std::string >;

struct literal : expr {
  literal_type val;
  literal() : val{ std::monostate() }{}

  literal( bool        b ): val{ b }{}
  literal( char        c ): val{ c }{}
  literal( int         i ): val{ i }{}
  literal( float       f ): val{ f }{}
  literal( double      d ): val{ d }{}
  literal( std::string s ): val{ s }{}

  std::string to_string( std::string pref ) const override {
    std::string res = "[empty]";
    if( std::holds_alternative< bool >( val ) ){
      res = std::get< bool >( val ) ? "true" : "false";
    }
    if( std::holds_alternative< char >( val ) ){
      res = std::string() + "'" + std::get< char >( val ) + "'";
    }
    if( std::holds_alternative< int >( val ) ){
      res = std::to_string( std::get< int >( val ) );
    }
    if( std::holds_alternative< float >( val ) ){
      res = std::to_string( std::get< float >( val ) );
    }
    if( std::holds_alternative< double >( val ) ){
      res = std::to_string( std::get< double >( val ) );
    }
    if( std::holds_alternative< std::string >( val ) ){
      res = '"' + std::get< std::string >( val ) + '"';
    }
    return pref + res;
  }
};

}

#endif
