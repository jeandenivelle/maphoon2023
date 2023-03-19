
// This is a super ambiguous grammar, in which we try
// to see how runtime conflict resolution of Maphoon would work. 
// We want to implement it by a directive : 
// %prefer E Prefix Infix Postfix 

%startsymbol Stat EOF
%reductionseq Prefix Infix Postfix Identifier
%reductionseq While Do If Else Identifier

%symbol { opcode } Prefix Infix Postfix
%symbol While Do If Then Else
%symbol LPAR RPAR COMMA BECOMES
%symbol { ast } E Expr Stat
%symbol { long double } NUMBER
%symbol { std::string } IDENTIFIER
%symbol { std::vector< ast > } Arglist
%symbol { const function* } Function
%symbol { } EOF 

%selfcheck

%rules

Stat => While Expr Do Stat 
     | If Expr Then Stat 
     | If Expr Then Stat Else Stat
     | Expr BECOMES Expr
     ;

Expr => E; 

E => Prefix E | E Infix E | E Postfix |
     NUMBER | IDENTIFIER | LPAR E RPAR |
     Function LPAR Arglist RPAR ;
 
Arglist => E ;
Arglist => Arglist COMMA E ;


Prefix => IDENTIFIER ;
Infix => IDENTIFIER ;
Postfix => IDENTIFIER ;

Function => IDENTIFIER ;

While => IDENTIFIER ;
Do => IDENTIFIER ; 

If => IDENTIFIER ;
Then => IDENTIFIER ;
Else => IDENTIFIER ;


