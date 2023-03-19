
// Language with tricky lookaheads:

%startsymbol S EOF
%symbol S EOF
%symbol a b c A B

%rules

S =>  c b c a | A a A b ;
A =>  B ;
B =>  c ; 


