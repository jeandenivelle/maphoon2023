
%startsymbol S EOF

%symbol S EOF G F rpar E plus id number lpar times

%rules

S => E ;

E => E plus F
  | F
  ;  

F => F times G 
  | G 
  ;

G => lpar E rpar 
  | number
  | id 
  ;


