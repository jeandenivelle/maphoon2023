#ifndef AST_STATEMENT_H
#define AST_STATEMENT_H
#include "base.h"

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <cassert>


namespace ast {

struct stmt : base {
  virtual std::string to_string( std::string pref ) const override {
    return pref + "[stmt]\n";
  }
};

using stmt_p = std::shared_ptr< stmt >;
using statements = std::vector< stmt_p >;

struct expr : stmt {
  virtual std::string to_string( std::string pref ) const override {
    return pref + "[expr]\n";
  }
};

using expr_p = std::shared_ptr< expr >;
using expressions = std::vector< expr_p >;

struct expr_list : expr {
  expressions list;

  expr_list(){}
  expr_list( expressions e ) : list{ e } {}

  std::string to_string( std::string pref ) const override {
    std::string res = pref + "[expr_list]\n";
    for( auto x : list ){ res += x -> to_string( pref + "  " ); }
    return res;
  }
};

}

#include "none.h"

namespace ast {

struct base_type;

using type_p = std::shared_ptr< base_type >;

struct base_type {
  type_p subtype;

  void set_subtype( type_p x ){
    if( x. get() == nullptr ){
      std::cerr << "When setting the subtype for " + repr( "" ) + ", the value of the subtype is nullptr\n";
      assert( x. get() != nullptr );
    }
    subtype = x;
  }

  std::string repr( const std::string pref ) const {
    std::string after;
    if( subtype. get() != nullptr ) after = subtype -> repr( pref + "  " );
    return to_string( pref ) + after;
  }

  virtual std::string to_string( const std::string pref ) const = 0;
};

struct empty_type : base_type {

  std::string to_string( const std::string pref ) const override {
    return pref + "<emtpy>";
  }

};

struct declarator : stmt {

  type_p tp;
  std::string name;
  stmt_p val;

  declarator() = delete;
  declarator( expr_p v )                          : tp{ type_p( new empty_type() ) }, name{ "" }, val{ v }                    {}
  declarator( stmt_p v )                          : tp{ type_p( new empty_type() ) }, name{ "" }, val{ v }                    {}
  declarator( std::string n )                     : tp{ type_p( new empty_type() ) }, name{ n } , val{ expr_p( new none() ) } {}
  declarator( type_p t )                          : tp{ t },                          name{ "" }, val{ expr_p( new none() ) } {}
  declarator( type_p t, std::string n )           : tp{ t },                          name{ n } , val{ expr_p( new none() ) } {}
  declarator( type_p t, stmt_p v )                : tp{ t },                          name{ "" }, val{ v }                    {}
  declarator( type_p t, std::string n, expr_p v ) : tp{ t },                          name{ n } , val{ v }                    {}

  std::string to_string( std::string pref ) const override {
    return pref + "[decl] " + "\n" +
      tp -> to_string( pref + "  " ) + "\n" +
      pref + "  " + name + '\n' +
      val -> to_string( pref + "  " );
  }
};

using decl_p = std::shared_ptr< declarator >;


struct type : base_type {

  std::vector< type_p > specifiers;

  type( std::vector< type_p > s ): specifiers{ s } {}
  type( std::initializer_list< type_p > s ) {
    for( auto x : s ) specifiers. push_back( x );
  }

  std::string to_string( const std::string pref ) const override {
    std::string res = pref;
    for( auto x : specifiers ){ res += x -> to_string( pref + "  " ); }
    return res;
  }

};

struct void_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "void"; }
};

struct char_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "char"; }
};

struct short_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "short"; }
};

struct int_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "int"; }
};

struct long_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "long"; }
};

struct float_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "float"; }
};

struct double_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "double"; }
};

struct signed_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "signed"; }
};

struct unsigned_type : base_type {
  std::string to_string( const std::string pref ) const override { return pref + "unsigned"; }
};

struct id_type : base_type {
  std::string name;

  id_type() = delete;
  id_type( std::string n ) : name{ n } {}

  std::string to_string( const std::string pref ) const override { return pref + name; }
};

struct pointer : base_type {
  type_p realtype;

  pointer(): realtype{ ast::type_p( new ast::empty_type() ) } {}
  pointer( type_p t ) : realtype{ t } {}

  std::string to_string( const std::string pref ) const override {
    return pref + realtype -> to_string( "" ) + "*";
  }
};

using sztype = std::variant< std::monostate, std::string, int >;

struct array : base_type {
  type_p reftype;
  sztype sz; // works with none, identifier, numbers only, must fail otherwise

  array() = delete;
  array( type_p t ) : reftype{ t }, sz{ std::monostate() } {}
  array( type_p t, sztype s ) : reftype{ t }, sz{ s } {}

  std::string to_string( const std::string pref ) const override {
    std::string s;
    if( std::holds_alternative< std::monostate >( sz ) ) s = "";
    if( std::holds_alternative< std::string    >( sz ) ) s = std::get< std::string >( sz );
    if( std::holds_alternative< int            >( sz ) ) s = std::to_string( std::get< int >( sz ) );
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return reftype -> to_string( "" ) + "[" + s + "]";
  }
};

