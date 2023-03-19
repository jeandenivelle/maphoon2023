

// Written by Ravinder Indarapu and Hans de Nivelle in March 2003.
// Replaced containers::hashmap by std::map in August 2005. 

#include "syntax.h"
#include <limits>

namespace prolog 
{


   syntax::syntax( ) :
      printlistsyntax( true ),
      maxprintdepth( std::numeric_limits< unsigned int > :: max( )),
      terminator( "." ) 
   { }


   bool syntax::insert( const opdef& def )
   {
      auto r = operators. equal_range( def. str ); 
      for( auto p = r. first; p != r. second; ++ p )
      {
         if( p -> second. sameside( def ))
         {
            if( p -> second != def )
            {
               p -> second = def; 
               return true;
            }
            else
               return false;    // already present. 
         }
      }
      
      operators. insert( std::pair( def. str, def ));
         // We could try to use r. second as hint, but it seems
         // not worth the effort. 

      return true; 
   }

 
   bool syntax::remove( const opdef& def )
   {
      auto r = operators. equal_range( def. str ); 
      for( auto p = r. first; p != r. second; ++ p )
      {
         if( p -> second == def )
         {
            operators. erase(p);
            return true;
         }
      }
      return false; 
   }


   bool prolog::syntax::hasprefixdef( const std::string& str ) const
   {
      auto r = operators. equal_range( str );
      for( auto p = r. first; p != r. second; ++ p )
      {
         if( p -> second. isprefix( ))
            return true;
      }
      return false;
   }


   bool prolog::syntax::hasinfixdef( const std::string& str ) const
   {
      auto r = operators. equal_range( str );
      for( auto p = r. first; p != r. second; ++ p )
      {
         if( p -> second. isinfix( ))
            return true;
      }
      return false;
   }


   bool prolog::syntax::haspostfixdef( const std::string& str ) const
   {
      auto r = operators. equal_range( str );
      for( auto p = r. first; p != r. second; ++ p )
      {
         if( p -> second. ispostfix( ))
            return true;
      }
      return false;
   }


   const prolog::opdef& 
   prolog::syntax::prefixdef( const std::string& str ) const
   {
      auto r = operators. equal_range( str );
      for( auto p = r. first; p != r. second; ++ p )
      {
         if( p -> second. isprefix( ))
            return p -> second; 
      }
      throw std::logic_error( "prefix not found" ); 
   }


   const prolog::opdef& 
   prolog::syntax::infixdef( const std::string& str ) const
   {
      auto r = operators. equal_range( str );
      for( auto p = r. first; p != r. second; ++ p )
      {
         if( p -> second. isinfix( ))
            return p -> second; 
      }
      throw std::logic_error( "infix not found" ); 
   }

   
   const prolog::opdef& 
   prolog::syntax::postfixdef( const std::string& str ) const
   {
      auto r = operators. equal_range( str );
      for( auto p = r. first; p != r. second; ++ p )
      {
         if( p -> second. ispostfix( ))
            return p -> second; 
      }
      throw std::logic_error( "postfix not found" ); 
   }


   void 
   prolog::syntax::print( std::ostream& os ) const 
   {
      os << "Prolog Syntax:\n\n";

      os << "printlistsyntax =     " << printlistsyntax << "\n";
      os << "maxprintdepth =       " << maxprintdepth << "\n";
      os << "terminator =          " << terminator << "\n";
      os << "\n";

      os << "defined operators: \n";
      for( const auto& def : operators ) 
         os << "   " << def. second << "\n"; 
   }

} 


