
// This code was produced by Maphoon 2022.
// Code for struct symbol:

#include "symbol.h"

#include <string>


namespace {

   template< typename Iter > 
   void print_range( Iter i0, Iter i1, char c0, char c1, std::ostream& out );

#line 29 "grammar.m"

   void print_attr( const list::list& lst, std::ostream& out )
   {
      lst -> print( out ); 
   }

}

namespace {

   template< typename T > 
   void print_attr( const T& t, std::ostream& out )
   {
      out << "(no print)";
   }

   void print_attr( bool b, std::ostream& out )
   {
      if(b)
         out << "true";
      else
         out << "false";
   }

   void print_attr( char c, std::ostream& out )
   {
      out << '\'' << c << '\'';
   }

   void print_attr( long int i, std::ostream& out )
   {
      out << i;
   }

   void print_attr( long unsigned int u, std::ostream& out )
   {
      out << u;
   }

   void print_attr( double d, std::ostream& out )
   {
      out << d;
   }

   void print_attr( const std::string& s, std::ostream& out )
   {
      out << '"' << s << '"';
   }

   template< typename T1, typename T2 > 
   void print_attr( const std::pair<T1,T2> & pr, std::ostream& out )
   {
      out << '[';
      print_attr( pr. first, out ); out << ',';
      print_attr( pr. second, out ); out << ']';
   }

   template< typename Iter > 
   void print_range( Iter i0, Iter i1, char c0, char c1, std::ostream& out )
   {
      out << '{';
      for( auto it = i0; it != i1; ++ it )
      {
         if( it != i0 )
            out << ',';
         print_attr( *it, out );
      }
      out << '}';
   }

}


const char* parsing::getcstring( symboltype tp )
{
   switch( tp )
   {
   case sym_Nil :
      return "Nil";
   case sym_Inlist :
      return "Inlist";
   case sym__recover_ :
      return "_recover_";
   case sym_QUOTE :
      return "QUOTE";
   case sym_ATOM :
      return "ATOM";
   case sym_CHAR :
      return "CHAR";
   case sym_Session :
      return "Session";
   case sym_EOF :
      return "EOF";
   case sym_LPAR :
      return "LPAR";
   case sym_SCANERROR :
      return "SCANERROR";
   case sym_FILEBAD :
      return "FILEBAD";
   case sym_WHITESPACE :
      return "WHITESPACE";
   case sym_INTEGER :
      return "INTEGER";
   case sym_COMMENT :
      return "COMMENT";
   case sym_RPAR :
      return "RPAR";
   case sym_EMPTY :
      return "EMPTY";
   case sym_S_expr :
      return "S_expr";
   case sym_FLOATING :
      return "FLOATING";
   case sym_LBRACE :
      return "LBRACE";
   case sym_STRING :
      return "STRING";
   case sym_RBRACE :
      return "RBRACE";
   case sym_DOT :
      return "DOT";
   }
   return "(unknown symbol type)";
      // unreachable, but makes the compiler shut up.
}

void parsing::symbol::print( std::ostream& out ) const
{
   out << type << '(';

   if( info. has_value( ))
      out << info. value( );

   if( std::holds_alternative< std::monostate > ( attr ))
      { out << ')'; return; }

   if( info. has_value( ))
      out << ',';

   if( std::holds_alternative< list::list > ( attr ))
      { ::print_attr( std::get<list::list> ( attr ), out ); out << ')'; return; }

   throw std::runtime_error( "symbol: attribute is corrupted" );
}


bool parsing::symbol::has_right_attribute( ) const
{
   switch( type )
   {
   case sym_Nil :
   case sym_Inlist :
   case sym_ATOM :
   case sym_CHAR :
   case sym_INTEGER :
   case sym_S_expr :
   case sym_FLOATING :
   case sym_STRING :
      return std::holds_alternative< list::list > ( attr );
   case sym__recover_ :
   case sym_QUOTE :
   case sym_Session :
   case sym_EOF :
   case sym_LPAR :
   case sym_SCANERROR :
   case sym_FILEBAD :
   case sym_WHITESPACE :
   case sym_COMMENT :
   case sym_RPAR :
   case sym_EMPTY :
   case sym_LBRACE :
   case sym_RBRACE :
   case sym_DOT :
      return std::holds_alternative< std::monostate > ( attr );
   }

   return false; // because the type is corrupted. 
}

