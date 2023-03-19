
// This code was produced by Maphoon 2021.
// Code for struct symbol:

#include "symbol.h"


#line 25 "grammar.m"


namespace {

  std::ostream& operator << ( std::ostream& out,
                              const util::shared_vector< tree > & vect )
  {
    out << "( ";
    for( size_t i = 0; i != vect. size( ); ++ i )
    {
      if( i != 0 ) out << ", ";
      out << vect[i];
    }
    out << ")";
    return out;
  }

}

const char* getcstring( symboltype tp )
{
   switch( tp )
   {
   case sym_mainloop:
      return "mainloop";
   case sym_expr3:
      return "expr3";
   case sym_expr2:
      return "expr2";
   case sym_expr1:
      return "expr1";
   case sym_expr:
      return "expr";
   case sym_STRING:
      return "STRING";
   case sym_DOUBLE:
      return "DOUBLE";
   case sym_WHITESPACE:
      return "WHITESPACE";
   case sym_PLUS:
      return "PLUS";
   case sym_BLOCKCOMMENT:
      return "BLOCKCOMMENT";
   case sym_INTEGER:
      return "INTEGER";
   case sym_EOF:
      return "EOF";
   case sym_DOT:
      return "DOT";
   case sym_ERROR:
      return "ERROR";
   case sym__recover_:
      return "_recover_";
   case sym_ASSIGN:
      return "ASSIGN";
   case sym_LPAR:
      return "LPAR";
   case sym_LOOKAHEAD_EMPTY:
      return "LOOKAHEAD_EMPTY";
   case sym_RPAR:
      return "RPAR";
   case sym_COMMA:
      return "COMMA";
   case sym_exprlist:
      return "exprlist";
   case sym_MINUS:
      return "MINUS";
   case sym_TIMES:
      return "TIMES";
   case sym_DIVIDES:
      return "DIVIDES";
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

   if( std::holds_alternative< std::monostate > ( attr ))
      { out << ")"; return; }

   if( std::holds_alternative< util::shared_vector<tree> > ( attr ))
      { out << std::get<util::shared_vector<tree>> ( attr ) << ")"; return; }
   if( std::holds_alternative< double > ( attr ))
      { out << std::get<double> ( attr ) << ")"; return; }
   if( std::holds_alternative< bigint > ( attr ))
      { out << std::get<bigint> ( attr ) << ")"; return; }
   if( std::holds_alternative< std::string > ( attr ))
      { out << std::get<std::string> ( attr ) << ")"; return; }
   if( std::holds_alternative< tree > ( attr ))
      { out << std::get<tree> ( attr ) << ")"; return; }

   throw std::runtime_error( "should be unreachable" );
}

