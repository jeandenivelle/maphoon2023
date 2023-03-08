
#ifndef TURINGMACHINE_
#define TURINGMACHINE_  1

#include <iostream>

#include <map>
#include <set>

#include "lhs.h"
#include "rhs.h"

struct turingmachine
{

   state starting;                 // Starting state. 
   std::set< state > accepting;    // Accepting states.
   std::set< char > sigma;         // Input alphabet.
   char blank;                     // Blank symbol

   using deltatype = std::multimap< lhs, rhs, lhs_cmp > ;

   deltatype delta;

   turingmachine( const state& starting, const std::set< state > & accepting,
                  const std::set< char > & sigma, char blank, 
                  const deltatype& delta )
      : starting( starting ), accepting( accepting ), sigma( sigma ), 
        blank( blank ), delta( delta )
   { }

   turingmachine( state&& starting, std::set< state > && accepting, 
                  std::set< char > && sigma, char blank, 
                  deltatype&& delta ) 
           : starting( std::move( starting )), 
             accepting( std::move( accepting )), 
             sigma( std::move( sigma )), blank( blank ),
             delta( std::move( delta ))
   { } 


   bool ininputalphabet( const std::string& s ) const; 
      // True if s uses only symbols from the input alphabet.

   std::set< state > states( ) const;
      // Gets the states. 

   std::set< char > gamma_left( ) const;
   std::set< char > gamma_right( ) const;
      // Gets all symbols that occur to the left or right of a 
      // transition. In principle one should check that all
      // left symbols are in sigma, or reachable in a finite 
      // number of steps. 

};

std::ostream& operator << ( std::ostream& out, const std::set< char > & );
std::ostream& operator << ( std::ostream& out, const std::set< state > & );
std::ostream& operator << ( std::ostream& out, const turingmachine& );

#endif

