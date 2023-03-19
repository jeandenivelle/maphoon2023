#ifndef AST_CYCLES_H
#define AST_CYCLES_H

#include "stmt.h"

#include <memory>
#include <vector>
#include <string>

#include "expr.h"
#include "block.h"

namespace ast {

struct forloop : stmt {

  stmt_p init;
  expr_p cond;
  expr_p step;

  block_p insts;
  
  forloop() = delete;
  forloop( stmt_p i, expr_p c, expr_p s, block_p _i ):
    init{ i },
    cond{ c },
    step{ s },
    insts{ _i }
  {}

  std::string to_string( std::string pref ) const override {
    return 
      pref + "[for]\n" +
      pref + "  [init]\n" + 
                   init -> to_string( pref + "    " ) + '\n' +
      pref + "  [cond]\n" + 
                   cond -> to_string( pref + "    " ) + '\n' +
      pref + "  [step]\n" + 
                   step -> to_string( pref + "    " ) + '\n' +
                 insts -> to_string( pref + "  " );
  }
};

struct whileloop : stmt {

  expr_p cond;

  block_p insts;
  
  whileloop() = delete;
  whileloop( expr_p c, block_p i ) : cond{ c }, insts{ i } {}

  std::string to_string( std::string pref ) const override {
    return 
      pref + "[for]\n" +
      pref + "  [cond]\n" + 
                   cond -> to_string( pref + "    " ) + '\n' +
                 insts -> to_string( pref + "  " );
  }
};

struct do_while : stmt {

  expr_p cond;

  block_p insts;
  
  do_while() = delete;
  do_while( expr_p c, block_p i ) : cond{ c }, insts{ i } {}

  std::string to_string( std::string pref ) const override {
    return 
      pref + "[for]\n" +
                 insts -> to_string( pref + "  " ) + '\n' +
      pref + "  [cond]\n" + 
                   cond -> to_string( pref + "    " );
  }
};

}

#endif
