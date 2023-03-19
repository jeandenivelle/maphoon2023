
// Maphoon specification for Expressions 
// Hans de Nivelle

terminal                       LPAR, RPAR, COMMA, DOT; 
terminal                       PLUS, MINUS, TIMES, DIVIDES; 
terminal     tree.Tree         INTEGER, DOUBLE, STRING;

non terminal tree.Tree                       expr, expr1, expr2, expr3 ; 
non terminal java.util.ArrayList<tree.Tree>  exprlist ;
non terminal                                 mainloop ; 

start with mainloop ;

mainloop ::=  
         | mainloop expr:e 
              {: System.out.println( "You typed expression: " + e ); 
                 System.out.println( "AST as tree: " );
                 System.out.println( e. showTree(1) ); 

                 if( e. hasString( ) &&
                     e. getString( ). equals( "quit" ) &&
                     e. nrSubTrees( ) == 0 )
                 {
                    throw new Quit( eleft, eright ); 
                 }
              :} 

              DOT
              ;

expr ::= expr1:e      {: RESULT = e; :} 
         |
         expr:e1 PLUS expr1:e2      {: RESULT = new tree.String( "+", e1, e2 ); :} 
         |
         expr:e1 MINUS expr1:e2     {: RESULT = new tree.String( "-", e1, e2 ); :} 
         ;

expr1 ::= expr2:e    {: RESULT = e; :} 
          |
          expr1:e1 TIMES expr2:e2   {: RESULT = new tree.String( "*", e1, e2 ); :} 
          |
          expr1:e1 DIVIDES expr2:e2 {: RESULT = new tree.String( "/", e1, e2 ); :} 
          ;

expr2 ::= expr3:e    {: RESULT = e; :}  
          |
          MINUS expr2 : e {: RESULT = new tree.String( "-", e ); :} 
          ;

expr3 ::= INTEGER:i  {: RESULT = i; :}  
          |
          DOUBLE:d   {: RESULT = d; :}  
          |
          STRING:s   {: RESULT = s; :} 
          |
          STRING:s LPAR exprlist:a RPAR
             {: RESULT = new tree.String( s. getString( ), a.toArray( new tree.Tree[0] )); :}
          |
          LPAR expr:e RPAR {: RESULT = e; :} 
          ;

exprlist ::= expr:e
           {: java.util.ArrayList<tree.Tree> args = new java.util.ArrayList<> ( ); 
              args. add( e );
              RESULT = args; :} 
          |
          exprlist:a COMMA expr:e
             {: a. add(e); RESULT = a; :}  
          ;
           

