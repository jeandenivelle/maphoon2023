
%startsymbol Fp Eof

%symbol Fp Eof Sign Int Frac Exp plus minus digit dot E e

%rules

Fp   => Sign Int Frac Exp 
     ;

Sign =>
      | plus 
      | minus
      ;

Int => digit 
     | Int digit 
     ;

Frac => 
      | dot Int
      ;

Exp  =>
      | e Sign Int
      | E Sign Int
      ;






