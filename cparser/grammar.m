%symbolcode_h { #include "interval.h" }
%symbolcode_h { #include "baseType.h" }
%symbolcode_h { #include "baseTree.h" }
%symbolcode_h { #include "program.h" }
%symbolcode_h { #include "functStore.h" }
%symbolcode_cpp { void print_attr( const tree::Tree tree, std::ostream& out ) { out<<" "<<*tree<<" "; } }

%parsercode_h { #include "baseType.h" }
%parsercode_h { #include "baseTree.h" }
%parsercode_h { #include "undeclaredError.h" }

%parameter { program::Program() } programData
%parameter { program::FuncStore() } fucntData

%symbol { tree::Tree } DEC_LIT OCT_LIT HEX_LIT DOUBLE_LIT CHAR_LIT IDENTIFIER

%symbol {} VOID CHAR INT FLOAT DOUBLE STRUCT ENUM UNION
%symbol {} SHORT LONG SIGNED UNSIGNED
%symbol {} AUTO EXTERN STATIC REGISTER TYPEDEF 
%symbol {} CONST VOLATILE
%symbol { type::Type } TYPE_NAME
%symbol { type::Type } Type Type2 Type3

%symbol {} ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN
%symbol {} ADD SUB MUL DIV MOD PIPE CARET AMP NOT NEG QUEST RIGHT_OP LEFT_OP PTR_OP
%symbol {} LPAR RPAR LCUR RCUR LSQR RSQR COLON SEMICOLON COMMA DOT ELLIPSIS
%symbol {} EQ_OP NE_OP LT_OP GT_OP LE_OP GE_OP AND_OP OR_OP INC_OP DEC_OP
%symbol {} IF ELSE FOR DO WHILE GOTO CONTINUE BREAK SWITCH CASE SIZEOF RETURN

%symbol { tree::Tree } primary_expression postfix_expression argument_expression_list 
%symbol { tree::Tree } unary_expression cast_expression multiplicative_expression additive_expression shift_expression
%symbol { tree::Tree } relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression
%symbol { tree::Tree } logical_and_expression logical_or_expression conditional_expression assignment_expression expression constant_expression

%symbol { std::vector<tree::Tree> } expression_list init_declarator_list identifier_list

%symbol { program::FieldArray } field_list 
%symbol { program::FieldArray::Field} parameter_declaration

%symbol {} DEFAULT COMMENTS SPACE ERROR EOF
%startsymbol program EOF

%rules

primary_expression => IDENTIFIER:ident
    { return ident; }
    | DEC_LIT:dec
    { return dec; }
    | OCT_LIT:oct
    { return oct; }
    | HEX_LIT:hex
    { return hex; }
    | CHAR_LIT:chr
    { return chr; }
    | DOUBLE_LIT:dbl
    { return dbl; }
    ;

postfix_expression => primary_expression:
    { return e; }
    | primary_expression:arr LSQR expression:i RSQR
    %requires
    { return arr.try_cast<tree::Identifier>() != nullptr; }
    %reduces
    { return tree::access_(arr->id, i); }
    | postfix_expression:func LPAR RPAR
    %requires
    { return func.try_cast<tree::Identifier>() != nullptr; }
    %reduces
    { return tree::apply_(func->id,{}); }
    | postfix_expression:func LPAR argument_expression_list:param RPAR
    %requires
    { return func.try_cast<tree::Identifier>() != nullptr; }
    %reduces
    { return tree::apply_(func->id, param); }
    | postfix_expression:e DOT IDENTIFIER:field
    %requires
    { return e.try_cast<tree::Identifier>() != nullptr; }
    %reduces
    { return tree::select_(e, field->id); }
    | postfix_expression:e PTR_OP IDENTIFIER:field
    %requires
    { return e.try_cast<tree::Identifier>() != nullptr; }
    %reduces
    { return tree::select_(tree::apply_("*", {e}), field->id); }
    | postfix_expression: e INC_OP
    %requires
    { return e->lr == 'L'; }
    %reduces
    { return tree::apply_("[xpp]", {e}); }
    | postfix_expression: e DEC_OP
    %requires
    { return e->lr == 'L'; }
    %reduces
    { return tree::apply_("[xmm]", {e}); }
    ;

argument_expression_list => assignment_expression:e
    { return program::FieldArray({e}); }
    | argument_expression_list:l COMMA assignment_expression:e
    { return l.add(e); }
    ;

unary_expression => postfix_expression:e
    { return e; }
    | INC_OP unary_expression:e
    { return tree::apply_("[ppx]", {e}); }
    | DEC_OP unary_expression:e
    { return tree::apply_("[mmx]", {e}); }
    | AMP cast_expression:e
    { return tree::apply_("[ref]", {e}); }
    | MUL cast_expression:e
    { return tree::apply_("[deref]", {e}); }
    | ADD cast_expression:e
    { return tree::apply_("[add]", {e}); }
    | SUB cast_expression:e
    { return tree::apply_("[sub]", {e}); }
    | NEG cast_expression:e
    { return tree::apply_("[neg]", {e}); }
    | NOT cast_expression:e
    { return tree::apply_("[not]", {e}); }
    | SIZEOF unary_expression:e
    { return tree::apply_("[sizeof]", {e}); }
    | SIZEOF LPAR type_name:tp RPAR
    { return tree::apply_("[sizeof]", {tp}); }
    ;

cast_expression => unary_expression:e
    { return e; }
    | LPAR type_name:tp RPAR cast_expression:e
    { return tree::apply_("[cast]",{e, tp}); }
    ;

multiplicative_expression => cast_expression:e
    { return e; }
    | multiplicative_expression:a MUL cast_expression:b
    { return tree::apply_("[mul]", {a, b}); }
    | multiplicative_expression:a DIV cast_expression:b
    { return tree::apply_("[div]", {a, b}); }
    | multiplicative_expression:a MOD cast_expression:b
    { return tree::apply_("[mod]", {a, b}); }
    ;

additive_expression => multiplicative_expression:e
    { return e; }
    | additive_expression:a ADD multiplicative_expression:b
    { return tree::apply_("[add]", {a, b}); }
    | additive_expression:a SUB multiplicative_expression:b
    { return tree::apply_("[sub]", {a, b}); }
    ;

shift_expression => additive_expression:e
    { return e; }
    | shift_expression:a LEFT_OP additive_expression:b
    { return tree::apply_("[sl]", {a, b}); }
    | shift_expression:a RIGHT_OP additive_expression:b
    { return tree::apply_("[sr]", {a, b}); }
    ;

relational_expression => shift_expression:e
    { return e; }
    | relational_expression:a LT_OP shift_expression:b
    { return tree::apply_("[lt]", {a, b}); }
    | relational_expression:a GT_OP shift_expression:b
    { return tree::apply_("[gt]", {a, b}); }
    | relational_expression:a LE_OP shift_expression:b
    { return tree::apply_("[le]", {a, b}); }
    | relational_expression:a GE_OP shift_expression:b
    { return tree::apply_("[ge]", {a, b}); }
    ;

equality_expression => relational_expression:e
    { return e; }
    | equality_expression:a EQ_OP relational_expression:b
    { return tree::apply_("[eq]", {a, b}); }
    | equality_expression:a NE_OP relational_expression:b
    { return tree::apply_("[ne]", {a, b}); }
    ;

and_expression => equality_expression:e
    { return e; }
    | and_expression:a AMP equality_expression:b
    { return tree::apply_("&", {a, b}); }
    ;

exclusive_or_expression => and_expression:e
    { return e; }
    | exclusive_or_expression:a CARET and_expression:b
    { return tree::apply_("^", {a, b}); }
    ;

inclusive_or_expression => exclusive_or_expression:e
    { return e; }
    | inclusive_or_expression:a PIPE exclusive_or_expression:b
    { return tree::apply_("|", {a, b}); }
    ;

logical_and_expression => inclusive_or_expression:e
    { return e; }
    | logical_and_expression:a AND_OP inclusive_or_expression:b
    { return tree::apply_("[and]", {a, b}); }
    ;

logical_or_expression => logical_and_expression:e
    { return e; }
    | logical_or_expression:a OR_OP logical_and_expression:b
    { return tree::apply_("[or]", {a, b}); }
    ;

conditional_expression => logical_or_expression:e
    { return e; }
    | logical_or_expression:cond QUEST expression:yes COLON conditional_expression:no
    { return tree::apply_("??", {cond, yes, no}); }
    ;

assignment_expression => conditional_expression:e
    { return e; }
    | unary_expression:left ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("=", {left, right}); }
    | unary_expression:left MUL_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("*=", {left, right}); }
    | unary_expression:left DIV_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("/=", {left, right}); }
    | unary_expression:left MOD_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("%=", {left, right}); }
    | unary_expression:left ADD_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("+=", {left, right}); }
    | unary_expression:left SUB_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("-=", {left, right}); }
    | unary_expression:left LEFT_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("<<=", {left, right}); }
    | unary_expression:left RIGHT_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_(">>=", {left, right}); }
    | unary_expression:left AND_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("&=", {left, right}); }
    | unary_expression:left XOR_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("^=", {left, right}); }
    | unary_expression:left OR_ASSIGN assignment_expression:right
    %requires
    { return left->lr == 'L'; }
    %reduces
    { return tree::apply_("|=", {left, right}); }
    ;

