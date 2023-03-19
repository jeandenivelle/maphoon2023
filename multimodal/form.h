
#ifndef FORM_
#define FORM_   1

#include <variant>
#include "agent.h" 
#include "../indentation.h"
#include "../../easycomp2022a/util/shared_ptr.h"

enum logop
{
   op_false, op_true,
   op_not,
   op_and, op_or, op_imp, op_equiv,
   op_box, op_dia 
};

const char* getcstring( logop );

inline std::ostream& operator << ( std::ostream& out, logop op )
{
   out << getcstring( op ); return out;
}


struct variable;
struct nullary;
struct unary;
struct binary;
struct modal;

using formbase = std::variant< variable, nullary, unary, binary, modal > ;

struct form 
{
   util::shared_ptr< formbase > pntr;

   form( const form& ) = default; 
   form( form&& ) noexcept = default;

   form& operator = ( const form& ) = default;
   form& operator = ( form&& ) noexcept = default;

   ~form( ) noexcept = default;

   form( const std::string& );
   form( std::string&& );

   form( logop op );

   form( logop op, const form& sub );
   form( logop op, form&& sub );

   form( logop op, const form& sub1, const form& sub2 );
   form( logop op, form&& sub1, form&& sub2 );

   form( logop op, agent a, const form& sub );
   form( logop op, agent a, form&& sub );

   size_t size( ) const; 

   form nnf( int polarity ) const;
      // polarity must be > 0 or < 0. 

   template< typename T > const T* get( ) const;

   void printprefix( std::ostream& out ) const; 
   void printastree( indentation indent, std::ostream& out ) const; 
};


struct variable
{
   std::string name; 
 
   variable( const std::string& name )
      : name( name ) 
   { }
     
   variable( std::string&& name )
      : name( std::move( name ))
   { }  
};


struct nullary
{ 
   logop op;

   nullary( logop op )  
      : op( op )
   { } 
};


struct unary 
{
   logop op; 
   form sub;

   unary( logop op, const form& sub )
      : op( op ), sub( sub )
   { }

   unary( logop op, form&& sub )
      : op( op ), sub( std::move( sub ))
   { }
};

 
struct binary
{
   logop op;
   form sub1; 
   form sub2;

   binary( logop op, const form& sub1, const form& sub2 )
      : op( op ), sub1( sub1 ), sub2( sub2 )
   { }

   binary( logop op, form&& sub1, form&& sub2 )
      : op( op ), sub1( std::move( sub1 )), sub2( std::move( sub2 ))
   { } 
};


struct modal
{
   logop op;
   agent a; 
   form sub;

   modal( logop op, agent a, const form& sub )
      : op( op ), a(a), sub( sub )
   { }

   modal( logop op, agent a, form&& sub )
      : op( op ), a(a), sub( std::move( sub ))
   { }
};

 
template< typename T >
const T* form::get( ) const 
   { return std::get_if<T> ( & *pntr ); }

void printastree( std::ostream& out, indentation ind, const form& f ); 

inline std::ostream& operator << ( std::ostream& out, const form& f )
{
   f. printprefix( out );
   return out;
}

#endif
 
