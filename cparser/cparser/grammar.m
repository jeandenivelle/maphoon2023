%startsymbol program EOF

%symbolcode_h { #include "ast/ast.h" }

%parsercode_h { #include <numeric> }
%parsercode_h { #include "lexer.h" }

%symbol {} ERROR EOF

%symbol {} VOID INT CHAR LONG FLOAT DOUBLE SHORT TYPE_NAME TYPEDEF 
%symbol {} REGISTER CONST STATIC SIGNED UNSIGNED VOLATILE AUTO EXTERN
%symbol {} ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN
%symbol {} ADD SUB MUL DIV MOD PIPE CARET AMP NOT NEG QUEST RIGHT_OP LEFT_OP PTR_OP
%symbol {} LPAR RPAR LCUR RCUR LSQR RSQR COLON SEMICOLON COMMA DOT ELLIPSIS
%symbol {} EQ_OP NE_OP LT_OP GT_OP LE_OP GE_OP AND_OP OR_OP INC_OP DEC_OP
%symbol {} IF ELSE FOR DO WHILE GOTO CONTINUE BREAK SWITCH CASE SIZEOF RETURN
%symbol {} STRUCT ENUM UNION
%symbol { int } CONSTANT
%symbol { char } CHARLIT
%symbol {} DEFAULT
%symbol { std::string } IDENTIFIER STRING_LITERAL
%symbol {} COMMENTS SPACE

%symbol { ast::expr_p } initializer
%symbol { ast::statements } statement_list
%symbol { ast::statements } declaration_list
%symbol { ast::stmt_p } declaration
%symbol { ast::decl_p } struct_declarator
%symbol { ast::decl_p } declarator
%symbol { ast::statements } compound_statement 
%symbol { ast::stmt_p } jump_statement
%symbol { ast::stmt_p } statement 
%symbol { ast::expr_p } primary_expression 
%symbol { ast::expr_p } postfix_expression
%symbol { ast::expr_p } unary_expression
%symbol { ast::expr_p } cast_expression
%symbol { ast::expr_p } multiplicative_expression
%symbol { ast::expr_p } additive_expression 
%symbol { ast::expr_p } exclusive_or_expression
%symbol { ast::expr_p } relational_expression 
%symbol { ast::expr_p } inclusive_or_expression
%symbol { ast::expr_p } equality_expression
%symbol { ast::expr_p } conditional_expression
%symbol { ast::expr_p } shift_expression
%symbol { ast::expr_p } and_expression
%symbol { ast::expr_p } logical_and_expression
%symbol { ast::expr_p } logical_or_expression
%symbol { ast::expr_p } constant_expression 
%symbol { ast::expr_p } assignment_expression
%symbol { ast::expr_p } expression 
%symbol { ast::stmt_p } expression_statement
%symbol { ast::expr_p } enumerator
%symbol { ast::type_p } pointer
%symbol { ast::type_p } declaration_specifiers 
%symbol { ast::type_p } storage_class_specifier 
%symbol { ast::stmt_p } iteration_statement 
%symbol { ast::decl_p } abstract_declarator 
%symbol { std::string } assignment_operator 
%symbol { ast::decl_p } parameter_declaration
%symbol { ast::expr_p } initializer_list
%symbol { ast::stmt_p } labeled_statement
%symbol { ast::type_p } type_specifier
%symbol { ast::decl_p } struct_declaration
%symbol { ast::stmt_p } external_declaration
%symbol { ast::type_p } type_name
%symbol { ast::decl_p } direct_abstract_declarator
%symbol { ast::type_p } enum_specifier
%symbol { std::vector< ast::decl_p > } struct_declarator_list
%symbol { ast::type_p } struct_or_union
%symbol { std::string } unary_operator
%symbol { ast::expressions } argument_expression_list
%symbol { ast::decl_p } direct_declarator
%symbol { std::vector< ast::decl_p > } parametertype_p_list
%symbol { std::vector< ast::decl_p > } struct_declaration_list
%symbol { ast::type_p } struct_or_union_specifier
%symbol { std::vector< ast::decl_p > } parameter_list
%symbol { ast::type_p } type_qualifier
%symbol { ast::type_p } type_qualifier_list
%symbol { std::vector< ast::decl_p > } identifier_list
%symbol { ast::expressions } enumerator_list
%symbol { ast::type_p } specifier_qualifier_list
%symbol { ast::stmt_p } selection_statement
%symbol { ast::decl_p } init_declarator
%symbol { std::vector< ast::decl_p > } init_declarator_list
%symbol { ast::stmt_p } function_definition
%symbol { ast::statements } function_definition_list
%symbol { ast::program_p } program

%parameter { Lexer } lexer
%source { lexer. readtoken(); }
%rules

primary_expression
 => IDENTIFIER : id          { 
   auto res = ast::expr_p( new ast::identifier( id ) ); 
   return res;
  }
	| CONSTANT   : c           { return ast::expr_p( new ast::literal( c ) ); }
	| CHARLIT    : c           { return ast::expr_p( new ast::literal( c ) ); }
	| STRING_LITERAL : s       { return ast::expr_p( new ast::literal( s ) ); }
	| LPAR expression : e RPAR { return e; }
	;

postfix_expression
 => primary_expression: e { return e; }
	| postfix_expression: e LSQR expression: i RSQR { return ast::expr_p( new ast::array_access( e, i ) ); }
	| postfix_expression: e LPAR RPAR { return ast::expr_p( new ast::funccall( e ) ); }
	| postfix_expression: e LPAR argument_expression_list: a RPAR { return ast::expr_p( new ast::funccall( e, a ) ); }
	| postfix_expression: e DOT IDENTIFIER: i
  {
    auto id = ast::expr_p( new ast::identifier( i ) );
    return ast::expr_p( new ast::member_access( e, id ) );
  }
	| postfix_expression: e PTR_OP IDENTIFIER: i 
  {
    auto id = ast::expr_p( new ast::identifier( i ) );
    return ast::expr_p( new ast::ptr_memacc( e, id ) );
  }
	| postfix_expression: e INC_OP { return ast::expr_p( new ast::unary( "xpp", e ) ); }
	| postfix_expression: e DEC_OP { return ast::expr_p( new ast::unary( "xmm", e ) ); }
	;

argument_expression_list
 => assignment_expression: e 
  { 
    return ast::expressions({ e }); 
  }
	| argument_expression_list: l COMMA assignment_expression: e
  {
    auto new_l = l;
    new_l. push_back( e );
    return new_l;
  }
	;

unary_expression
 => postfix_expression: e { return e; }
	| INC_OP unary_expression: e { return ast::expr_p( new ast::unary( "ppx", e ) ); }
	| DEC_OP unary_expression: e { return ast::expr_p( new ast::unary( "mmx", e ) ); }
	| unary_operator: o cast_expression: e { return ast::expr_p( new ast::unary( o, e ) ); }
	| SIZEOF unary_expression: e { return ast::expr_p( new ast::unary( "sizeof", e ) ); }
	| SIZEOF LPAR type_name: tp RPAR { return ast::expr_p( new ast::szof( "sizeof", tp ) ); }
	;

unary_operator
 => AMP { return "&"; }
	| MUL { return "*"; }
	| ADD { return "+"; }
	| SUB { return "-"; }
	| NEG { return "~"; }
	| NOT { return "!"; }
	;

cast_expression
 => unary_expression : e { return e; }
	| LPAR type_name: tp RPAR cast_expression: e
  {
    return ast::expr_p( new ast::cast( tp, e ) );
  }
	;

multiplicative_expression
 => cast_expression : e { return e; }
	| multiplicative_expression: a MUL cast_expression: b { return ast::expr_p( new ast::binary( "*", a, b ) ); }
	| multiplicative_expression: a DIV cast_expression: b { return ast::expr_p( new ast::binary( "/", a, b ) ); }
	| multiplicative_expression: a MOD cast_expression: b { return ast::expr_p( new ast::binary( "%", a, b ) ); }
	;

additive_expression
 => multiplicative_expression : e { return e; }
	| additive_expression: a ADD multiplicative_expression: b { return ast::expr_p( new ast::binary( "+", a, b ) ); }
	| additive_expression: a SUB multiplicative_expression: b { return ast::expr_p( new ast::binary( "-", a, b ) ); }
	;

shift_expression
 => additive_expression: e { return e; }
	| shift_expression: a LEFT_OP additive_expression: b { return ast::expr_p( new ast::binary( "<<", a, b ) ); }
	| shift_expression: a RIGHT_OP additive_expression: b { return ast::expr_p( new ast::binary( ">>", a, b ) ); }
	;

relational_expression
 => shift_expression: e { return e; }
	| relational_expression: a LT_OP shift_expression: b { return ast::expr_p( new ast::binary( "<", a, b ) ); }
	| relational_expression: a GT_OP shift_expression: b { return ast::expr_p( new ast::binary( "<", b, a ) ); }
	| relational_expression: a LE_OP shift_expression: b { return ast::expr_p( new ast::binary( "<=", a, b ) ); }
	| relational_expression: a GE_OP shift_expression: b { return ast::expr_p( new ast::binary( "<=", b, a ) ); }
	;

equality_expression
 => relational_expression: e { return e; }
	| equality_expression: a EQ_OP relational_expression: b { return ast::expr_p( new ast::binary( "==", a, b ) ); }
	| equality_expression: a NE_OP relational_expression: b { return ast::expr_p( new ast::binary( "!=", a, b ) ); }
	;

and_expression
 => equality_expression: e { return e; }
	| and_expression: a AMP equality_expression: b { return ast::expr_p( new ast::binary( "&", a, b ) ); }
	;

exclusive_or_expression
 => and_expression: e { return e; }
	| exclusive_or_expression: a CARET and_expression: b { return ast::expr_p( new ast::binary( "^", a, b ) ); }
	;

inclusive_or_expression
 => exclusive_or_expression: e { return e; }
	| inclusive_or_expression: a PIPE exclusive_or_expression: b { return ast::expr_p( new ast::binary( "|", a, b ) ); }
	;

logical_and_expression
 => inclusive_or_expression: e { return e; }
	| logical_and_expression: a AND_OP inclusive_or_expression: b { return ast::expr_p( new ast::binary( "&&", a, b ) ); }
	;

logical_or_expression
 => logical_and_expression: e { return e; }
	| logical_or_expression: a OR_OP logical_and_expression: b { return ast::expr_p( new ast::binary( "||", a, b ) ); }
	;

conditional_expression
 => logical_or_expression: e { return e; }
	| logical_or_expression: e QUEST expression: t COLON conditional_expression: f { return ast::expr_p( new ast::ternary( e, t, f ) ); }
	;

assignment_expression
 => conditional_expression: e { return e; }
	| unary_expression: a assignment_operator: o assignment_expression: b
  {
    return ast::expr_p( new ast::binary( o, a, b ) );
  }
	;

assignment_operator
 => ASSIGN       { return "="  ; }
	| MUL_ASSIGN   { return "*=" ; }
	| DIV_ASSIGN   { return "/=" ; }
	| MOD_ASSIGN   { return "%=" ; }
	| ADD_ASSIGN   { return "+=" ; }
	| SUB_ASSIGN   { return "-=" ; }
	| LEFT_ASSIGN  { return "<<="; }
	| RIGHT_ASSIGN { return ">>="; }
	| AND_ASSIGN   { return "&=" ; }
	| XOR_ASSIGN   { return "^=" ; }
	| OR_ASSIGN    { return "|=" ; }
	;

expression
 => assignment_expression : e
  {
    return e;
  }
	| expression : e COMMA assignment_expression : ae
  {
    ast::expressions list;
    if( auto cast = dynamic_cast< ast::expr_list* >( e. get() ); cast != nullptr ){
      auto list = cast -> list;
      list. push_back( ae );
    } else {
      list = ast::expressions({ e, ae });
    }
    return ast::expr_p( new ast::expr_list( list ) );
  }
	;

constant_expression
 => conditional_expression : e { return e; }
	;

declaration
 => declaration_specifiers: sp SEMICOLON
  {
    return ast::decl_p( new ast::declarator( sp ) );
  }
	| declaration_specifiers: sp init_declarator_list: v SEMICOLON
  {
    std::vector< ast::stmt_p > t;
    std::transform( v. begin(), v. end(), std::back_inserter( t ), []( ast::decl_p x ){ return std::dynamic_pointer_cast< ast::stmt >( x ); } );
    return ast::decl_p( new ast::declarator( sp, ast::stmt_p( new ast::block( t ) ) ) );
  }
	;

declaration_specifiers
 => storage_class_specifier: x                                                    { return x; }
	| type_specifier         : x                                                    { return x; }
	| type_qualifier         : x                                                    { return x; }
	| storage_class_specifier: x declaration_specifiers: ds { x -> set_subtype( ds ); return x; }
	| type_specifier         : x declaration_specifiers: ds { x -> set_subtype( ds ); return x; }
	| type_qualifier         : x declaration_specifiers: ds { x -> set_subtype( ds ); return x; }
	;

init_declarator_list
 => init_declarator: d
  { 
    auto res = std::vector< ast::decl_p >({ d });
    auto str = std::accumulate( res. begin(), res. end(), std::string(""), []( std::string x, ast::decl_p p ) -> std::string { return x + p -> to_string( "" ); });
    return res;
  }
	| init_declarator_list: v COMMA init_declarator: d
  {
    v. push_back( d );
    return v;
  }
	;

init_declarator
 => declarator: d
  {
    return d;
  }
	| declarator: d ASSIGN initializer: i 
  {
    return ast::decl_p( new ast::declarator( d -> tp, d -> name, i ) );
  }
	;

storage_class_specifier
 => TYPEDEF { return ast::type_p( new ast::typedef_type () ); }
	| EXTERN  { return ast::type_p( new ast::extern_type  () ); }
	| STATIC  { return ast::type_p( new ast::static_type  () ); }
	| AUTO    { return ast::type_p( new ast::auto_type    () ); }
	| REGISTER{ return ast::type_p( new ast::register_type() ); }
	;

type_specifier
 => VOID     { return ast::type_p( new ast::void_type() ); }
	| CHAR     { return ast::type_p( new ast::char_type() ); }
	| SHORT    { return ast::type_p( new ast::short_type() ); }
	| INT      { return ast::type_p( new ast::int_type() ); }
	| LONG     { return ast::type_p( new ast::long_type() ); }
	| FLOAT    { return ast::type_p( new ast::float_type() ); }
	| DOUBLE   { return ast::type_p( new ast::double_type() ); }
	| SIGNED   { return ast::type_p( new ast::signed_type() ); }
	| UNSIGNED { return ast::type_p( new ast::unsigned_type() ); }
	| struct_or_union_specifier: e { return e; }
	| enum_specifier: e { return e; }
  | IDENTIFIER: i { return ast::type_p( new ast::id_type( i ) ); }
	| TYPE_NAME { std::cerr << "TYPE_NAME is not implemented!\n"; assert( false ); return ast::type_p(); }
	;

struct_or_union_specifier
 => struct_or_union: su IDENTIFIER: id LCUR struct_declaration_list: v RCUR
  {
    auto cast = dynamic_cast< ast::struct_or_union* >( su. get() );
    cast -> name = id;
    cast -> body = v;
    return su;
  }
	| struct_or_union: su LCUR struct_declaration_list: v RCUR
  {
    auto cast = dynamic_cast< ast::struct_or_union* >( su. get() );
    cast -> body = v;
    return su;
  }
	| struct_or_union: su IDENTIFIER: id 
  { 
    auto x = su; 
    if( auto cast = dynamic_cast< ast::struct_type* >( x. get() ); cast != nullptr ){
      return ast::type_p( new ast::struct_type( id ) );
    }
    if( auto cast = dynamic_cast< ast::union_type*  >( x. get() ); cast != nullptr ){
      return ast::type_p( new ast::union_type( id ) );
    }
    return ast::type_p(); // mustn't reach here
  }
	;

struct_or_union
 => STRUCT { return ast::type_p( new ast::struct_type() ); }
	| UNION  { return ast::type_p( new ast::union_type () ); }
	;

struct_declaration_list
 => struct_declaration: s
  {
    return std::vector< ast::decl_p >({ s });
  }
	| struct_declaration_list: v struct_declaration: s
  {
    v. push_back( s );
    return v;
  }
	;

struct_declaration
 => specifier_qualifier_list: t struct_declarator_list: sl SEMICOLON
  {
    std::vector< ast::stmt_p > v;
    std::transform( sl. begin(), sl. end(), std::back_inserter( v ), []( ast::decl_p x ){ return std::dynamic_pointer_cast< ast::stmt >( x ); } );
    return ast::decl_p( new ast::declarator( t, ast::stmt_p( new ast::block( v ) ) ) );
  }
	;

specifier_qualifier_list
 => type_specifier: ts specifier_qualifier_list: v
  {
    ts -> subtype = v;
    return ts;
  }
	| type_specifier: ts
  {
    return ts;
  }
	| type_qualifier: tq specifier_qualifier_list: v
  {
    tq -> subtype = v;
    return tq;
  }
	| type_qualifier: tq
  {
    return tq;
  }
	;

struct_declarator_list
 => struct_declarator: d
  {
    return std::vector< ast::decl_p >({ d });
  }
	| struct_declarator_list: v COMMA struct_declarator: d
  {
    v. push_back( d );
    return v;
  }
	;

struct_declarator
 => declarator: d
  {
    return d;
  }
	| COLON constant_expression: e
  {
    return ast::decl_p( new ast::declarator( e ) );
  }
	| declarator: d COLON constant_expression: e
  {
    return ast::decl_p( new ast::declarator( d -> tp, d -> name, e ) );
  }
	;

enum_specifier
 => ENUM LCUR enumerator_list: v RCUR
  {
    return ast::type_p( new ast::enum_type( v ) );
  }
	| ENUM IDENTIFIER: i LCUR enumerator_list: v RCUR
  {
    return ast::type_p( new ast::enum_type( i, v ) );
  }
	| ENUM IDENTIFIER: i
  {
    return ast::type_p( new ast::enum_type( i ) );
  }
	;

enumerator_list
 => enumerator: e
  {
    return ast::expressions({ e });
  }
	| enumerator_list: v COMMA enumerator: e
  {
    v. push_back( e );
    return v;
  }
	;

enumerator
 => IDENTIFIER: i
  {
    return ast::expr_p( new ast::identifier( i ) );
  }
	| IDENTIFIER: i ASSIGN constant_expression: e
  {
    return 
    ast::expr_p( new ast::binary( "=", ast::expr_p( new ast::identifier( i ) ), e ) );
  }
	;

type_qualifier
 => CONST    { return ast::type_p( new ast::const_type   () ); }
	| VOLATILE { return ast::type_p( new ast::volatile_type() ); }
	;

declarator
 => pointer: p direct_declarator: d
  {
    auto cur = p;
    auto cur_cast = dynamic_cast< ast::pointer* >( cur. get() );
    while( cur_cast != nullptr && cur_cast -> realtype != nullptr ){
      cur = cur_cast -> realtype;
      cur_cast = dynamic_cast< ast::pointer* >( cur. get() );
    }
    auto cast = dynamic_cast< ast::pointer* >( cur. get() );
    cast -> realtype = d -> tp;
    return d;
  }
	| direct_declarator: d
  {
    return d;
  }
	;

direct_declarator
 => IDENTIFIER: id 
  { 
    //return std::make_pair( ast::type_p( nullptr ), ast::expr_p( new ast::identifier( id ) ) );
    return ast::decl_p( new ast::declarator( id ) );
  }
	| LPAR declarator: d RPAR
  {
    return d;
  }
	| direct_declarator: d LSQR constant_expression: e RSQR
  {
    auto tp = d -> tp;
    while( tp -> subtype != nullptr ){ tp = tp -> subtype; }
    tp -> subtype = ast::type_p( new ast::array_type( e ) );
    return d;
  }
	| direct_declarator: d LSQR RSQR
  {
    auto tp = d -> tp;
    while( tp -> subtype != nullptr ){ tp = tp -> subtype; }
    tp -> subtype = ast::type_p( new ast::array_type() );
    return d;
  }
	| direct_declarator: d LPAR parametertype_p_list: v RPAR
  {
    auto tp = ast::type_p( new ast::func_type( d -> tp, v ) );
    d -> tp = tp;
    return d;
  }
	| direct_declarator: d LPAR identifier_list: v RPAR
  {
    auto tp = ast::type_p( new ast::func_type( d -> tp, v ) );
    d -> tp = tp;
    return d;
  }
	| direct_declarator: d LPAR RPAR
  {
    auto tp = ast::type_p( new ast::func_type( d -> tp ) );
    d -> tp = tp;
    return d;
  }
	;

pointer
 => MUL
  {
    return ast::type_p( new ast::pointer() );
  }
	| MUL type_qualifier_list: v
  {
    return ast::type_p( new ast::pointer( v ) );
  }
	| MUL pointer: p
  {
    return ast::type_p( new ast::pointer( p ) );
  }
	| MUL type_qualifier_list: v pointer: p
  {
    auto cur = v;
    while( cur -> subtype. get() != nullptr ) cur = cur -> subtype;
    cur -> subtype = p;
    return ast::type_p( new ast::pointer( v ) );
  }
	;

type_qualifier_list
	=> type_qualifier: tq
  {
    return tq;
  }
	| type_qualifier_list: v type_qualifier: tq
  {
    auto cur = v;
    while( cur -> subtype. get() != nullptr ) cur = cur -> subtype;
    cur -> subtype = tq;
    return v;
  }
	;


parametertype_p_list
 => parameter_list: v
  {
    return v;
  }
	| parameter_list: v COMMA ELLIPSIS
  {
    v. push_back( ast::decl_p( new ast::declarator( ast::type_p( new ast::variadic_type() ) , "..." ) ) );
    return v;
  }
	;

parameter_list
 => parameter_declaration: p
  {
    return std::vector< ast::decl_p >({ p });
  }
	| parameter_list: v COMMA parameter_declaration: p
  {
    v. push_back( p );
    return v;
  }
	;

parameter_declaration
 => declaration_specifiers: sp declarator: d
  {
    auto tp = d -> tp;
    auto cur = sp;
    while( cur != nullptr && cur -> subtype != nullptr ){ 
      cur = cur -> subtype; 
    }
    cur -> subtype = d -> tp;
    d -> tp = sp;
    return d;
  }
	| declaration_specifiers: sp abstract_declarator: a
  {
    auto tp = a -> tp;
    auto cur = sp;
    while( cur != nullptr && cur -> subtype != nullptr ){ cur = cur -> subtype; }
    cur -> subtype = a -> tp;
    a -> tp = sp;
    return a;
  }
	| declaration_specifiers: sp
  {
    return ast::decl_p( new ast::declarator( sp , "" ) );
  }
	;

identifier_list
 => IDENTIFIER: i
  {
    std::vector< ast::decl_p > v{ ast::decl_p( new ast::declarator( i ) ) };
    return v;
  }
	| identifier_list: v COMMA IDENTIFIER: i
  {
    v. push_back( ast::decl_p( new ast::declarator( i ) ) );
    return v;
  }
	;

type_name
 => specifier_qualifier_list: tp 
  { 
    return tp; 
  }
	| specifier_qualifier_list: x abstract_declarator: a
  {
    ast::type_p cur = x;
    while( cur -> subtype != nullptr ){ cur = cur -> subtype; }
    cur -> subtype = a -> tp;
    a -> tp = x;
    return x;
  }
	;

abstract_declarator
 => pointer: p
  {
    return ast::decl_p( new ast::declarator( p, "" ) );
  }
	| direct_abstract_declarator: d
  {
    return d;
  }
	| pointer: p direct_abstract_declarator: d
  {
    auto cur = p;
    while( cur != nullptr ) cur = cur -> subtype;
    cur -> subtype = d -> tp;
    d -> tp = p;
    return d;
  }
	;

direct_abstract_declarator
 => LPAR abstract_declarator: a RPAR
  {
    return a;
  }
	| LSQR RSQR
  {
    return ast::decl_p( new ast::declarator( ast::type_p( new ast::array_type( ) ) ) );
  }
	| LSQR constant_expression: e RSQR
  {
    return ast::decl_p( new ast::declarator( ast::type_p( new ast::array_type( e ) ) ) );
  }
	| direct_abstract_declarator: a LSQR RSQR
  {
    auto tp = a -> tp;
    while( tp != nullptr ){ tp = tp -> subtype; }
    tp -> subtype = ast::type_p( new ast::array_type( ) );
    return a;
  }
	| direct_abstract_declarator: a LSQR constant_expression: e RSQR
  {
    auto tp = a -> tp;
    while( tp != nullptr ){ tp = tp -> subtype; }
    tp -> subtype = ast::type_p( new ast::array_type( e ) );
    return a;
  }
	| LPAR RPAR
  {
    return ast::decl_p( new ast::declarator( ast::type_p( new ast::func_type() ) ) );
  }
	| LPAR parametertype_p_list: v RPAR
  {
    return ast::decl_p( new ast::declarator( ast::type_p( new ast::func_type( v ) ) ) );
  }
	| direct_abstract_declarator: d LPAR RPAR
  {
    return ast::decl_p( new ast::declarator( ast::type_p( new ast::func_type( d -> tp ) ) ) );
  }
	| direct_abstract_declarator: d LPAR parametertype_p_list: v RPAR
  {
    return ast::decl_p( new ast::declarator( ast::type_p( new ast::func_type( d -> tp, v ) ) ) );
  }
	;

initializer
 => assignment_expression: e
  {
    return e;
  }
	| LCUR initializer_list: il RCUR
  {
    return il;
  }
	| LCUR initializer_list: il COMMA RCUR
  {
    return il;
  }
	;

initializer_list
 => initializer : x
  {
    return ast::expr_p( new ast::initializer_list({ x }) );
  }
	| initializer_list: il COMMA initializer: i
  {
    if( auto cast = dynamic_cast< ast::initializer_list* >( il. get() ); cast != nullptr ){
      cast -> vals. push_back( i );
    }
    return il;
  }
	;

statement
 => labeled_statement : s    { return s; }
	| compound_statement : c   { 
    auto res = ast::stmt_p( new ast::block( c ) );
    return res;
  }
	| expression_statement : e { return e; }
	| selection_statement : s  { return s; }
	| iteration_statement : i  { return i; }
	| jump_statement : j       { 
    return j; 
  }
	;

labeled_statement
 => IDENTIFIER: id COLON statement: s 
  { 
    return ast::stmt_p( new ast::label( id, s ) ); 
  }
	| CASE constant_expression: e COLON statement: s 
  { 
    return ast::stmt_p( new ast::case_arm( e, s ) ); 
  }
	| DEFAULT COLON statement: s 
  { 
    return ast::stmt_p( new ast::case_arm( ast::expr_p( new ast::none() ), s ) ); 
  }
	;

compound_statement
 => LCUR RCUR
  {
    return ast::statements();
  }
	| LCUR statement_list : s RCUR
  {
    return s;
  }
	| LCUR declaration_list: d RCUR
  {
    return d;
  }
	| LCUR declaration_list: d statement_list: s RCUR
  {
    for( auto x : s ){ d. push_back( x ); }
    return d;
  }
	;

declaration_list
 => declaration: d
  {
    return ast::statements({ d });
  }
	| declaration_list: v declaration: d
  {
    v. push_back( d );
    return v;
  }
	;

statement_list
 => statement : s 
  { 
    return ast::statements({ s }); 
  }
	| statement_list: l statement: s
  {
    auto new_list = l;
    new_list. push_back( s );
    return new_list;
  }
	;

expression_statement
 => SEMICOLON 
  { 
    return ast::stmt_p( new ast::none() ); 
  }
	| expression: e SEMICOLON 
  { 
    return e; 
  }
	;

selection_statement
 => IF LPAR expression: c RPAR statement: s
  %requires
  {
    if( !lookahead ) { return true; }
    auto x = (*lookahead);
    return x. type != sym_ELSE;
  }
  %reduces
  {
    return ast::stmt_p( new ast::if_else( c, s ) );
  }
  | IF LPAR expression: c RPAR statement: t ELSE statement: f
  %reduces
  {
    auto res = ast::stmt_p( new ast::if_else( c, t, f ) );
    return res;
  }
	| SWITCH LPAR expression: c RPAR statement: s
  {
    return ast::stmt_p( new ast::swtch( c, s ) );
  }
	;

iteration_statement
 => WHILE LPAR expression : e RPAR statement : ss
  {
    ast::block_p new_ss = std::dynamic_pointer_cast< ast::block >( ss );
    return ast::stmt_p( new ast::whileloop( e, new_ss ) );
  }
	| DO statement : ss WHILE LPAR expression : e RPAR SEMICOLON
  {
    ast::block_p new_ss = std::dynamic_pointer_cast< ast::block >( ss );
    return ast::stmt_p( new ast::do_while( e, new_ss ) );
  }
	| FOR LPAR expression_statement : i expression_statement : c RPAR statement : ss
  {
    ast::expr_p new_c = std::dynamic_pointer_cast< ast::expr >( c );
    ast::block_p new_ss = std::dynamic_pointer_cast< ast::block >( ss );
    return ast::stmt_p( new ast::forloop( i, new_c, ast::expr_p( new ast::none() ), new_ss ) );
  }
	| FOR LPAR expression_statement : i expression_statement : c expression : s RPAR statement : ss
  {
    ast::expr_p new_c = std::dynamic_pointer_cast< ast::expr >( c );
    ast::block_p new_ss = std::dynamic_pointer_cast< ast::block >( ss );
    return ast::stmt_p( new ast::forloop( i, new_c, s, new_ss ) );
  }
	;

jump_statement
 => GOTO IDENTIFIER: id SEMICOLON
  {
    return ast::stmt_p( new ast::go_to( id ) );
  }
	| CONTINUE SEMICOLON
  {
    return ast::stmt_p( new ast::cont() );
  }
	| BREAK SEMICOLON
  {
    return ast::stmt_p( new ast::brk() );
  }
	| RETURN SEMICOLON
  {
    return ast::stmt_p( new ast::ret( ast::expr_p( new ast::none() ) ) );
  }
	| RETURN expression: e SEMICOLON
  {
    return ast::stmt_p( new ast::ret( e ) );
  }
	;

external_declaration
 => function_definition: f
  {
    return f;
  }
	| declaration: d
  {
    return d;
  }
	;

function_definition
 => declaration_specifiers: ds declarator: d declaration_list: dl compound_statement: cs
  {
    for( auto x : cs ){ dl. push_back( x ); }
    return ast::stmt_p( new ast::funcdef( ds, d, dl ) );
  }
	| declaration_specifiers: ds declarator: d compound_statement: cs
  {
    return ast::stmt_p( new ast::funcdef( ds, d, cs ) );
  }
	| declarator: d declaration_list: dl compound_statement: cs
  {
    for( auto x : cs ){ dl. push_back( x ); }
    return ast::stmt_p( new ast::funcdef( d, dl ) );
  }
	| declarator: d compound_statement: cs 
  {
    return ast::stmt_p( new ast::funcdef( d, cs ) );
  }
	;

function_definition_list 
 => function_definition_list: l function_definition: f 
  { 
    auto new_list = l;
    new_list. push_back( f );
    return new_list;
  }
  | function_definition : f { return ast::statements({ f }); }
  ;

program
 => external_declaration: d
  {
    return ast::program_p( new ast::program({ d }) );
  }
	| program: p external_declaration: d
  {
    p -> add_decl( d );
    return p;
  }
  ;
