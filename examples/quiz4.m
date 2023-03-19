
%startsymbol S EOF 

%symbol S EOF a A b

%rules

S => a S a | A ;
A => b a b S | b S b ;



