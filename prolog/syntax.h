
// Written by Ravinder Indarapu and Hans de Nivelle in March 2003.
// Replaced containers::hashmap by std::map in August 2005.
// Somewhat modified in September 2006, I don't remember how. 
// Rewritten in September 2021 to work with Maphoon, and with
// std::unordered_multimap.  

#ifndef PROLOG_SYNTAX_
#define PROLOG_SYNTAX_   1

#include <unordered_map>
#include "opdef.h" 

// A syntax determines in which format terms are read and printed.
// Its main component are the definitions of Prolog-style 
// prefix/infix/postfix operator definitions.
// In addition, it defines:
//
//  - Whether list syntax is used when printing a term. List syntax is 
//    always accepted as input.
//
// - Up to which depth terms are printed. This does not affect the 
//   depth of terms that can be read. 
//
// - The string that is used for terminating input. Reasonable choices are
//   . or ; 

namespace prolog 
{

   class syntax
   {
      std::unordered_multimap< std::string, opdef > operators; 

   public: 
      bool printlistsyntax;
         //  If true, then list notation is used when printing output.
         //  List notation is always accepted as input.

      unsigned int maxprintdepth;
         //  The maximal depth up to which terms are printed. A subtree that
         //  occurs at a depth deeper than maxprintdepth, is printed as
         //  <...> . One could argue that this is not part of the syntax,
         //  but I don't know a better place to put it.

      std::string terminator; 

      syntax( );
         // Create a new empty syntax. 
         // The syntax is initially empty, the default nil is [], and the
         // default cons is the dot. By default, printlistsyntax = true. The
         // default value for maxprintdepth is +infinity. 

      bool insert( const opdef& def );
         // We insert def if either there was no definition for def.ident
         // at the given position (prefix,infix or postfix), or 
         // a conflicting definition, which we will overwrite. 
         // We return true if the insertion took place. 

      bool remove( const opdef& def );
         // Delete def, if it occurs. Otherwise do nothing.
         // Return true if the removal took place.

      bool hasprefixdef( const std::string& ident ) const;
      bool hasinfixdef( const std::string& ident ) const;
      bool haspostfixdef( const std::string& ident ) const;

      const opdef& prefixdef( const std::string& ident ) const;
      const opdef& infixdef( const std::string& ident ) const;
      const opdef& postfixdef( const std::string& ident ) const;
         // Must be checked in advance that it exists.

      void clear( ) { operators. clear( ); }

      void print( std::ostream& out ) const; 
   };


   inline std::ostream& operator << ( std::ostream& out, const syntax& synt )
   {
      synt. print( out );
      return out;
   }

}

#endif

