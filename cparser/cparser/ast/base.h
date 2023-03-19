#ifndef AST_BASE_H
#define AST_BASE_H

#include <string>
#include <vector>
#include <memory>
#include <variant>
#include <iostream>

namespace ast {

struct base {
  virtual std::string to_string( std::string pref ) const = 0;
};

using base_p = std::shared_ptr< base >;

}

#endif
