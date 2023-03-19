
#ifndef LIST_QUOTE_
#define LIST_QUOTE_

namespace list {

struct quote : listbase 
{

   list arg;

   quote() noexcept {}

   quote( const list& arg )
      : arg( arg )
   { }

   quote( list&& arg )
      : arg( std::move( arg ))
   { }

   bool equal_to( const list& lst ) const override
   {
      auto p = lst. try_cast< quote > ( ); 
      return p && p -> arg -> equal_to( arg ); 
   }

   void print( std::ostream& out ) const {
      out << "'" << arg; 
   }

   void prettyprint( std::ostream& out, indentation ind ) const
   {
      out << "'\n"; 
      arg -> prettyprint( out, ind + 3 );  
   }

};

} 

#endif

