
// This code was produced by Maphoon 2023.
// Code for struct symbol:

#include "symbol.h"

#include <string>


namespace {

   template< typename Iter > 
   void print_range( Iter i0, Iter i1, char c0, char c1, std::ostream& out );

#line 38 "grammar.m"
 
   void 
   print_attr( const std::vector< prolog::term > & vect, std::ostream& out ) 
   {
      print_range( vect. begin( ), vect. end( ), '{', '}', out );
   }

   void 
   print_attr( const prolog::term& trm, std::ostream& out )
   { 
      out << trm; 
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


const char* prolog::getcstring( symboltype tp )
{
   switch( tp )
   {
   case sym_TERMINATOR :
      return "TERMINATOR";
   case sym_BAR :
      return "BAR";
   case sym_SomeTerms :
      return "SomeTerms";
   case sym__recover_ :
      return "_recover_";
   case sym_INTEGER :
      return "INTEGER";
   case sym_VARIABLE :
      return "VARIABLE";
   case sym_DOUBLE :
      return "DOUBLE";
   case sym_RSQBRACKET :
      return "RSQBRACKET";
   case sym_Postfix :
      return "Postfix";
   case sym_LSQBRACKET :
      return "LSQBRACKET";
   case sym_ListEnd :
      return "ListEnd";
   case sym_Start :
      return "Start";
   case sym_COMMENT :
      return "COMMENT";
   case sym_IDENTIFIER :
      return "IDENTIFIER";
   case sym_Term :
      return "Term";
   case sym_MaybeTerms :
      return "MaybeTerms";
   case sym_OneTerm :
      return "OneTerm";
   case sym_GLUEDQUOTEDIDENTIFIER :
      return "GLUEDQUOTEDIDENTIFIER";
   case sym_ERROR :
      return "ERROR";
   case sym_COMMA :
      return "COMMA";
   case sym_EOF :
      return "EOF";
   case sym_LPAR :
      return "LPAR";
   case sym_Infix :
      return "Infix";
   case sym_GLUEDIDENTIFIER :
      return "GLUEDIDENTIFIER";
   case sym_Prefix :
      return "Prefix";
   case sym_RPAR :
      return "RPAR";
   case sym_WHITESPACE :
      return "WHITESPACE";
   case sym_QUOTEDIDENTIFIER :
      return "QUOTEDIDENTIFIER";
   }
   return "(unknown symbol type)";
      // unreachable, but makes the compiler shut up.
}

void prolog::symbol::print( std::ostream& out ) const
{
   out << type << '(';

   if( std::holds_alternative< std::monostate > ( attr ))
      { out << ')'; return; }

   if( std::holds_alternative< term > ( attr ))
      { ::print_attr( std::get<term> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< double > ( attr ))
      { ::print_attr( std::get<double> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< opdef > ( attr ))
      { ::print_attr( std::get<opdef> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::string > ( attr ))
      { ::print_attr( std::get<std::string> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< bigint > ( attr ))
      { ::print_attr( std::get<bigint> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::vector<term> > ( attr ))
      { ::print_attr( std::get<std::vector<term>> ( attr ), out ); out << ')'; return; }

   throw std::runtime_error( "symbol: attribute is corrupted" );
}


bool prolog::symbol::has_correct_attribute( ) const
{
   switch( type )
   {
   case sym_ListEnd :
   case sym_Term :
   case sym_OneTerm :
      return std::holds_alternative< term > ( attr );
   case sym_DOUBLE :
      return std::holds_alternative< double > ( attr );
   case sym_Postfix :
   case sym_Infix :
   case sym_Prefix :
      return std::holds_alternative< opdef > ( attr );
   case sym_VARIABLE :
   case sym_IDENTIFIER :
   case sym_GLUEDQUOTEDIDENTIFIER :
   case sym_GLUEDIDENTIFIER :
   case sym_QUOTEDIDENTIFIER :
      return std::holds_alternative< std::string > ( attr );
   case sym_INTEGER :
      return std::holds_alternative< bigint > ( attr );
   case sym_SomeTerms :
   case sym_MaybeTerms :
      return std::holds_alternative< std::vector<term> > ( attr );
   case sym_TERMINATOR :
   case sym_BAR :
   case sym__recover_ :
   case sym_RSQBRACKET :
   case sym_LSQBRACKET :
   case sym_Start :
   case sym_COMMENT :
   case sym_ERROR :
   case sym_COMMA :
   case sym_EOF :
   case sym_LPAR :
   case sym_RPAR :
   case sym_WHITESPACE :
      return std::holds_alternative< std::monostate > ( attr );
   }

   return false; // because the type is corrupted. 
}

