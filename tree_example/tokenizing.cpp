
#include "tokenizing.h"

#include "../../lexing2021/classifier.h"
#include "../../lexing2021/algorithms.h"

lexing::classifier < char, symboltype > buildclassifier( )
{
  using namespace lexing;
  
  classifier< char, symboltype > cl( sym_ERROR );

  cl.insert( just( '(' ), sym_LPAR );
  cl.insert( just( ')' ), sym_RPAR );
  cl.insert( just( ',' ), sym_COMMA );
  cl.insert( just( '.' ), sym_DOT );

  cl.insert( just( '=' ), sym_ASSIGN );

  cl.insert( just( '+' ), sym_PLUS );
  cl.insert( just( '-' ), sym_MINUS );
  cl.insert( just( '*' ), sym_TIMES );
  cl.insert( just( '/' ), sym_DIVIDES );


  auto lineterminator = ( just('\r') | just( '\n' ) | word( "\r\n") );
  auto whitespace = ( lineterminator | just( '\t' ) | just( '\f' ) | just( ' ' ) ).plus();

  auto blockcomment = word( "/*" ) * ( every<char>().without('*') | just( '*' ).plus() * every<char>().without('/') ).star() * word( "*/" );
  cl.insert( blockcomment, sym_BLOCKCOMMENT );

  auto digit       = range( '0', '9' );
  auto id_letter   = ( range( 'a', 'z' ) | range( 'A', 'Z' ) | just( '_' ) );

  auto intconst = just( '0' ) | \
                  just( '-' ).optional() * range( '1', '9' ) * ( digit ).star();

  auto dblconst = intconst * ( just( '.' ) * digit. plus() );

  auto strconst = id_letter * ( id_letter | digit ).star( );

  cl.insert( whitespace, sym_WHITESPACE );
  cl.insert( blockcomment, sym_BLOCKCOMMENT );
  cl.insert( intconst, sym_INTEGER );
  cl.insert( dblconst, sym_DOUBLE );
  cl.insert( strconst, sym_STRING );
  
  return cl;
}

std::string readstring( filereader &r, size_t len ){
  std::string res;
  for( size_t i = 0; i < len; ++ i){
    res += r.peek(i);
  }

  return res;
}

symbol readsymbol( filereader &r ){

  auto cls = buildclassifier( );

  auto res = readandclassify( cls, r );
  do{
    if( res. first != sym_BLOCKCOMMENT && res. first != sym_WHITESPACE ){
      break;
    }
    r.commit( res. second );
    res = readandclassify( cls, r );
  } while( res. first == sym_BLOCKCOMMENT || res. first == sym_WHITESPACE );

  if( !r. has(1) ){
    return symbol( sym_EOF );
  }

  if( res. first == sym_INTEGER ){
    std::string val = readstring( r, res. second );
    bigint bi( val );
    r. commit( res. second );

    return symbol( sym_INTEGER, bi );
  }

  if( res. first == sym_DOUBLE ){
    std::string val = readstring( r, res. second );
    double d = std::stod( val );
    r. commit( res. second );

    return symbol( sym_DOUBLE, d );
  }

  if( res. first == sym_STRING ){
    std::string val = readstring( r, res. second );
    r. commit( res. second );

    return symbol( sym_STRING, val );
  }

  if( res. second == 0 )
    r. commit( 1 );
  else
    r. commit( res. second );

  return symbol( res. first );
}