expression => assignment_expression:e
    { return e; }
    ;

expression_list => expression:e
    { 
        std::vector<tree::Tree>* list = new std::vector<tree::Tree>();
        list->push_back(e);
        return *list
    }
    | expression_list:list COMMA expression:e
    {
        list.push_back(e);
        return list;
    }
    ;

constant_expression => conditional_expression:e
    { return e; }
    ;

declaration => TYPEDEF Type:tp IDENTIFIER:alias SEMICOLON
    %requires
    { return programData.typedefs.find(alias->id) == programData.typedefs.end(); }
    %reduces
    { if( programData.typedefs.find(alias->id) != programData.typedefs.end()) 
         throw 
       programData.typedefs.insert(alais->id, tp); }
    | Type:tp init_declarator_list:list SEMICOLON
    {/*???????????????????*/}
    ;

init_declarator_list => init_declarator:idec
    {
        std::vector<tree::Tree> = { idec }; 
        return list;
    }
    | init_declarator_list:list COMMA init_declarator:idec
    {
        list.push_back(idec);
        return list;
    }
    ;

init_declarator => declarator:dec
    { return dec; }
    | declarator:dec ASSIGN initializer:init
    { return dec; /*???????????????????????????????? how to store the initialization value.*/ }
    ;

declarator => declarator2:dec
    | LPAR declarator:dec RPAR
    { return dec; }
    | MUL declarator:dec
    {
        dec->type = type::pointer_(dec->type);
        return dec;
    }
    | MUL CONST declarator:dec
    {
        /*how const should affect the dec ???*/
        dec->type = type::pointer_(dec->type);
        return dec;
    }
    | MUL VOLATILE declarator:dec
    {
        /*how volatile should affect the dec ???*/
        dec->type = type::pointer_(dec->type);
        return dec;
    }

