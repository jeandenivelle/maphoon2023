
%startsymbol MachineWithInputs EOF

%infotype{ location }

%symbol                                  EOF EMPTY BADFILE
%symbol                                  COMMENT WHITESPACE NL 
%symbol                                  COMMA ARROW
%symbol{ char }                          CHAR 
%symbol{ int }                           INTEGER LeftRightStat

%symbol{ std::string }                   GARBAGE 
%symbol{ std::string }                   STRING
%symbol                                  DOT

%symbol                                  ALPHABET STARTING ACCEPTING BLANK TRANSITIONS INPUTS

%symbol{ std::pair< turingmachine, std::vector< std::string >> } MachineWithInputs

%symbol{ lhs }                           Lhs
%symbol{ rhs }                           Rhs
%symbol{ std::string }                   Word
%symbol{ std::vector< std::string > }    Words OptInputs
%symbol{ state }                         State

%symbol{ std::set< char > }              CharacterSet
%symbol{ std::set< state > }             StateSet

%symbol{ std::pair< lhs, rhs > }         Transition 
%symbol{ turingmachine::deltatype }      TransitionMap

%symbol NewLines OptNewLines


%symbolcode_h { #include "../turingmachine.h" }
%symbolcode_h { #include "location.h" }
%symbolcode_h { #include <vector> }

%symbolcode_cpp {

   void print_attr( const state& st, std::ostream& out )
   {
      out << st;
   }

   void print_attr( const turingmachine::deltatype& delta, std::ostream& out )
   {
      print_range( delta. begin( ), delta. end( ), '{', '}', out );
   }

   void print_attr( const std::set<char> & set, std::ostream& out )
   {
      print_range( set. begin( ), set. end( ), '{', '}', out );
   }

}

%parameter { tokenizer } tok

%symbolspace parsing 
%parserspace parsing 

%parsercode_h { #include "tokenizer.h" }

%source { tok. read( ); }

%rules

MachineWithInputs => 
   OptNewLines 
   ALPHABET CharacterSet:sigma NewLines
   STARTING State:starting NewLines
   ACCEPTING StateSet:accepting NewLines
   BLANK CHAR:blank NewLines
   TRANSITIONS NewLines TransitionMap:delta 
   OptInputs : inputs

{ return { turingmachine( std::move( starting ), std::move( accepting ),
                          std::move( sigma ), blank, std::move( delta )), inputs }; }
;

CharacterSet 
   =>                          { return std::set<char> ( ); } 
   | CharacterSet:set CHAR:c   { set. insert(c); return set; } 
   ;

StateSet 
   =>                          { return std::set<state> ( ); } 
   | StateSet:set State:s      { set. insert(s); return set; }  
   ;

TransitionMap =>  
      { return turingmachine::deltatype( ); } 
| TransitionMap: d Transition: t 
      { d. insert( std::move(t)); return d; }
;

Transition => Lhs:left ARROW Rhs:right NewLines { return std::pair( left, right ); } 
    ;

Lhs => State:q COMMA CHAR:c { return lhs(q,c); } 
    ; 

Rhs => State:q COMMA Word:w COMMA INTEGER:i { return rhs(q,w,i); } 
    | State:q COMMA Word:w COMMA LeftRightStat:i { return rhs( q,w,i ); } 
    ;

Word => CHAR:c      { std::string s = {c}; return s; }
     |  STRING:s    { return s; }
     |  DOT         { return std::string( ); } 
     ;

State => Word : w        { return state(w); } 
      ;

LeftRightStat => CHAR : c
%requires { char c1 = toupper(c); return c1 == 'L' || c1 == 'S' || c1 == 'R'; }
%reduces 
{
   char c1 = toupper(c);
   if( c1 == 'L' ) return -1;  // left 
   if( c1 == 'R' ) return 1;   // right
   return 0;   // stationary. 
}
;

// NewLines is at least one NL :

NewLines => NL
   | NewLines NL
   ;

OptNewLines => 
   | NewLines
   ;

// Input words are optional:

OptInputs 
   => { return std::vector< std::string > ( ); } 
   | INPUTS NewLines Words:inp { return inp; }  
   ;

Words 
  =>                            { return std::vector< std::string > ( ); }
  | Words:inp Word:w NewLines   { inp. push_back(w); return inp; }  
  ;

%errors
   TRANSITIONS 2 TransitionMap State 1 => "lhs character" ; 
   MachineWithInputs  => "a state, %inputs, %end, or a test word" ; 
   TransitionMap Lhs => "-->" ;
   ARROW => "destination state";
   ARROW State 1 => "rhs word" ;
   ARROW 1 State 1 COMMA 1 Word 2 => "L,S,R, or integer" ;
   Rhs 1 => "newline" ;
   ACCEPTING 4 => "state" ; 
   BLANK * * => "a newline" ;
   ALPHABET * => "a symbol";
%end



