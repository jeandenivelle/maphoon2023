
// This code was produced by Maphoon 2023.
// Code for struct symbol:

#include "symbol.h"

#include <string>


namespace {

   template< typename Iter > 
   void print_range( Iter i0, Iter i1, char c0, char c1, std::ostream& out );

#line 41 "grammar.m"

   void print_attr( const form& f, std::ostream& out )
      { out << f; }


//   void print_attr( const agent& a, std::ostream& out )
//      { out << a; }

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


const char* getcstring( symboltype tp )
{
   switch( tp )
   {
   case sym__recover_ :
      return "_recover_";
   case sym_Index :
      return "Index";
   case sym_Var :
      return "Var";
   case sym_ID :
      return "ID";
   case sym_WHITESPACE :
      return "WHITESPACE";
   case sym_ERROR :
      return "ERROR";
   case sym_NOT :
      return "NOT";
   case sym_NUMBER :
      return "NUMBER";
   case sym_IMP :
      return "IMP";
   case sym_DIASTART :
      return "DIASTART";
   case sym_COMMENT :
      return "COMMENT";
   case sym_Session :
      return "Session";
   case sym_AND :
      return "AND";
   case sym_DIAEND :
      return "DIAEND";
   case sym_CONST :
      return "CONST";
   case sym_RIGHTPAR :
      return "RIGHTPAR";
   case sym_DIA :
      return "DIA";
   case sym_LEFTPAR :
      return "LEFTPAR";
   case sym_OR :
      return "OR";
   case sym_EOF :
      return "EOF";
   case sym_EQUIV :
      return "EQUIV";
   case sym_SEMICOLON :
      return "SEMICOLON";
   case sym_BOX :
      return "BOX";
   case sym_BOXSTART :
      return "BOXSTART";
   case sym_RETURN :
      return "RETURN";
   case sym_NNF :
      return "NNF";
   case sym_BOXEND :
      return "BOXEND";
   case sym_BECOMES :
      return "BECOMES";
   case sym_METAVAR :
      return "METAVAR";
   case sym_Formula :
      return "Formula";
   case sym_Command :
      return "Command";
   }
   return "(unknown symbol type)";
      // unreachable, but makes the compiler shut up.
}

void symbol::print( std::ostream& out ) const
{
   out << type << '(';

   if( std::holds_alternative< std::monostate > ( attr ))
      { out << ')'; return; }

   if( std::holds_alternative< form > ( attr ))
      { ::print_attr( std::get<form> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< bool > ( attr ))
      { ::print_attr( std::get<bool> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< unsigned int > ( attr ))
      { ::print_attr( std::get<unsigned int> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::string > ( attr ))
      { ::print_attr( std::get<std::string> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< agent > ( attr ))
      { ::print_attr( std::get<agent> ( attr ), out ); out << ')'; return; }

   throw std::runtime_error( "symbol: attribute is corrupted" );
}


bool symbol::has_correct_attribute( ) const
{
   switch( type )
   {
   case sym_Formula :
   case sym_Command :
      return std::holds_alternative< form > ( attr );
   case sym_CONST :
      return std::holds_alternative< bool > ( attr );
   case sym_NUMBER :
      return std::holds_alternative< unsigned int > ( attr );
   case sym_Var :
   case sym_ID :
   case sym_METAVAR :
      return std::holds_alternative< std::string > ( attr );
   case sym_Index :
      return std::holds_alternative< agent > ( attr );
   case sym__recover_ :
   case sym_WHITESPACE :
   case sym_ERROR :
   case sym_NOT :
   case sym_IMP :
   case sym_DIASTART :
   case sym_COMMENT :
   case sym_Session :
   case sym_AND :
   case sym_DIAEND :
   case sym_RIGHTPAR :
   case sym_DIA :
   case sym_LEFTPAR :
   case sym_OR :
   case sym_EOF :
   case sym_EQUIV :
   case sym_SEMICOLON :
   case sym_BOX :
   case sym_BOXSTART :
   case sym_RETURN :
   case sym_NNF :
   case sym_BOXEND :
   case sym_BECOMES :
      return std::holds_alternative< std::monostate > ( attr );
   }

   return false; // because the type is corrupted. 
}

