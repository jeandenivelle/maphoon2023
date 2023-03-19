
// A location is just a point in the source file. 

#ifndef PARSING_LOCATION_
#define PARSING_LOCATION_

namespace parsing
{
   struct location
   {
      long unsigned int line;
      long unsigned int column;

      location( ) = delete;

      location( long unsigned int line,
                long unsigned int column )
         : line( line ),
           column( column )
      { }  

      void merge( location loc ) { } 
      // void merge( const location& loc ) { } 
      // void merge( location&& loc ) { } 
      // All three are possible. 
   };

   inline 
   std::ostream& operator << ( std::ostream& out, location loc )
   {
      out << ( loc. line + 1 ) << "/" << ( loc. column + 1 ); 
         // Convert programmer counting to layman counting. 
      return out; 
   }
}

#endif


