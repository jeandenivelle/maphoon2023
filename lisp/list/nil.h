
#ifndef LIST_NIL_
#define LIST_NIL_

namespace list {

struct nil : listbase {

  nil() noexcept {}

   bool equal_to( const list& lst ) const override
   {
      return lst. try_cast< nil > ( );
   }

   void print( std::ostream& out ) const {
      out << "n-i-l";
   }

   void prettyprint( std::ostream& out, indentation ind ) const
   {
      out << ind << "nil\n";
   }

   bool isnil( ) const override { return true; }

};

} 

#endif

