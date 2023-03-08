
// Hans de Nivelle, November 2017.

#ifndef STATE_INCLUDED
#define STATE_INCLUDED   1

#include <iostream>
#include <string>

struct state
{
   std::string s;
      // We don't bother to normalize strings, because
      // we expect that they are short.

   state( ) = delete;

   state( const std::string& s )
       : s(s)
   { }

   state( const char* c )
       : s( std::string(c) )
   { } 

};

inline bool operator == ( const state& st1, const state& st2 )
{
   return st1.s == st2.s;
}

inline bool operator < ( const state& st1, const state& st2 ) 
{
   return st1.s < st2.s; 
}


inline std::ostream &operator << ( std::ostream &out, const state& s )
{
   out << s.s;
   return out;
}

#endif

