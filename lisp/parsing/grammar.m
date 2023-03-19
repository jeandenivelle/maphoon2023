
%startsymbol Session EOF

%infotype{ interval }

%symbol      Session
%symbol{} EOF SCANERROR FILEBAD WHITESPACE COMMENT EMPTY
%symbol{} LPAR RPAR LBRACE RBRACE DOT 
%symbol{ list::list } S_expr 
%symbol{ list::list } STRING CHAR ATOM INTEGER FLOATING 
%symbol                QUOTE
%symbol{ list::list } Inlist
%symbol{ list::list } Nil

%symbolcode_h { #include "../../filereader.h" }
%symbolcode_h { #include "../../../easycomp2022a/bigint.h" }
%symbolcode_h { #include <vector> }
%symbolcode_h { #include "interval.h" }
%symbolcode_h { #include "../list/list.h" }

%parameter { tokenizer } tok

%reductionseq Nil S_expr

%symbolspace parsing 
%parserspace parsing

%symbolcode_cpp
{
   void print_attr( const list::list& lst, std::ostream& out )
   {
      lst -> print( out ); 
   }
}

%parsercode_h { #include "tokenizer.h" }

%source { tok. read( ); }

%rules

Session => 
   | Session S_expr : e { std::cout << " --> " << e << "\n"; } 
   ;

S_expr => ATOM:a                    { return a; }
        | STRING:s                  { return s; } 
        | INTEGER:i                 { return i; }  
        | FLOATING:f                { return f; } 
        | Nil:n                     { return n; } 
        | QUOTE S_expr:s            { return new list::quote( std::move(s)); } 
        | LPAR Inlist:lst RPAR      { return lst; } 
        | LBRACE Inlist:lst RBRACE  { return lst; } 
        ;

Inlist =>                           { return new list::nil( ); }  

       | DOT S_expr:e               { return e; } 
       | S_expr:car Inlist : cdr    { return new list::cons( car, cdr ); } 
       ;

Nil  => ATOM : a 
%requires {
   auto p = a. try_cast< list::atom > ( );
   return p && p -> getstring( ) == "nil";
}
%reduces { 
   return new list::nil( ); 
}
      ;


%end


