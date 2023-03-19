
#ifndef SYNTAXERROR_
#define SYNTAXERROR_

#include <string>
#include <exception>

class syntaxerror : public std::exception 
{
   std::string msg;
   unsigned int line;
   unsigned int column;

public:
   syntaxerror( const std::string& msg, 
                unsigned int line, unsigned int column )
      : msg( msg ),
        line( line ),
        column( column )
   { } 

   const char* what() const noexcept 
   {
      static char res[200];
      sprintf( res, "%s at position %u/%u", msg. c_str( ), line, column );  
      return res; 
   }

};

#endif

