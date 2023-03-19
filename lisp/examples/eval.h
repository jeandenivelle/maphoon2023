#ifndef EVAL_HEADER
#define EVAL_HEADER

#include <string>
#include <set>

#include "ast/ast.h"

namespace eval {

bool iskeyword( std::string name ){
  std::set< std::string > keyset = {
    "+", "-", "*", "/", "<", ">", ">=", "<=", "=", "list", "quote", "readline", "print", "println", "defun", "let", "car", "cdr", "cons", "if", "length", "first", "last", "head", "tail"
  };
  if( keyset. find( name ) != keyset. end() ) return true;
  else return false;
}

ast::listbp construct_list( ast::listbp cur ){
  ast::nil* nil_cast = dynamic_cast<ast::nil*>( cur. get() );
  if( nil_cast != nullptr ){
    return ast::listbp( new ast::nil() );
  } else {
    ast::list* list_cast = dynamic_cast<ast::list*>( cur. get() );
    auto val = list_cast -> first;
    return ast::listbp( new ast::list( val, construct_list( list_cast -> rest ) ) );
  }
}

ast::listbp eval( const ast::listbp &_list, ast::storage &vars, ast::storage &func )
{
  if( const ast::number* check_cast = dynamic_cast<const ast::number*>( _list. get() ); check_cast != nullptr ){
    return ast::listbp( new ast::number( check_cast -> val ) );
  }

  if( const ast::string* check_cast = dynamic_cast<const ast::string*>( _list. get() ); check_cast != nullptr ){
    return ast::listbp( new ast::string( check_cast -> str ) );
    //return _list;
  }

  if( const ast::list* check_cast = dynamic_cast<const ast::list*>( _list. get() ); check_cast != nullptr ){
    auto list_cast = check_cast;
    auto op_ptr = list_cast -> first;
    ast::symbol* op = dynamic_cast<ast::symbol*>( op_ptr.get() );

    if( iskeyword( op -> name ) ){
      auto command = op -> name;
      if( command == "first" ){
        const ast::list* res = dynamic_cast<const ast::list*>( list_cast -> rest. get() );
        return res -> first;
      }
      if( command == "rest" ){
        const ast::list* res = dynamic_cast<const ast::list*>( list_cast -> rest. get() );
        return res -> rest;
      }
      if( command == "length" ){
        int len = 0;
        auto cur = list_cast -> rest;
        ast::nil* nil_cast = dynamic_cast<ast::nil*>( cur. get() );

        while( nil_cast == nullptr ){
          len ++;
          ast::list* next_ptr = dynamic_cast<ast::list*>( cur. get() );
          cur = next_ptr -> rest;
        }

        return ast::listbp( new ast::number( len ) );
      }
      if( command == "list" ){
        auto cur = list_cast -> rest;
        return construct_list( cur );
      }
      if( command == "+" ){
        bigint res( 0 );

        auto list_to_check = list_cast -> rest;
        ast::nil* nil_cast = dynamic_cast<ast::nil*>( list_to_check. get() );
        while( nil_cast == nullptr ){
          ast::list* list_ptr = dynamic_cast<ast::list*>( list_to_check. get() );

          auto val = eval( list_ptr -> first, vars, func );
          ast::number* num_ptr = dynamic_cast<ast::number*>( val. get() );
          res += num_ptr -> val;
          list_to_check = list_ptr -> rest;

          nil_cast = dynamic_cast<ast::nil*>( list_to_check. get() );
        }
        return ast::listbp( new ast::number( res ) );
      }

      if( command == "-" ){
        bigint res( 0 );
        bool first = true;

        auto list_to_check = list_cast -> rest;
        ast::nil* nil_cast = dynamic_cast<ast::nil*>( list_to_check. get() );
        while( nil_cast == nullptr ){
          ast::list* list_ptr = dynamic_cast<ast::list*>( list_to_check. get() );

          auto val = eval( list_ptr -> first, vars, func );
          ast::number* num_ptr = dynamic_cast<ast::number*>( val. get() );
          if( first ) { res += num_ptr -> val; first = false; }
          else res -= num_ptr -> val;
          list_to_check = list_ptr -> rest;

          nil_cast = dynamic_cast<ast::nil*>( list_to_check. get() );
        }
        return ast::listbp( new ast::number( res ) );
      }
    }
  }

  return ast::listbp( new ast::nil() );
}

} // namespace eval

#endif
