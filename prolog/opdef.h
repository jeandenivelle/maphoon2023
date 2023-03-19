
// An opdef is a Prolog-style operator definition, see for example in 
//    Sterling and Shapiro, the art of Prolog. 

#ifndef PROLOG_OPDEF_
#define PROLOG_OPDEF_  1

#include <iostream>
#include <string>

namespace prolog
{

   enum optag { fx, fy, xfx, xfy, yfx, xf, yf }; 
      // x must be weaker, y can have same strength.
      // xfy = right associative.
      // yfx = left associative.
      // xfx = non-associative.
      // The general rule is that 'x' wins from 'y' when the
      // priorities are the same. That means that in
      // fx A yf, the postfix operator gets the A, so it will be
      // fx ( A yf ). 

   static const char* getcstring( optag ); 
   
   inline std::ostream& operator << ( std::ostream& out, optag tag )
   {
      out << getcstring( tag ); return out;
   }
   
   struct opdef
   {
      std::string str;
      optag type; 
      unsigned int attraction;
         // smaller number means more attraction.

      static constexpr unsigned int supattraction = 1000000;


      opdef( const std::string& str, optag type, unsigned int attraction )
         : str( str ),
           type( type ),
           attraction( attraction )
      {
         if( attraction >= supattraction )
            throw std::runtime_error( "opdef: too unattractive" ); 
      }

      bool isprefix( ) const 
         { return type == fx || type == fy; } 
      bool isinfix( ) const 
         { return type == xfx || type == xfy || type == yfx; } 
      bool ispostfix( ) const 
         { return type == xf || type == yf; } 

      // Decide how a conflict between this opdef
      // and the other opdef will be resolved. 
      // The question is how to parse T1 this T2 other T3.
      // A return value of -1 means ( T1 this T2 ) other T3.
      // A return value of 1 means T1 this ( T2 other T3 ).
      // A return value of 0 means that the conflict is a syntax error.

      int decide( const opdef& other ) const;

      bool sameside( const opdef& other ) const; 
         // True if we are on the same side, that is
         // we are both prefix, infix, or postfix operators. 
 
   };

   bool operator == ( const opdef& def1, const opdef& def2 );
   bool operator != ( const opdef& def1, const opdef& def2 );

   std::ostream& operator << ( std::ostream&, const opdef& ); 
}

#endif


