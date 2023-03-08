
#include "turingmachine.h"

bool turingmachine::ininputalphabet( const std::string& s ) const 
{
   for( auto ch : s )
   {
      if( !sigma. contains( ch ))
         return false;
   }
   return true;
}

std::set< state > 
turingmachine::states( ) const
{
   std::set< state > res;
   for( const auto& d : delta )
   {
      res. insert( d. first. q );
      res. insert( d. second. q );
   }
   return res;
}

std::set< char > turingmachine::gamma_left( ) const
{
   std::set< char > res;
   for( const auto& d : delta )
      res. insert( d. first. req ); 
   return res; 
}

std::set< char > turingmachine::gamma_right( ) const 
{
   std::set< char > res;
   for( const auto& d : delta )
   {
      for( char c : d. second. repl ) 
         res. insert(c);  
   }
   return res;
}

 
std::ostream& 
operator << ( std::ostream& out, const std::set< char > & set )
{
   out << '{';

   for( auto p = set. begin(); p != set. end(); ++ p )
   {
      if( p != set. begin() )
         out << ", ";
      else
         out << " ";

      out << *p;
   }
   out << " }\n";

   return out; 
}


std::ostream& 
operator << ( std::ostream& out, const std::set< state > & set )
{
   out << '{'; 

   for( auto p = set. begin( ); p != set. end( ); ++ p )
   {
      if( p != set. begin( ))
         out << ", ";
      else
         out << " ";
      out << *p;
   }
   out << " }\n";

   return out;
}


std::ostream& 
operator << ( std::ostream& out, const turingmachine& tm ) 
{
   out << "\n"; 
   out << "Turing Machine:\n";
   out << "   input alphabet =  " << tm. sigma << "\n";
   out << "   q-starting =      " << tm. starting << "\n";
   out << "   q-accepting =     " << tm. accepting << "\n";

   out << "   blank symbol =    " << tm. blank << "\n";
   out << "   delta =\n";
   for( const auto& d : tm. delta )
      out << "      " << d.first << " ---> " << d. second << "\n";

   return out; 
}


