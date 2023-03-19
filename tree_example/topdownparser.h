
#ifndef TOPDOWNPARSER_
#define TOPDOWNPARSER_  1

#include "symbol.h"
#include "tokenizing.h"
#include "syntaxerror.h"

class topdownparser  
{
   std::optional<symbol> lookahead;
   filereader& r;

public:
   bool show = false;

   // We become the owner of the file reader.

   topdownparser( filereader& r ) 
      : r(r) 
   {}

   void move( );
   const symbol& peek( );

   tree parseE( );
   tree parseE1( );
   tree parseE2( );
   tree parseE3( );

};

#endif

