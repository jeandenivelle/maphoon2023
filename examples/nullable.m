
// A ridiculous grammar that has nullable symbols.

%startsymbol S EOF

%symbol S EOF E1 E2 E3 F1 F2 F3 A B C

%rules

S => E1 E2 E3 
  | F1 F2 F3 E2 
  ;
    

E1 => F1 F2 F3
  ;  

F1 => F2 ;
F2 => F3 ;
F3 => A B ;
E1 => B B A ;
A => B ;
B => A ; 
B => C ;
C => ;

