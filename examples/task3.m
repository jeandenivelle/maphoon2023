
%startsymbol E EOF 

%symbol E EOF identifier integer lpar rpar A A1 comma

%rules

E => identifier 
   | integer 
   | identifier lpar A rpar
   ;


 A => 
   | A1 
   ;

 A1 => E 
    | E comma A1
    ;






