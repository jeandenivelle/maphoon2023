
// Written by Hans de Nivelle, September 2021. 

#ifndef PROLOG_FUNCPRED_
#define PROLOG_FUNCPRED_  1

#include <unordered_map> 
#include <unordered_set>
#include <string>
#include <iostream>

namespace prolog
{

   struct stringarity
   {
      std::string str;
      size_t ar;

      stringarity( const std::string& str, size_t ar )
         : str( str ), 
           ar( ar ) 
      { } 

      struct hash
      {
         std::hash< std::string > h;

         size_t operator( ) ( stringarity f ) const
         {
            return h( f. str ) + 11 * f. ar;
         }
      };

      struct equal_to
      {
         bool operator( ) ( stringarity f1, stringarity f2 ) const
         {
            return f1. ar == f2. ar && f1. str == f2. str;
         }
      };

   };

   inline std::ostream& 
   operator << ( std::ostream& out, stringarity f )
   {
      out << f. str << '/' << f. ar;
      return out;
   }

  
   class function 
   {

      using indextype = 
         std::unordered_set< stringarity, 
                             stringarity::hash, stringarity::equal_to > ;
   
      indextype::const_iterator p;

      function( ) = delete;

public:
      function( const std::string& str, size_t ar ) 
      { 
         static indextype index;
         p = index. insert( stringarity( str, ar )). first; 
      }

      function( const char* c, size_t ar )
         : function( std::string(c), ar )
      { }

      const std::string& getstring( ) const { return ( p -> str ); }
      size_t getarity( ) const { return ( p -> ar ); }

      bool operator == ( function f ) const { return p == f.p; } 
      bool operator != ( function f ) const { return p != f.p; } 

      struct hash
      {
         std::hash< const stringarity* > h;

         size_t operator( ) ( function f ) const 
            { return h( & *(f.p) ); }
      };

      struct equal_to
      {
         bool operator( ) ( function f1, function f2 ) const
            { return f1. p == f2. p; }
      };

      using set =
      std::unordered_set< function, function::hash, function::equal_to > ;

      template< typename D >
      using map =
      std::unordered_map< function, D, function::hash, function::equal_to > ;

   };


   inline std::ostream& operator << ( std::ostream& out, function f )
   {
      out << f. getstring( ) << "/" << f. getarity( ); 
      return out;
   }

}

#endif 


