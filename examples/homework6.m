
%startsymbol S EOF 

%symbol S EOF a A b c

%rules

S => a S A | A | c ;

A => a b | S b ;


