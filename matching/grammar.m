
%startsymbol Instance END

%symbol { instance< std::string, std::string, std::string > } Instance
%symbol { triple< std::string, std::string, std::string > } Triple
%symbol                                                     Newlines


%symbol { std::string }   ERROR
%symbol                   SEMICOLON NEWLINE WHITESPACE
%symbol                   COMMENT
%symbol { std::string }   VALUE
%symbol                   END 

%symbolcode_h{ #include <string> } 
%symbolcode_h{ #include "instance.h" }

%symbolcode_cpp{
   void print_attr( const instance< std::string, std::string, std::string > & inst, std::ostream& out ) 
      { out << inst; }

   void print_attr( const triple< std::string, std::string, std::string > & trip, std::ostream& out )
      { out << trip; }
}
  
%parsercode_h{ #include "tokenizer.h" }

%source { tok. get( ); }

%parameter { tokenizer } tok

%rules

Instance => Instance:inst Triple:trip Newlines { inst. insert( trip ); return inst; } 
         | { return instance< std::string, std::string, std::string > ( ); } 
         ;

Newlines => NEWLINE
         | COMMENT NEWLINE
         | Newlines NEWLINE
         | Newlines COMMENT NEWLINE
         ;

Triple => VALUE:x SEMICOLON VALUE:y SEMICOLON VALUE:z { return triple(x,y,z); } ; 

%end

