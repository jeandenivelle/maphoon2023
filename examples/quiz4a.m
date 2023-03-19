
%startsymbol S EOF 

%symbol S EOF a A b

%rules

S => a S a | a A ;
A => a a b S | b S b ;


