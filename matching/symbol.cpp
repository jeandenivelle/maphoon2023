
// This code was produced by Maphoon 2022.
// Code for struct symbol:

#include "symbol.h"

#include <string>


namespace {

   template< typename Iter > 
   void print_range( Iter i0, Iter i1, char c0, char c1, std::ostream& out );

#line 18 "grammar.m"

   void print_attr( const instance< std::string, std::string, std::string > & inst, std::ostream& out ) 
      { out << inst; }

   void print_attr( const triple< std::string, std::string, std::string > & trip, std::ostream& out )
      { out << trip; }

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
   case sym_VALUE :
      return "VALUE";
   case sym_COMMENT :
      return "COMMENT";
   case sym_NEWLINE :
      return "NEWLINE";
   case sym_SEMICOLON :
      return "SEMICOLON";
   case sym_END :
      return "END";
   case sym_WHITESPACE :
      return "WHITESPACE";
   case sym_ERROR :
      return "ERROR";
   case sym_Newlines :
      return "Newlines";
   case sym_Triple :
      return "Triple";
   case sym_Instance :
      return "Instance";
   }
   return "(unknown symbol type)";
      // unreachable, but makes the compiler shut up.
}

void symbol::print( std::ostream& out ) const
{
   out << type << '(';

   if( std::holds_alternative< std::monostate > ( attr ))
      { out << ')'; return; }

   if( std::holds_alternative< instance<std::string, std::string, std::string> > ( attr ))
      { ::print_attr( std::get<instance<std::string, std::string, std::string>> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< triple<std::string, std::string, std::string> > ( attr ))
      { ::print_attr( std::get<triple<std::string, std::string, std::string>> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::string > ( attr ))
      { ::print_attr( std::get<std::string> ( attr ), out ); out << ')'; return; }

   throw std::runtime_error( "symbol: attribute is corrupted" );
}


bool symbol::has_right_attribute( ) const
{
   switch( type )
   {
   case sym_Instance :
      return std::holds_alternative< instance<std::string, std::string, std::string> > ( attr );
   case sym_Triple :
      return std::holds_alternative< triple<std::string, std::string, std::string> > ( attr );
   case sym_VALUE :
   case sym_ERROR :
      return std::holds_alternative< std::string > ( attr );
   case sym__recover_ :
   case sym_COMMENT :
   case sym_NEWLINE :
   case sym_SEMICOLON :
   case sym_END :
   case sym_WHITESPACE :
   case sym_Newlines :
      return std::holds_alternative< std::monostate > ( attr );
   }

   return false; // because the type is corrupted. 
}

