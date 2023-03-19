
#ifndef VARSTORE_
#define VARSTORE_   1

#include <map>
#include <string>
#include <iostream>

template< typename D > 
class varstore
{

   std::map<std::string,D> table;

public:
   varstore( ) = default; 

   bool contains( const std::string& var ) const 
      { return table. find( var ) != table. end( ); }

   void assign( const std::string& var, const D& val )
   { 
      auto p = table. insert( std::make_pair( var, val ));
      if( !p. second ) p. first -> second = val;
   }

   const D* lookup( const std::string& var ) const
   {
      auto p = table. find( var );
      if( p != table. end( ))
         return & ( p -> second );
      else
         return nullptr;
   }

   D* lookup( const std::string& var )
   {
      auto p = table. find( var );
      if( p != table. end( ))
         return & ( p -> second );
      else
         return nullptr;
   }

   void clear( ) 
      { table. clear( ); } 

   void print( std::ostream& out ) const
   {
      out << "Variable Store:\n";
      for( const auto& t : table )
         out << "   " << t. first << " = " << t. second << "\n";
      out << "\n";
   }

};

template< typename D > 
inline std::ostream& operator << ( std::ostream& out, const varstore<D>& vs )
{
   vs. print( out );
   return out;
}

#endif

