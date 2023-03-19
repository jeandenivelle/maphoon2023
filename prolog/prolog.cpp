
#include "function.h"
#include "term.h"
#include "termbasics.h"



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
                  prolog::term op )
{
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

   if( op. sel( ) == prolog::sel_functional )
   {
      auto v = op. view_func( );

      if( v. f( ). getarity( ) == 0 )
      {
         const auto& s = v. f( ). getstring( );

         synt. insert( prolog::opdef( s, p -> second, u )); 
         return;
      }

      if( v. f( ) == consnil. cons )
      {
         while( op. sel( ) == prolog::sel_functional &&
                op. view_func( ). f( ) == consnil. cons )
         {
            auto first = op. view_func( ). sub(0);

            if( first. sel( ) == prolog::sel_functional &&
                first. view_func( ). size( ) == 0 ) 
            {
               const auto& arg = first. view_func( ). f( ). getstring( );    

               synt. insert( prolog::opdef( arg, p -> second, u )); 
            }

            op = op. view_func( ). sub(1);  
         }

         if( op. sel( ) != prolog::sel_functional ||
             op. view_func( ). f( ) != consnil. nil )
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
   auto t1 = prolog::term( prolog::sel_int, 4 );
   auto t2 = prolog::term( prolog::sel_string, std::string( "hallo" ));
   auto t3 = prolog::term( prolog::sel_double, 2.718 );

   std::cout << t1 << "\n";
   std::cout << t2 << "\n";
   std::cout << t3 << "\n";

   auto f3 = prolog::function( "f", 3 ); 

   auto t = prolog::term( prolog::sel_functional, f3, { t1, t2, t3 } );

   std::cout << t << "\n";

   lexing::filereader rd( &std::cin, "std::cin" ); 

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

         if( res. get< prolog::term > ( ). sel( ) == prolog::sel_functional ) 
         {
            auto p = res. get< prolog::term > ( ). view_func( );

            if( p. size( ) == 0 && p.f( ). getstring( ) == "halt" ) 
            {
               std::cout << "this was the halt command\n";
               std::cout << "there were " << nrerrors << " errors\n";
               return 0;
            }

            if( p. size( ) == 0 && p.f( ). getstring( ) == "debug" )
            {
               std::cout << "turning debugging on\n";
               prs. debug = 1;
            }

            if( p. size( ) == 0 && p.f( ). getstring( ) == "nodebug" )
            {
               std::cout << "turning debugging off\n";
               prs. debug = 0;
            } 
      
            if( p. size( ) == 3 && p. f( ). getstring( ) == "op" )
            {
               if( p. sub(0). sel( ) == prolog::sel_bigint &&
                   p. sub(1). sel( ) == prolog::sel_functional &&
                   p. sub(1). view_func( ). size( ) == 0 ) 
               {
                  addoperator( synt, consnil, p. sub(0). view_bigint( ). i( ), 
                               p. sub(1). view_func( ). f( ). getstring( ), 
                               p. sub(2) ); 
               }
            }

            if( p. size( ) == 0 && p. f( ). getstring( ) == "show" )
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


