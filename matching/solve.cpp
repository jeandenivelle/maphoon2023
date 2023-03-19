
#include "instance.h"
#include "symbol.h"
#include "tokenizer.h"
#include "parser.h"

#if 0
template< 
solve( const instance& inst, ZZv
{
   setX allX;
   setY allY;
   setZ allZ;

   for( const auto& tr : inst )
   {
      allX. insert( tr. x );
      allY. insert( tr. y );
      allZ. insert( tr. z );
   }

   out << allX << "\n";
   out << allY << "\n";
   out << allZ << "\n";

   if( allX. size( ) != allY. size( ) || allY.size( ) != allZ. size( ))
   {
      std::cout << "sizes differ\n";
      return;
   }

   setX usedX;
   setY usedY;
   setZ usedZ;
}
#endif


int main( int argc, char* argv[] )
{

   tokenizer tok( filereader( &std::cin, "stdin" ));

   parser prs( tok );

   prs. debug = 1;
   prs. checkattrtypes = 2;
   auto res = prs. parse( sym_Instance );

   std::cout << "parser returned " << res << "\n";
}