declarator2 => IDENTIFIER:ident
    { return ident; }
    | declarator2:dec LSQR constant_expression:e RSQR
    {
        dec->type = type::array_(e.try_cast<tree::Integer>()->i, dec->type);
        return dec;
    }
    | declarator2:dec LSQR RSQR
    {
        dec->type = type::array_(0, dec->type);
        return dec;    
    }
    | declarator2:dec LPAR parametertype_p_list:param RPAR
    %requires
    { return dec.try->cast<tree::Identifier>() != nullptr && fucntData.contains(dec.try->cast<tree::Identifier>()->id) == false; }
    %reduces
    {
        fucntData.insert(dec.try_cast<tree::Identifier>()->id, program::FuncStore::Functdef(param, nullptr, nullptr));
        return dec;
    }
    | declarator2:dec LPAR identifier_list:args RPAR
    {/*?????????????????*/}
    | declarator2:d LPAR RPAR
    {/*?????????????????*/}
    ;

parametertype_p_list => parameter_list:list
    { return list; }
    | parameter_list:list COMMA ELLIPSIS
    {/*?????????????????*/}
    ;

parameter_list => parameter_declaration:field
    { return program::FieldArray({p}); }
    | parameter_list:fields COMMA parameter_declaration:field
    { fields.add(field); return fields; }
    ;

parameter_declaration => Type:tp declarator:dec
    {
        if(fucntData.contains(dec.try_cast<tree::Identifier>()->id)) fucntData.find(dec.try_cast<tree::Identifier>()->id)->returnType = tp;
        else if(dec->type.try_cast<type::Array>() != nullptr) dec->type->type = tp;
        else dec->type = tp;
        return program::FieldArray::Field(dec.try_cast<tree::Identifier>()->id, tp);
    }
    | Type:tp abstract_declarator:adec
    {/*???????????????*/}
    | Type:tp
    { return program::FieldArray::Field(" ", tp); }
    ;

