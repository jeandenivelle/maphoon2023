
#ifndef TREE_
#define TREE_  1

#include <iostream>
#include <variant>
#include <string>

#include "../../easycomp2021b/util/shared_vector.h" 
#include "../../easycomp2021b/bigint.h"

#include "../indentation.h" 

// in Java, all of this was OO. In C++, one can do without.  

class tree
{
   std::variant< double, std::string, bigint > top; 
   util::shared_vector< tree > subtrees; 

public:
   tree( double d, const util::shared_vector< tree > & subtrees )
      : top(d), 
        subtrees( subtrees )
   { }
 
   tree( const std::string& s,
                   const util::shared_vector< tree > & subtrees =
                         util::shared_vector< tree > ( ) )
      : top(s),
        subtrees( subtrees ) 
   { } 

   tree( const bigint& i, const util::shared_vector< tree > & subtrees =
                          util::shared_vector< tree > ( ) )
      : top(i),
        subtrees( subtrees )
   { }  

   tree( double d, util::shared_vector< tree > && subtrees = 
                   util::shared_vector< tree > ( )) 
      : top(d),
        subtrees( std::move( subtrees ))
   { } 

   tree( std::string&& s, util::shared_vector< tree> && subtrees =
                          util::shared_vector< tree > ( ))
      : top( std::move(s)),
        subtrees( std::move( subtrees ))
   { }

   tree( bigint&& i, util::shared_vector< tree> && subtrees = 
                     util::shared_vector< tree > ( ))
      : top( std::move(i)),
        subtrees( std::move( subtrees ))
   { } 
                        
   size_t size( ) const;
      // Total size of the tree.

   bool hasinteger( ) const 
      { return std::holds_alternative< bigint > ( top ); } 
   bool hasdouble( ) const
      { return std::holds_alternative< double > ( top ); } 
   bool hasstring( ) const
      { return std::holds_alternative< std::string > ( top ); } 
  
   const bigint& getinteger( ) const
      { return std::get< bigint > ( top ); } 
   bigint& getinteger( )
      { return std::get< bigint > ( top ); } 

   double getdouble( ) const 
      { return std::get< double > ( top ); }
   double& getdouble( )
      { return std::get< double > ( top ); } 

   const std::string& getstring( ) const
      { return std::get< std::string > ( top ); } 
   std::string& getstring( )
      { return std::get< std::string > ( top ); } 

   std::ostream& printtop( std::ostream& out ) const;
 
   std::ostream& flatprint( std::ostream& out ) const; 

   std::ostream& 
   print( std::ostream& out, indentation ind = indentation(0) ) const;  

   size_t nrsubtrees( ) const 
      { return subtrees. size( ); } 

   const tree& operator[] ( size_t i ) const
      { return subtrees[i]; }

};

inline std::ostream& operator<< ( std::ostream &out, const tree& t ) 
{
   return t. flatprint( out );
}

bool tops_equal( const tree& t1, const tree& t2 ); 
   // True if the tops of t1 and t2 are equal. 

bool operator == ( const tree& t1, const tree& t2 );

inline bool operator != ( const tree& t1, const tree& t2 )
{
   return ! ( t1 == t2 );
}

#endif

