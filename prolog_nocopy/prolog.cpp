
#include "function.h"
#include "term.h"
#include "opdef.h"
#include "syntax.h"
#include "listconstr.h"
#include "tokenizer.h"
#include "parser.h"

void tptp( prolog::syntax& synt )
{
   synt. insert( { "$", prolog::fx, 99 } );
   synt. insert( { "!", prolog::fx, 400 } ); 
   synt. insert( { "?", prolog::fx, 400 } ); 

   synt. insert( { "=", prolog::xfx, 405 } ); 
   synt. insert( { "!=", prolog::xfx, 405 } ); 

   synt. insert( { "~", prolog::fy, 450 } ); 
   synt. insert( { ":", prolog::xfy, 450 } ); 

   synt. insert( { "|", prolog::xfy, 502 } );
   synt. insert( { "~|", prolog::xfy, 502 } ); 

   synt. insert( { "&", prolog::xfy, 503 } );
   synt. insert( { "~&", prolog::xfy, 503 } ); 

   synt. insert( { "=>", prolog::xfy, 504 } );
   synt. insert( { "<=", prolog::xfy, 504 } );

   synt. insert( { "<=>", prolog::xfy, 505  } );
   synt. insert( { "<~>", prolog::xfy, 505  } );
}


// Taken from Sterling and Shapiro, but corrected, because
// it is very incomplete and contains many errors.

void standard( prolog::syntax& synt )
{
   synt. insert( prolog::opdef( ":-", prolog::xfx, 1200 ));
   synt. insert( prolog::opdef( "-->", prolog::xfx, 1200 ));
   synt. insert( prolog::opdef( ":-", prolog::xf, 1200 ));
      // Sterling & Shapiro say this is a prefix operator, but
      // that cannot be right, because you want to be able to write
      // p(X) :- . 

   synt. insert( prolog::opdef( ";", prolog::xfy, 1100 ));

   synt. insert( { ",", prolog::xfy, 1000 } );

   synt. insert( { "\\+", prolog::fx, 800 } );

   synt. insert( { "=", prolog::xfx, 700 } );
   synt. insert( { "\\=", prolog::xfx, 700 } );

   synt. insert( { "==", prolog::xfx, 700 } );
   synt. insert( { "\\==", prolog::xfx, 700 } );

   synt. insert( { "=..", prolog::xfx, 700 } );

   synt. insert( { "is", prolog::xfx, 700 } );
      // Not present in Sterling & Shapiro.

   synt. insert( { "=:=", prolog::xfx, 700 } );
   synt. insert( { "=\\=", prolog::xfx, 700 } );
   
   synt. insert( { "<", prolog::xfx, 700 } );
   synt. insert( { "=<", prolog::xfx, 700 } );
   synt. insert( { ">", prolog::xfx, 700 } );
   synt. insert( { ">=", prolog::xfx, 700 } );

   synt. insert( prolog::opdef( "+", prolog::yfx, 500 ));
   synt. insert( prolog::opdef( "-", prolog::yfx, 500 ));

   synt. insert( prolog::opdef( "*", prolog::yfx, 400 ));
   synt. insert( prolog::opdef( "/", prolog::yfx, 400 ));
   synt. insert( prolog::opdef( "mod", prolog::yfx, 400 ));

   synt. insert( prolog::opdef( "&", prolog::xfy, 200 ));
   synt. insert( prolog::opdef( "^", prolog::xfy, 200 ));

   synt. insert( prolog::opdef( "-", prolog::fy, 200 ));
}

void addoperator( prolog::syntax& synt, const prolog::listconstr& consnil, 
                  const bigint& attr, const std::string& assoc, 
                  const prolog::term& op )
{
   std::cout << "op = " << op << "\n";

   if( attr > bigint( 100000000 ))
      return;

   unsigned int u = attr. getunsigned( );

   const static std::map< std::string, prolog::optag > 
      assocnames = { { "fx", prolog::fx },
                     { "fy", prolog::fy },
                     { "xfx", prolog::xfx },
                     { "xfy", prolog::xfy },
                     { "yfx", prolog::yfx },
                     { "xf", prolog::xf },
                     { "yf", prolog::yf } };

   auto p = assocnames. find( assoc );
   if( p == assocnames. end( ))
      return;

   auto f = op. try_cast< prolog::functional > ( );

   if(f)
   {
      if( f -> getfunction( ). getarity( ) == 0 )
      {
         const auto& s = f -> getfunction( ). getstring( );

         synt. insert( prolog::opdef( s, p -> second, u )); 
         return;
      }

      if( f -> getfunction( ) == consnil. cons )
      {
         while( f && f -> getfunction( ) == consnil. cons )
         {
            if( auto car = (*f)[0]. try_cast< prolog::functional > ( ); 
                car && car -> getarity( ) == 0 ) 
            {
               const auto& arg = car -> getfunction( ). getstring( );    

               synt. insert( prolog::opdef( arg, p -> second, u )); 
            }

            f = (*f)[1]. try_cast< prolog::functional > ( ); 
         }

         if( !f || f -> getfunction( ) != consnil. nil )
         {
            std::cout << "end of operator list should have been " << consnil. nil << "\n"; 
         }

         return;
      }
   }
   else 
      std::cout << "cannot define " << op << " as operator\n";  
}


