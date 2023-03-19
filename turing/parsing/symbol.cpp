
// This code was produced by Maphoon 2023.
// Code for struct symbol:

#include "symbol.h"

#include <string>


namespace {

   template< typename Iter > 
   void print_range( Iter i0, Iter i1, char c0, char c1, std::ostream& out );

#line 39 "grammar.m"


   void print_attr( const state& st, std::ostream& out )
   {
      out << st;
   }

   void print_attr( const turingmachine::deltatype& delta, std::ostream& out )
   {
      print_range( delta. begin( ), delta. end( ), '{', '}', out );
   }

   void print_attr( const std::set<char> & set, std::ostream& out )
   {
      print_range( set. begin( ), set. end( ), '{', '}', out );
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
   case sym_OptNewLines :
      return "OptNewLines";
   case sym_NewLines :
      return "NewLines";
   case sym_TransitionMap :
      return "TransitionMap";
   case sym_STRING :
      return "STRING";
   case sym_COMMA :
      return "COMMA";
   case sym_ALPHABET :
      return "ALPHABET";
   case sym_Words :
      return "Words";
   case sym_NL :
      return "NL";
   case sym_ARROW :
      return "ARROW";
   case sym_WHITESPACE :
      return "WHITESPACE";
   case sym_BADFILE :
      return "BADFILE";
   case sym_COMMENT :
      return "COMMENT";
   case sym_MachineWithInputs :
      return "MachineWithInputs";
   case sym_StateSet :
      return "StateSet";
   case sym_LeftRightStat :
      return "LeftRightStat";
   case sym_Lhs :
      return "Lhs";
   case sym_CHAR :
      return "CHAR";
   case sym_DOT :
      return "DOT";
   case sym_EMPTY :
      return "EMPTY";
   case sym_GARBAGE :
      return "GARBAGE";
   case sym_EOF :
      return "EOF";
   case sym_STARTING :
      return "STARTING";
   case sym_ACCEPTING :
      return "ACCEPTING";
   case sym_BLANK :
      return "BLANK";
   case sym_TRANSITIONS :
      return "TRANSITIONS";
   case sym_INPUTS :
      return "INPUTS";
   case sym__recover_ :
      return "_recover_";
   case sym_Transition :
      return "Transition";
   case sym_Rhs :
      return "Rhs";
   case sym_Word :
      return "Word";
   case sym_INTEGER :
      return "INTEGER";
   case sym_OptInputs :
      return "OptInputs";
   case sym_State :
      return "State";
   case sym_CharacterSet :
      return "CharacterSet";
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

   if( std::holds_alternative< std::set<char> > ( attr ))
      { ::print_attr( std::get<std::set<char>> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< state > ( attr ))
      { ::print_attr( std::get<state> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< rhs > ( attr ))
      { ::print_attr( std::get<rhs> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::pair<lhs, rhs> > ( attr ))
      { ::print_attr( std::get<std::pair<lhs, rhs>> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< int > ( attr ))
      { ::print_attr( std::get<int> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::set<state> > ( attr ))
      { ::print_attr( std::get<std::set<state>> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< char > ( attr ))
      { ::print_attr( std::get<char> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::pair<turingmachine, std::vector<std::string> > > ( attr ))
      { ::print_attr( std::get<std::pair<turingmachine, std::vector<std::string> >> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::vector<std::string> > ( attr ))
      { ::print_attr( std::get<std::vector<std::string>> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< lhs > ( attr ))
      { ::print_attr( std::get<lhs> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< std::string > ( attr ))
      { ::print_attr( std::get<std::string> ( attr ), out ); out << ')'; return; }
   if( std::holds_alternative< turingmachine::deltatype > ( attr ))
      { ::print_attr( std::get<turingmachine::deltatype> ( attr ), out ); out << ')'; return; }

   throw std::runtime_error( "symbol: attribute is corrupted" );
}


bool parsing::symbol::has_correct_attribute( ) const
{
   switch( type )
   {
   case sym_CharacterSet :
      return std::holds_alternative< std::set<char> > ( attr );
   case sym_State :
      return std::holds_alternative< state > ( attr );
   case sym_Rhs :
      return std::holds_alternative< rhs > ( attr );
   case sym_Transition :
      return std::holds_alternative< std::pair<lhs, rhs> > ( attr );
   case sym_LeftRightStat :
   case sym_INTEGER :
      return std::holds_alternative< int > ( attr );
   case sym_StateSet :
      return std::holds_alternative< std::set<state> > ( attr );
   case sym_CHAR :
      return std::holds_alternative< char > ( attr );
   case sym_MachineWithInputs :
      return std::holds_alternative< std::pair<turingmachine, std::vector<std::string> > > ( attr );
   case sym_Words :
   case sym_OptInputs :
      return std::holds_alternative< std::vector<std::string> > ( attr );
   case sym_Lhs :
      return std::holds_alternative< lhs > ( attr );
   case sym_STRING :
   case sym_GARBAGE :
   case sym_Word :
      return std::holds_alternative< std::string > ( attr );
   case sym_TransitionMap :
      return std::holds_alternative< turingmachine::deltatype > ( attr );
   case sym_OptNewLines :
   case sym_NewLines :
   case sym_COMMA :
   case sym_ALPHABET :
   case sym_NL :
   case sym_ARROW :
   case sym_WHITESPACE :
   case sym_BADFILE :
   case sym_COMMENT :
   case sym_DOT :
   case sym_EMPTY :
   case sym_EOF :
   case sym_STARTING :
   case sym_ACCEPTING :
   case sym_BLANK :
   case sym_TRANSITIONS :
   case sym_INPUTS :
   case sym__recover_ :
      return std::holds_alternative< std::monostate > ( attr );
   }

   return false; // because the type is corrupted. 
}