struct enum_type : base_type {

  std::string name;
  std::vector< expr_p > fields;

  enum_type() = delete;
  enum_type( std::vector< expr_p > v = {} ): name{ "" }, fields{ v } {}
  enum_type( std::string n = "", std::vector< expr_p > v = {} ): name{ n }, fields{ v } {}

  std::string to_string( const std::string pref ) const override {
    auto res = "enum " + name;
    std::string f_string = "{}";
    if( fields. size() != 0 ){
      f_string += "{\n";
      for( auto x : fields ) f_string += x -> to_string( "  " ) + '\n';
      f_string += "}";
    }
    return res + f_string;
  }

};

struct struct_or_union : base_type {
  std::string name;
  std::vector< decl_p > body;

  struct_or_union( std::string n, std::vector< decl_p > b ): name{ n }, body{ b } {}

  std::string to_string( const std::string pref ) const override {
    auto res = pref + name + '\n';
    for( auto x : body ){
        res += x -> to_string( pref + "  " ) + '\n';
    }
    return res;
  }
};

struct struct_type : struct_or_union {

  struct_type(): struct_or_union( "<empty>", {} ){}
  struct_type( std::string n ): struct_or_union( n, {} ){}

  std::string to_string( const std::string pref ) const override {
    return pref + "[struct]\n" + struct_or_union::to_string( pref + "  " );
  }

};

struct union_type : struct_or_union {

  std::string name;

  union_type(): struct_or_union( "<empty>", {} ) {}
  union_type( std::string n ): struct_or_union( n, {} ) {}

  std::string to_string( const std::string pref ) const override {
    return pref + "[union]\n" + struct_or_union::to_string( pref + "  " );
  }

};

struct storage_specifier : base_type {

  std::string name;
  storage_specifier(): name{ "<empty>" }{}
  storage_specifier( std::string n ): name{ n }{}

};

struct typedef_type : storage_specifier {

  typedef_type() {}
  typedef_type( std::string n ): storage_specifier( n ) {}

  std::string to_string( const std::string pref ) const override {
    return pref + "typedef " + name;
  }

};

struct extern_type : storage_specifier {

  extern_type() {}
  extern_type( std::string n ): storage_specifier( n ) {}

  std::string to_string( const std::string pref ) const override {
    return pref + "extern " + name;
  }

};

struct static_type : storage_specifier {

  static_type() {}
  static_type( std::string n ): storage_specifier( n ) {}

  std::string to_string( const std::string pref ) const override {
    return pref + "static " + name;
  }

};

struct auto_type : storage_specifier {

  auto_type() {}
  auto_type( std::string n ): storage_specifier( n ) {}

  std::string to_string( const std::string pref ) const override {
    return pref + "auto " + name;
  }

};

struct register_type : storage_specifier {

  register_type() {}
  register_type( std::string n ): storage_specifier( n ) {}

  std::string to_string( const std::string pref ) const override {
    return pref + "register " + name;
  }

};

struct const_type : base_type {

  std::string to_string( const std::string pref ) const override {
    return pref + "const";
  }

};

struct volatile_type : base_type {

  std::string to_string( const std::string pref ) const override {
    return pref + "volatile";
  }

};
struct array_type : base_type {

  expr_p sz;

  array_type() : sz{ nullptr } {}
  array_type( expr_p s ): sz{ s } {}

  std::string to_string( const std::string pref ) const override {
    std::string ssz;
    if( sz != nullptr ) ssz = sz -> to_string( "" );
    return pref + "[" + ssz + "]";
  }
};

struct variadic_type : base_type {

  std::string to_string( const std::string pref ) const override {
    return pref + "<variadic>";
  }

};

}

#include "decl.h"

namespace ast {

struct func_type : base_type {

  type_p rettype;
  std::string name;
  std::vector< decl_p > args;

  func_type(): rettype{ ast::type_p( new ast::empty_type() ) }, name{ "<abst>" }, args{ std::vector< ast::decl_p >() } {}
  func_type( type_p r ): rettype{ r }, name{ "<abst>" }, args{ std::vector< decl_p >() } {}
  func_type( type_p r, std::string n, std::vector< decl_p > a ): rettype{ r }, name{ n }, args{ a } {}
  func_type( type_p r, std::vector< decl_p > a ): rettype{ r }, name{ "<abst>" }, args{ a } {}
  func_type( std::vector< decl_p > a ): rettype{ type_p( new empty_type( ) ) }, name{ "<abst>" }, args{ a } {}

  std::string to_string( const std::string pref ) const override {
    auto res = rettype -> to_string( pref ) + name;
    std::string fields = "()";
    if( args. size() ){
      fields = pref + "(\n";
      for( auto x : args ) fields += x -> tp -> to_string( pref + "  " ) + " " + x -> name + '\n';
      fields += pref + ")";
    }
    return res + fields;
  }

};

}

#endif
