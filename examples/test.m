
%startsymbol S EOF 

%symbol S EOF E if then else ident becomes number

%rules

S => if E then S 
  |  if E then S else S 
  |  ident becomes E 
  ;

E => number 
  | ident
  ;