identifier_list => IDENTIFIER:ident
    {
        std::vector<tree::Tree>* list = new std::vector<tree::Tree>();
        list.push_back(ident);
        return list; 
    }
    | identifier_list:list COMMA IDENTIFIER:ident
    {
        list.push_back(ident);
        return list;
    }
    ;

Type =>  Type2:tp
    { return tp; }
    | AUTO  Type2:tp
    { return tp; }
    | STATIC  Type2:tp
    { return storageModifier::static_(tp); }
    | EXTERN  Type2:tp
    { return storageModifier::extern_(tp); }
    | REGISTER  Type2:tp
    { return storageModifier::register_(tp); }
    ;

Type2 => Type3:tp
    { return tp; }
    | SHORT Type3:tp
    { return typeModifier::short_(tp); }
    | LONG Type3:tp
    { return typeModifier::long_(tp); }
    | LONG LONG Type3:tp
    { return typeModifier::long_(typeModifier::long_(tp)); }
    | SIGNED Type3:tp
    { return typeModifier::signed_(tp); }
    | UNSIGNED Type3:tp
    { return typeModifier::unsigned_(tp); }
    ;

Type3 => VOID
    { return type::void_(); }
    | CHAR
    { return type::char_(); }
    | SHORT
    { return typeModifier::short_(type::integer_()); }
    | INT
    { return type::integer_(); }
    | LONG
    { return typeModifier::long_(type::integer_()); }
    | FLOAT
    { return type::float_(); }
    | DOUBLE
    { return type::double_(); }
    | struct_specifier:e
    | union_specifier:e
    | enum_specifier:e
    | IDENTIFIER:ident
    %requires
    { return programData.typedefs.find(ident->id) != programData.typedefs.end(); }
    %reduces
    { return type::alais_(ident->id);}
    ;

struct_specifier => STRUCT IDENTIFIER:name LCUR field_list:fields RCUR
    %requires
    { return programData.structdefs.find(name->id) == programData.structdefs.end(); }
    %reduces
    {
        programData.structdefs.insert(name->id, fields);
        return type::struct_(name->id);
    }
    | STRUCT LCUR field_list:fields RCUR
    {
        programData.structdefs.insert(" ", fields);
        return type::struct_(" ");
    }
    | STRUCT IDENTIFIER:name
    %requires
    { return programData.structdefs.find(name->id) == programData.structdefs.end(); }
    %reduces
    {
        program::FieldArray* fields = new program::FieldArray();
        programData.structdefs.insert(name->id, *fields);
        return type::struct_(name->id);
    }
    ;

union_specifier => UNION IDENTIFIER:name LCUR field_list:fields RCUR
    %requires
    { return programData.uniondefs.find(name->id) == programData.uniondefs.end(); }
    %reduces
    {
        programData.uniondefs.insert(name->id, fields);
        return type::union_(name->id);
    }
    | UNION LCUR field_list:fields RCUR
    {
        programData.uniondefs.insert(" ", fields);
        return type::union_(" ");
    }
    | UNION IDENTIFIER:type_name
    %requires
    { return programData.uniondefs.find(name->id) == programData.uniondefs.end(); }
    %reduces
    {
        program::FieldArray* fields = new program::FieldArray();
        programData.uniondefs.insert(name->id, *fields);
        return type::union_(name->id);
    }
    ;

field => .....................
    { return program::FieldArray::Field(name->id, tp); }
    ;

field_list => field:f
    { return program::FieldArray({f});}
    | field_list:list field:f
    {
        list.add(f);
        return list;
    }
    ;
-----------------------------------------------------------------------------------------------------------------------------

direct_declarator => IDENTIFIER:ident
    | direct_declarator:d LSQR constant_expression:e RSQR
    | direct_declarator:d LSQR RSQR
    | direct_declarator: d LPAR parametertype_p_list: v RPAR
    | direct_declarator: d LPAR identifier_list: v RPAR
    | direct_declarator: d LPAR RPAR
    ;

type_qualifier_list => type_qualifier:q
    | type_qualifier_list:list COMMA type_qualifier:q
    ;

pointer => MUL
    | MUL type_qualifier_list:q
    | MUL type_qualifier_list:q pointer:p
    ;

declarator => pointer:p direct_declarator:d
    | direct_declarator:d
    | LPAR declarator:dec RPAR
    ;



