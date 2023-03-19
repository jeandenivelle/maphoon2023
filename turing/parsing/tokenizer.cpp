
#include "tokenizer.h"

namespace
{

   lexing::classifier< char, parsing::symboltype >
   buildclassifier()
   {
      using namespace lexing;
      using namespace parsing;

      classifier< char, symboltype > cls( sym_EMPTY );

      auto whitespace = ( just( ' ' ) | just( '\t' ) | just( '\v' ) | 
                          just( '\f' ) | just( '\r' )). plus( );
         // Whitespace that stays on the same line.

      auto newline = just( '\n' ); 
         // Whitespace that changes the line.

      auto comment1 = word( "//" ) * 
              ( every<char>( ). without( '\n' )). star( );

      auto comment2 = 
         word( "/*" ) *
         ( every<char>( ). without( '*' ) |
            ( just('*'). plus( ) *
               every<char> ( ). without( '/' ). without( '*' )). star( )
            ). star( ) *
            just( '*' ). plus( ) * just( '/' );

      cls. insert( whitespace, sym_WHITESPACE );
      cls. insert( newline, sym_NL ); 
      cls. insert( comment1, sym_COMMENT );
      cls. insert( comment2, sym_COMMENT );

      const char* tapesym = 
         "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_#$";

      auto onechar = empty< char > ( );
      for( auto* p = tapesym; *p; ++ p )
         onechar |= just( *p );

      auto digit = range( '0', '9' );

      cls. insert( onechar, sym_CHAR );
      cls. insert( onechar * ( onechar | digit ). plus( ), sym_STRING );
 
      auto optsign = just( '-' ). optional( ) | just( '+' ). optional( ); 

      cls. insert( optsign * digit. plus( ), sym_INTEGER );

      cls. insert( word( "%alphabet" ), sym_ALPHABET );
      cls. insert( word( "%starting" ), sym_STARTING );
      cls. insert( word( "%accepting" ), sym_ACCEPTING );
      cls. insert( word( "%blank" ), sym_BLANK );
      cls. insert( word( "%transitions" ), sym_TRANSITIONS );
      cls. insert( word( "%inputs" ), sym_INPUTS );
      cls. insert( word( "%end" ), sym_EOF );
 
      cls. insert( just( ',' ), sym_COMMA );
      cls. insert( just( '.' ), sym_DOT );

      cls. insert( word( "-->" ), sym_ARROW );

      cls = make_deterministic( cls );
      cls = minimize( cls );

#if 0
      std::ofstream file( "parsing/DFA.h" );
      if( !file ) throw std::runtime_error( "could not open file" );

      printcode<char, symboltype> (
        "char", "symboltype", { "parsing" },
         cls, file,
         []( std::ostream& out, char c ) { out << (int) c; },
         []( std::ostream& out, const symboltype t ) { out << "sym_" << t; } );
#endif

      return cls;
   }
}


void parsing::tokenizer::printstate( std::ostream& out ) const
{
   out << "state of the tokenizer\n";
   out << "   " << inp;
}

#include "DFA.h"

parsing::symbol 
parsing::tokenizer::read( ) 
{
   static auto cls = buildclassifier( );
   // int cls = 55;

restart:
   auto loc = location( inp. line, inp. column );
      // We need the location before reading starts.

   if( !inp. has(1))
      return symbol( sym_EOF, loc );

   if( !inp. good() )
      return symbol( sym_BADFILE, loc );

   std::pair< symboltype, size_t >  p = readandclassify( cls, inp );

   if( p. second == 0 )
   {
      std::string attr; attr. push_back( inp. peek(0) ); 
      inp. commit(1);
      return symbol( sym_GARBAGE, loc, attr ); 
   }

   // Stuff that needs to be ignored:

   if( p. first == sym_WHITESPACE || p. first == sym_COMMENT )
   {
      inp. commit( p. second );
      goto restart;
   }

   // String attribute:

   if( p. first == sym_GARBAGE || p. first == sym_STRING )
   {
      std::string attr = std::string( inp. view( p. second )); 
      inp. commit( p. second );
      return symbol( p. first, loc, std::move( attr )); 
   }

   // Character attribute:

   if( p. first == sym_CHAR )
   { 
      std::string attr = std::string( inp. view( p. second ));
      if( attr. size( ) != 1 )
         throw std::logic_error( "attribute always has length one" );
      inp. commit( p. second );
      return symbol( p. first, loc, attr[0] );
   }

   if( p. first == sym_INTEGER )
   {
      int val = std::stoi( std::string( inp. view( p. second )));
      inp. commit( p. second );
      return symbol( p. first, loc, val );
   }

   // Symbols without attribute:

   inp. commit( p. second );
   return symbol( p. first, loc );
}


void parsing::tokenizer::test( )
{
   auto sym = read( );
   while( sym. type != sym_EOF && sym. type != sym_GARBAGE )
   {
      std::cout << sym << "\n";
      if( !sym. has_right_attribute( ))
         std::cout << "(attribute is wrong)\n";

      sym = read( );
   }
   std::cout << sym << "\n";
}


