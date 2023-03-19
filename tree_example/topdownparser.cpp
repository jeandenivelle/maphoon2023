
#include "topdownparser.h"

void topdownparser::move( )
{
   if( !lookahead. has_value( ))
      throw std::logic_error( "move( ) cannot be called without lookahead" );
   else
   {
      if( lookahead. value( ). type != sym_EOF )
         lookahead. reset( );
            // This will cause the next peek( ) to read. 
   }
}

const symbol& topdownparser::peek()
{
   if( !lookahead. has_value( ))
   {
      lookahead = readsymbol(r); 
      if( show )
      {
         std::cout << "Read symbol: " << lookahead. value( ); 
      }   
   }
   return lookahead. value( ); 
}

tree topdownparser::parseE( )
{
   tree attr = parseE1( );

   while( peek( ). type == sym_PLUS || peek( ). type == sym_MINUS )
   {
      auto tp = peek( ). type; 
      move( ); 

      tree t = parseE1( );
      if( tp == sym_PLUS ) 
         attr = tree( std::string( "+" ), { attr, t } );
      else
         attr = tree( std::string( "-" ), { attr, t } ); 
   }
   return attr;
}


tree topdownparser::parseE1( )
{
   tree attr = parseE2( );

   while( peek( ). type == sym_TIMES || peek( ). type == sym_DIVIDES ) 
   {
      auto tp = peek( ). type;
      move( ); 

      tree t = parseE2( ); 
      if( tp == sym_TIMES )
         attr = tree( std::string( "*" ), { attr, t } );
      else
         attr = tree( std::string( "/" ), { attr, t } ); 
   }

   return attr;
}

tree topdownparser::parseE2( ){
   unsigned int nrminus = 0;

   while( peek( ). type == sym_MINUS )
   {
      move( );
      ++ nrminus; 
   } 
   auto attr = parseE3( );
   while( nrminus )
   {
      attr = tree( std::string( "-" ), { attr } ); 
      -- nrminus;
   }
   std::cout << "E2 returns " << attr << "\n";
   return attr; 
}

tree topdownparser::parseE3( ){
   std::cout << "parsing an E3\n";

   const symbol& s = peek( ); 
   if( s. type == sym_INTEGER )
   {
      // It must be done in this order, because move will spoil s.

      tree attr = tree( s. get< bigint > ());
      move( );
      return attr;
   }

   if( s. type == sym_DOUBLE )
   {
      tree attr = tree( s. get< double > ( ));
      move( );
      return attr;
   }

   if( s. type == sym_STRING )
   {
      std::string f = s. get< std::string > ();
      move( ); 
      if( peek( ). type == sym_LPAR )
      {
         move( ); 
         util::shared_vector< tree > subtrees; 
         subtrees. push_back( parseE( )); 

         while( peek( ). type == sym_COMMA )
         {
            move( );
            subtrees. push_back( parseE( ));
         }

         if( peek( ). type != sym_RPAR ){
            std::string msg = "expected right parenthesis, but instead found ";
            msg += getcstring( peek( ). type );
            throw syntaxerror( msg, r. line, r. column ); 
         }

         move( ); 
         return tree( std::move(f), std::move(subtrees) );
      }
      else
         return f;  
   }

   if( s. type == sym_LPAR )
   {
      move( ); 
      auto attr = parseE( );

      if( peek( ). type != sym_RPAR )
      {
         std::string msg = "expected right parenthesis, instead found ";
         msg += getcstring( peek( ). type );
         throw syntaxerror( msg, r. line, r. column );
      }
      move( );  // We skip the ')'. 
      return attr; 
   }

   std::string msg = "expected number, string, or right parenthesis ";
   msg += "but instead found ";
   msg += getcstring( s. type );
   throw syntaxerror( msg, r. line, r. column ); 
}


