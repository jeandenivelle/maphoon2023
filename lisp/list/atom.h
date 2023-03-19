
#ifndef LIST_ATOM_
#define LIST_ATOM_

#include "list.h"
#include <unordered_set>

namespace list 
{

   class atom : public listbase 
   {

      using indextype = std::unordered_set< std::string > ;
      indextype :: const_iterator p;

   public:
      atom( const std::string& s )
      {
         static indextype index;
         auto val = index. insert(s);
         p = val. first;
      }
    
      atom( const char* c )
         : atom( std::string(c))
      { }

      const std::string& getstring( ) const
         { return *p; }

      bool operator == ( atom at ) const
         { return p == at.p; }
      bool operator != ( atom at ) const
         { return p != at.p; }

      struct hash_obj 
      {
         size_t operator( ) ( atom at ) const
         {
            std::hash< const std::string* > h;
            return h( & * at.p );
         }
      };

      struct equal_obj
      {
         bool operator( ) ( atom at1, atom at2 ) const
         {
            return at1.p == at2.p;
         }
      };

      bool equal_to( const list& lst ) const override
         { auto a = lst. try_cast< atom > ( );
           return a && p == a -> p; }

      void print( std::ostream& out ) const override
         {  out << getstring( ); } 
      void prettyprint( std::ostream& out, indentation ind ) const override
         { out << ind << getstring( ) << '\n'; } 

   };

}

#endif


