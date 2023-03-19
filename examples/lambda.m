
// I think that this language originates from a LEGO-style
// type checker for lambda expressions.


%startsymbol Command EOF

%symbol VAR METAVAR EOF 
%symbol ARROW COLON COMMA SEMICOLON   
%symbol LEFTACCOL RIGHTACCOL LEFTPAR RIGHTPAR LEFTSQR RIGHTSQR 
%symbol Lambda Lambda1 Lambda2 Lambda3 Decls Names Command

%rules

Command   => Lambda SEMICOLON 
          ;         

Lambda    => LEFTSQR Decls RIGHTSQR Lambda 
          | LEFTACCOL Decls RIGHTACCOL Lambda
          | Lambda1 
          ;

Lambda1   => Lambda2 
          | Lambda2 ARROW Lambda1
          ;

Lambda2   => Lambda3
          | Lambda2 Lambda3 
          ;

Lambda3   => LEFTPAR Lambda RIGHTPAR 
          | VAR
          | METAVAR 
          ;

Decls     => Names COLON Lambda
          ;

Names     => VAR
          | Names COMMA VAR
          ;



