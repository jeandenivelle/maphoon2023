

#include "tokenizer.h"

lexing::classifier< char, parsing::symboltype > 
parsing::tokenizer::buildclassifier()
{
   using namespace lexing;

   classifier< char, symboltype > cls( sym_EMPTY );

   auto letter = range( 'a', 'z' ) | range( 'A', 'Z' );
   auto digit  = range( '0', '9' );
   auto hexdigit =
      range( '0', '9' ) | range( 'a', 'f' ) | range( 'A', 'F' );

   auto whitespace = 
      ( just(' ') | just('\t') | just('\n') | just('\v') |
        just('\f') | just('\r')). plus( ); 

   auto comment = just( ';' ) * ( every<char> (). without( '\n' ) ). star( );

   {
      auto escape = word( "\\0" ) | word( "\\n" ) |
                    word( "\\t" ) | word( "\\v" ) |
                    word( "\\r" ) | word( "\\f" ) |
                    word( "\\\'" ) | word( "\\\"" ) |
                    word( "\\\\" ) | ( word( "\\x" ) * hexdigit * hexdigit );

      // Characters allowed in strings:

      auto onechar = letter | digit; 

      std::string allowedinstring = "`,.+-*/#$%:;=_!?|&()[]{}<>^@~ \t";

      for( char c : allowedinstring )
         onechar |= just(c);

      cls. insert( just( '\'' ) *
                   ( onechar | escape | just( '"' )) *
                     just( '\'' ),
                   sym_CHAR );

      cls. insert( just( '"' ) *
                   ( onechar | escape | just( '\'' ) ). star( ) *
                   just( '"' ), sym_STRING );
   }

   auto integer = just('0') | 
                  just('-'). optional() * range( '1', '9' ) * digit. star();

   auto optsign = ( just( '-' ) | just( '+' ) ). optional( );

   auto exp = ( just( 'e' ) | just( 'E' ) ) *
                 optsign * digit. plus( );

   cls. insert( optsign * digit. plus( ) * exp, sym_FLOATING );

   cls. insert( optsign *
                digit. plus( ) * just( '.' ) * 
                digit. star( ) * exp. optional( ),
                sym_FLOATING );

   cls. insert( digit. star( ) * just( '.' ) * 
                digit. plus( ) * exp. optional( ),
                sym_FLOATING );

   cls. insert( integer, sym_INTEGER );

   cls. insert( just( '(' ), sym_LPAR );
   cls. insert( just( ')' ), sym_RPAR );
   cls. insert( just( '{' ), sym_LBRACE );
   cls. insert( just( '}' ), sym_RBRACE );
   cls. insert( just( '.' ), sym_DOT );

   cls. insert( comment, sym_COMMENT );
   cls. insert( whitespace, sym_WHITESPACE );

   cls. insert( ( letter | just( '_' ) | just( '?' )) *
                ( letter | digit | just( '_' ) | just( '?' )). star( ), 
                sym_ATOM );

   {
      std::string allowed = "~!@#$%^&*/+-=<>|";
      auto all = empty<char> ( );
      for( auto c : allowed )
         all |= just(c);
 
      cls. insert( all. plus( ), sym_ATOM );
   }

   cls. insert( just( '\'' ), sym_QUOTE );

   cls. insert( word( "%end" ), sym_EOF );
   cls. insert( word( "%eof" ), sym_EOF );

   return minimize( make_deterministic( cls ));
}


parsing::symbol 
parsing::tokenizer::read( )
{
   static auto cls = buildclassifier( );

restart:
   location startloc = getlocation( ); 
      // Point where the symbol that we are hoping to read, will start.
  
   if( !inp. has(1))
      return symbol( sym_EOF, interval( startloc, startloc ) );

   if( !inp. good() )
      return symbol( sym_FILEBAD, interval( startloc, startloc ) );

   auto p = readandclassify( cls, inp );
  
   if( p. second == 0 )
   {
      std::string attr = { inp. peek(0) };
      inp. commit(1);
      return symbol( sym_SCANERROR, interval( startloc, getlocation( ) )); 
   }

   if( p. first == sym_WHITESPACE || p. first == sym_COMMENT )
   {
      inp. commit( p. second );
      goto restart; 
   }

   if( p. first == sym_ATOM )
   {
      list::list attr = new list::atom( std::string( inp. view( p. second )));
      inp. commit( p. second );
      return symbol( sym_ATOM, interval( startloc, getlocation( )), attr );
   }

   if( p. first == sym_INTEGER )
   {
      list::list attr = new list::integer( bigint( inp. view( p. second )));
      inp. commit( p. second );
      return symbol( sym_INTEGER, interval( startloc, getlocation( )), attr );
   }

   if( p. first == sym_FLOATING )
   {
      list::list attr = 
         new list::floating( std::stod( std::string( inp. view( p. second ))));

      inp. commit( p. second );
      return symbol( sym_FLOATING, interval( startloc, getlocation( )), attr );
   }

   if( p. first == sym_STRING )
   {
      std::string_view v = inp. view( p. second );
      v = v. substr( 1, v. size( ) - 2 );
         // We remove the quotes.

      list::list attr = 
         new list::string( std::string(v));

      inp. commit( p. second );
      return symbol( sym_STRING, interval( startloc, getlocation( )), attr );
   }

   // All the tokens that have no attribute:

   inp. commit( p. second );
   return symbol( p. first, interval( startloc, getlocation( )) );
}


void parsing::tokenizer::test( )
{
   auto sym = read( );
   while( sym. type != sym_EOF && sym. type != sym_SCANERROR )
   {
      std::cout << sym << "\n";
      if( !sym. has_right_attribute( ))
         std::cout << "(attribute is wrong)\n";

      sym = read( );
   }
   std::cout << sym << "\n";
}


