
%startsymbol S EOF

%symbol S EOF lpar rpar

%rules


S => lpar S rpar S 
   | 
   ;


