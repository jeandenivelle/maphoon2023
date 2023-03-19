
// Written by Hans de Nivelle, April 2021.

#ifndef AGENT_ 
#define AGENT_  1

#include <string>
#include <iostream>
#include <unordered_map>

class agent
{
   using maptype = std::unordered_map< std::string, size_t > ; 
   maptype::const_iterator p; 

   // We normalize strings into iterators for quick 
   // comparison.

private:
   static maptype& getmap( ) 
   {
      static maptype map;
      return map;  
   }

public: 
   agent( const std::string& s )
      : p( getmap( ). insert( std::make_pair( s, getmap( ). size( ))). first )
   { }

   agent( const char* c ) 
      : agent( std::string(c) )
   { }

   const std::string& getstring( ) const
      { return p -> first; } 

   size_t getindex( ) const
      { return p -> second; }

   static void printall( std::ostream& stream );
      // Prints the table of all agents and their indices. 

   bool operator == ( agent a ) const 
      { return p -> second == a.p -> second; } 
   bool operator != ( agent a ) const 
      { return p -> second != a.p -> second; } 

   bool operator < ( agent a ) const
      { return p -> second < a.p -> second; }
   bool operator > ( agent a ) const
      { return p -> second > a.p -> second; }

   bool operator <= ( agent a ) const
      { return p -> second <= a.p -> second; }
   bool operator >= ( agent a ) const
      { return p -> second >= a.p -> second; }

};

inline std::ostream& operator << ( std::ostream& out, agent a )
{
   out << a. getstring( ); 
   return out;
}

#endif


