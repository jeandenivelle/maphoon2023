
// This code was produced by Maphoon 2021.
// Code for struct symbol:

#include "symbol.h"


std::ostream& operator << ( std::ostream& out, symboltype tp )
{
   switch( tp )
   {
   case sym_EOF:
      out << "EOF"; return out;
   case sym__recover:
      out << "_recover"; return out;
   case sym_Function:
      out << "Function"; return out;
   case sym_Arglist:
      out << "Arglist"; return out;
   case sym_NUMBER:
      out << "NUMBER"; return out;
   case sym_Stat:
      out << "Stat"; return out;
   case sym_Expr:
      out << "Expr"; return out;
   case sym_E:
      out << "E"; return out;
   case sym_Infix:
      out << "Infix"; return out;
   case sym_Do:
      out << "Do"; return out;
   case sym_Postfix:
      out << "Postfix"; return out;
   case sym_If:
      out << "If"; return out;
   case sym_IDENTIFIER:
      out << "IDENTIFIER"; return out;
   case sym_Prefix:
      out << "Prefix"; return out;
   case sym_While:
      out << "While"; return out;
   case sym_RPAR:
      out << "RPAR"; return out;
   case sym_Then:
      out << "Then"; return out;
   case sym_Else:
      out << "Else"; return out;
   case sym_LPAR:
      out << "LPAR"; return out;
   case sym_COMMA:
      out << "COMMA"; return out;
   case sym_BECOMES:
      out << "BECOMES"; return out;
   }
   return out;      // unreachable, but makes the compiler shut up
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

   if( std::holds_alternative< opcode > ( attr ))
      { out << std::get<opcode> ( attr ) << ")"; return; }
   if( std::holds_alternative< ast > ( attr ))
      { out << std::get<ast> ( attr ) << ")"; return; }
   if( std::holds_alternative< long double > ( attr ))
      { out << std::get<long double> ( attr ) << ")"; return; }
   if( std::holds_alternative< std::string > ( attr ))
      { out << std::get<std::string> ( attr ) << ")"; return; }
   if( std::holds_alternative< std::vector<ast> > ( attr ))
      { out << std::get<std::vector<ast>> ( attr ) << ")"; return; }
   if( std::holds_alternative< const function* > ( attr ))
      { out << std::get<const function*> ( attr ) << ")"; return; }

   throw std::runtime_error( "should be unreachable" );
}

