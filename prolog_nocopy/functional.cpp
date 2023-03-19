
// Written by Hans de Nivelle, September 2021.

#include "functional.h" 

bool prolog::functional::equal_to( const term& t ) const
{
   auto p = t. try_cast<functional> ( );
   if(p)
   {
      if( f != p -> f || sub. size( ) != p -> sub. size( ))
         return false; 

      for( size_t i = 0; i != sub. size( ); ++ i )
      {
         if( ! sub[i] -> equal_to( p -> sub[i] ))
            return false;
      }
      return true; 
   }
   return false;
}

void prolog::functional::print( std::ostream& out ) const 
{
   out << f. getstring( );
   if( sub. size( ))
   {
      out << "( ";
      for( auto p = sub. begin( ); p != sub. end( ); ++ p )
      { 
         if( p != sub. begin( ))
            out << ", ";
         (*p) -> print( out );
      }
      out << " )"; 
   }
}

void prolog::functional::printhash( util::hashbuilder& hh ) const 
{
   function::hash h; 

   hh << h(f); 
   for( const auto& s : sub )
      s -> printhash(hh);
}


