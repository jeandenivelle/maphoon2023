
#include "configuration.h"

namespace
{
   void appendreversal( std::vector<char> & v, const std::string& s )
   {
      auto p = s. end( );
      while( p != s. begin( ))
      {
         -- p;
         v. push_back( *p );
      }
   }
}


configuration::configuration( const state& q,
                              const std::string& left, 
                              const std::string& right )
   : q(q) 
{
   for( char c : left )
      leftofhead. push_back(c); 
   appendreversal( rightofhead, right );
}

 
configuration& 
configuration::movehead( int dist, char blank )
{
   if( dist > 0 )
   {
      while( dist > 0 )
      {
         if( rightofhead. size( ))
         {
            leftofhead. push_back( rightofhead. back( ));
            rightofhead. pop_back( );
         }
         else
            leftofhead. push_back( blank );

         -- dist;
      }
   }
   else 
   {
      while( dist < 0 ) 
      {
         if( leftofhead. size( )) 
         {
            rightofhead. push_back( leftofhead. back( ));
            leftofhead. pop_back( );
         }
         else
            rightofhead. push_back( blank ); 

         ++ dist; 
      }
   }

   return *this;
}


bool 
configuration::applicable( const lhs& left, char blank ) const
{
   if( q == left. q )
   {
      // We have to considere the case where head stands
      // at the end of the tape:

      if( rightofhead. size( ))
         return left. req == rightofhead. back( ); 
      else
         return left. req == blank;  
   }
   else
      return false; 
}


configuration 
configuration::apply( const rhs& right, char blank ) const
{
   configuration res = *this;
 
   if( res. rightofhead. size( )) 
      res. rightofhead. pop_back( );
      // If size( ) == 0, this means we assumed a blank symbol.

   appendreversal( res. rightofhead, right. repl );
 
   res. q = right. q; 
   res. movehead( right. movedist, blank );
   return res; 
}


std::ostream& operator << ( std::ostream &out, const configuration&c )
{
   out << "( ";
   for( auto ch : c.leftofhead )
   {
      out << ch;
   }
   out << "  |" << c.q << "|  ";

   if( c.rightofhead.size() > 0 )
   {
      unsigned int i = c.rightofhead.size() - 1;

      out << c.rightofhead.at(i);

      for (; i > 0;){
         out << c.rightofhead.at(--i);
      }
      out << " )";
      return out;
   }
   else
   {

      out << " ";

      out << " )";
      return out;
   }
}

int
configuration::cmp::threeway_ignore_leading_blanks( 
      const std::vector< char > & w1,
      const std::vector< char > & w2 ) const
{
   auto p1 = w1. begin( );
   while( p1 != w1. end( ) && *p1 == blank )
      ++ p1;

   auto p2 = w2. begin( );
   while( p2 != w2. end( ) && *p2 == blank )
      ++ p2;

   while( p1 != w1. end( ) && p2 != w2. end( ))
   {
      if( *p1 < *p2 ) return -1;
      if( *p1 > *p2 ) return 1;
      ++ p1; ++ p2;
   }

   if( p1 == w1. end( ))
      if( p2 == w2. end( ))
         return 0;
      else
         return -1;
   else
      return 1;
}
 

bool 
configuration::cmp::operator( ) ( const configuration& conf1, 
                                  const configuration& conf2 ) const
{

   if( conf1.q == conf2.q )
   {
      int c = threeway_ignore_leading_blanks( conf1. leftofhead, 
                                              conf2. leftofhead );

      if(c) return c < 0;

      c = threeway_ignore_leading_blanks( conf1. rightofhead, 
                                          conf2. rightofhead );

      return c < 0; 
   }
   else
      return conf1.q < conf2.q;
}


