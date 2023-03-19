
// This code was produced by Maphoon 2021.
// Code for struct symbol:

#include "symbol.h"


#line 38 "grammar.m"


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



const char* getcstring( symboltype tp )
{
   switch( tp )
   {
   case sym__recover_:
      return "_recover_";
   case sym_S_EXPR:
      return "S_EXPR";
   case sym_LIST:
      return "LIST";
   case sym_EOF:
      return "EOF";
   case sym_ERROR:
      return "ERROR";
   case sym_INT:
      return "INT";
   case sym_COMMENT:
      return "COMMENT";
   case sym_FLOAT:
      return "FLOAT";
   case sym_LIST_REST:
      return "LIST_REST";
   case sym_EMPTY:
      return "EMPTY";
   case sym_WHITESPACE:
      return "WHITESPACE";
   case sym_ID:
      return "ID";
   case sym_ATOM:
      return "ATOM";
   case sym_LPAR:
      return "LPAR";
   case sym_STR:
      return "STR";
   case sym_RPAR:
      return "RPAR";
   case sym_QUOT:
      return "QUOT";
   }
   return "(unknown symbol type)";
      // unreachable, but makes the compiler shut up
}

// If you see a big error message originating from
// symbol::print( ), then the most likely reason is that
// one of the possible attribute types or the info type has 
// no definition for operator << .
// You can either remove it from print( ), or 
// define operator << (if necessary as dummy). 

void symbol::print( std::ostream& out ) const
{
   out << "sym_" << type << "(";

   if( info. has_value( ))
      out << info. value( );

   if( std::holds_alternative< std::monostate > ( attr ))
      { out << ")"; return; }

   if( info. has_value( ))
      out << ",";

   if( std::holds_alternative< double > ( attr ))
      { out << std::get<double> ( attr ) << ")"; return; }
   if( std::holds_alternative< std::string > ( attr ))
      { out << std::get<std::string> ( attr ) << ")"; return; }
   if( std::holds_alternative< bigint > ( attr ))
      { out << std::get<bigint> ( attr ) << ")"; return; }
   if( std::holds_alternative< ast::listbp > ( attr ))
      { out << std::get<ast::listbp> ( attr ) << ")"; return; }

   throw std::runtime_error( "should be unreachable" );
}