int main( int argc, char* argv[] )
{
   filereader rd( &std::cin, "std::cin" ); 

   prolog::tokenizer tok( std::move( rd ));

   prolog::syntax synt;

   std::cout << synt << "\n";

   prolog::listconstr consnil( { "nil", 0 }, { "cons", 2 } );

   std::cout << consnil << "\n";

   varstore< prolog::term > vs;

   prolog::parser prs( tok, vs, synt, consnil );

   prs. debug = 0;
   prs. checkattrtypes = 0;
   prs. checkmovable = 0;
 
   unsigned int nrerrors = 0;

   while( true )
   {
      std::cout << "--------------------------------------\n";
      std::cout << synt << "\n";

      prs. ensurelookahead( );
      if( prs. getlookahead( ). type == prolog::sym_EOF )
      {
         std::cout << "end-of-file reached in normal fashion\n";
         std::cout << "there were " << nrerrors << " errors\n";
         return 0;
      }

      auto res = prs. parse( prolog::sym_Start );
      std::cout << "parser returned:    " << res << "\n\n";
      std::cout << "lookahead = " << prs. getlookahead( ) << "\n"; 

      if( res. type == prolog::sym_OneTerm && 
          prs. getlookahead( ). type == prolog::sym_TERMINATOR )
      {
         std::cout << "parse succesful\n"; 

         // check for 'halt' and 'op': 

         if( auto p = res. get< prolog::term > ( ). 
                      try_cast< prolog::functional > ( ) ; p ) 
         {
            if( p -> getarity( ) == 0 && 
                p -> getfunction( ). getstring( ) == "halt" ) 
            {
               std::cout << "this was the halt command\n";
               std::cout << "there were " << nrerrors << " errors\n";
               return 0;
            }

            if( p -> getarity( ) == 0 &&
                p -> getfunction( ). getstring( ) == "debug" )
            {
               std::cout << "turning debugging on\n";
               prs. debug = 1;
            }

            if( p -> getarity( ) == 0 && 
                p -> getfunction( ). getstring( ) == "nodebug" )
            {
               std::cout << "turning debugging off\n";
               prs. debug = 0;
            } 
      
            if( p -> getarity( ) == 3 &&
                p -> getfunction( ). getstring( ) == "op" )
            {
               auto prior = (*p)[0].try_cast< prolog::constant< bigint >> ( );
               auto assoc = (*p)[1].try_cast< prolog::functional > ( );
               
               if( prior && assoc && assoc -> getarity( ) == 0 )
               {
                  addoperator( synt, consnil, prior -> c, 
                               assoc -> getfunction( ). getstring( ), 
                               (*p)[2] ); 
               }
            }

            if( p -> getarity( ) == 0 &&
                p -> getfunction( ). getstring( ) == "show" )
            {
               std::cout << synt << "\n";
            }

         }
      }
      else
      {
         std::cout << "error # " << ( ++ nrerrors ) << "\n";
         while( prs. getlookahead( ). type != prolog::sym_TERMINATOR &&
                prs. getlookahead( ). type != prolog::sym_EOF )
         {
            tok. contextstack. clear( ); 
               // Becaue the tokenizer remembers context.

            std::cout << "ignoring " << prs. getlookahead( ) << "\n";

            prs. resetlookahead( );
            prs. ensurelookahead( ); 
         }

      }

      if( prs. getlookahead( ). type == prolog::sym_TERMINATOR )
         prs. resetlookahead( ); 
      prs. reset( ); 
   }
 
   return 0; 
}

