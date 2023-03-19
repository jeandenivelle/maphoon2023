%startsymbol S_EXPR EOF

%infotype{ location }

%symbol{} EOF ERROR WHITESPACE COMMENT EMPTY
%symbol{} LPAR RPAR QUOT
%symbol{ std::string } ID STR
%symbol{ bigint }      INT
%symbol{ double }      FLOAT

%symbol{ ast::listbp } ATOM LIST
%symbol{ ast::listbp } S_EXPR
%symbol{ ast::listbp } LIST_REST

%symbolcode_h { #include <filereader.h> }
%symbolcode_h { #include "ast/ast.h" }
%symbolcode_h { #include <bigint.h> }
%symbolcode_h { #include <vector> }
%symbolcode_h { #include <memory> }

%parameter { filereader } r
%parameter { tokenizer } tok

%symbolcode_h {
struct location{
  long unsigned int line;
  long unsigned int column;

  location() {}
  location( long unsigned int line,
            long unsigned int column )
            : line( line ),
              column( column )
  { }
};
}

%symbolcode_cpp{

namespace {
  std::ostream& operator<< ( std::ostream& out, const location& loc ){
    out << "at position " << loc. line << "/" << loc. column;
    return out;
  }

  std::ostream& operator<< ( std::ostream& out, const std::vector< ast::listbp > vec ){
    out << "[";
    for( auto x : vec ){ x -> print( out ); }
    out << "]";
    return out;
  }
}

}

%parsercode_h { #include "tokenizer.h" }
%parsercode_h { #include "ast/ast.h" }
%parsercode_h { #include <algorithm> }

%source { tok.read_symbol(); }

%rules
ATOM => ID:id   { return ast::listbp( new ast::symbol( id ) ); }
      | STR:s   { return ast::listbp( new ast::string( s ) ); }
      | FLOAT:f { return ast::listbp( new ast::floating( f ) ); }
      | INT:i   { return ast::listbp( new ast::number( i ) ); }
      ;


S_EXPR => ATOM:atom { return atom; }
        | LIST:lst  { return lst; }
        | QUOT S_EXPR:s { 
          return ast::listbp( new ast::list( ast::listbp( new ast::string( "quote" ) ), s ) ); }
        ;

LIST_REST => { return ast::listbp( new ast::nil() ); }
           | S_EXPR : s_expr LIST_REST:lst 
           {
             return ast::listbp( new ast::list( s_expr, lst ) ) ;
           }
           ;

LIST => LPAR S_EXPR:s_expr LIST_REST: lst RPAR
      {
        return ast::listbp( new ast::list( s_expr, lst ) );
      }
      ;
