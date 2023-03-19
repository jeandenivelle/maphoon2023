

%startsymbol E EOF

%symbol E EOF F plus id

%rules

E => F plus E | F ; 
F => id ; 


