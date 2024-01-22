%locations
%define parse.error verbose
%{
    #define YYSTYPE tree_node*
    #include<stdio.h>
    
    #include "syntax_tree.h"
    #include "syntax_check_update.h"
    #include "lex.yy.c"
    #include "flex.h"
    #include "parser.tab.h"
    
    #define ERROR_MSG(line, msg, errrul) if(errname>0){\
        fprintf(stdout, " |~~%s (rule %d at line %d)~~|.\n",msg, errrul, line);\
        errname=0;\
        }
    #define ERROR_OK(line, msg, errrul) if(errname>0){\
        fprintf(stdout, " |~~%s (rule %d at line %d)~~|.\n",msg, errrul, line);\
        errname=0;\
        yyerrok;\
        }
    #define TREE_ACTIONS1(EXPNAME, out, loc, e1) out=make_line_node(EXPNAME, loc.first_line);add_node(out, e1);
    #define TREE_ACTIONS2(EXPNAME, out, loc, e1, e2) \
        TREE_ACTIONS1(EXPNAME, out, loc, e1)\
        add_node(out, e2); 
    #define TREE_ACTIONS3(EXPNAME, out, loc, e1, e2, e3) \
        TREE_ACTIONS2(EXPNAME, out, loc, e1, e2)\
        add_node(out, e3);
    #define TREE_ACTIONS4(EXPNAME, out, loc, e1, e2, e3, e4) \
        TREE_ACTIONS3(EXPNAME, out, loc, e1, e2, e3)\
        add_node(out, e4); 
    #define TREE_ACTIONS5(EXPNAME, out, loc, e1, e2, e3, e4, e5) \
        TREE_ACTIONS4(EXPNAME, out, loc, e1, e2, e3, e4)\
        add_node(out, e5);
    #define TREE_ACTIONS6(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6) \
        TREE_ACTIONS5(EXPNAME, out, loc, e1, e2, e3, e4, e5)\
        add_node(out, e6); 
    #define TREE_ACTIONS7(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6, e7) \
        TREE_ACTIONS6(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6)\
        add_node(out, e7);

    #define EXP_ACTIONS1(EXPNAME, out, loc, e1) \
        TREE_ACTIONS1(EXPNAME, out, loc, e1)\
        update_tree(out);
    #define EXP_ACTIONS2(EXPNAME, out, loc, e1, e2) \
        TREE_ACTIONS2(EXPNAME, out, loc, e1, e2)\
        update_tree(out);
    #define EXP_ACTIONS3(EXPNAME, out, loc, e1, e2, e3) \
        TREE_ACTIONS3(EXPNAME, out, loc, e1, e2, e3)\
        update_tree(out);
    #define EXP_ACTIONS4(EXPNAME, out, loc, e1, e2, e3, e4) \
        TREE_ACTIONS4(EXPNAME, out, loc, e1, e2, e3, e4)\
        update_tree(out);
    #define EXP_ACTIONS5(EXPNAME, out, loc, e1, e2, e3, e4, e5) \
        TREE_ACTIONS5(EXPNAME, out, loc, e1, e2, e3, e4, e5)\
        update_tree(out);
    #define EXP_ACTIONS6(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6) \
        TREE_ACTIONS6(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6)\
        update_tree(out);
    #define EXP_ACTIONS7(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6, e7) \
        TREE_ACTIONS7(EXPNAME, out, loc, e1, e2, e3, e4, e5, e6, e7)\
        update_tree(out);

    void yyerror(const char* msg);
    int errname=0;
    
%}
%token SEMI//;
%token COMMA//,
%token ASSIGN//=
%token RELGT//>
%token RELLT//<
%token RELGE//>=
%token RELLE//<=
%token RELEQ//==
%token RELNE//!=
%token PLUS//+
%token MINUS//-
%token STAR//*
%token DIV// /
%token AND//&&
%token OR//||
%token DOT//.
%token NOT//!
%token ITYPE//int
%token FTYPE//float
%token LP//(
%token RP//)
%token LB//[
%token RB//]
%token LC//{
%token RC//}
%token STRUCT//struct
%token RETURN//return
%token IF//if
%token ELSE//else
%token WHILE//while
%token INT//int num
%token FLOAT//float num
%token ID
%token REL
%token TYPE

%right ASSIGN
%left OR
%left AND
%left REL
%left PLUS MINUS
%left STAR DIV
%right NOT UMINUS 
%left LP RP LB RB DOT
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%
Program : ExtDefList {EXP_ACTIONS1("Program", $$, @$, $1) add_node(NULL, $$);}
        ;
ExtDefList : {$$=NULL;}
        | ExtDef ExtDefList {EXP_ACTIONS2("ExtDefList", $$, @$, $1, $2)}
        ;
ExtDef : Specifier ExtDecList SEMI {EXP_ACTIONS3("ExtDef", $$, @$, $1, $2, $3)}
        | Specifier SEMI {EXP_ACTIONS2("ExtDef", $$, @$, $1, $2)}
        | Specifier FunDec CompSt {EXP_ACTIONS3("ExtDef", $$, @$, $1, $2, $3)}
        | error SEMI {ERROR_OK(@1.first_line,"ExtDef err", 92)}
        | Specifier error {ERROR_OK(@2.first_line,"ExtDef ;?", 93)}
        ;
ExtDecList : VarDec {EXP_ACTIONS1("ExtDecList", $$, @$, $1)}
        | VarDec COMMA ExtDecList {EXP_ACTIONS3("ExtDecList", $$, @$, $1, $2, $3)}
        | VarDec error {ERROR_OK(@2.first_line,"ExtDecList err", 97)}
        ;

Specifier : TYPE {EXP_ACTIONS1("Specifier", $$, @$, $1)}
        | StructSpecifier {EXP_ACTIONS1("Specifier", $$, @$, $1)}
        ;
StructSpecifier : STRUCT OptTag LC DefList RC {EXP_ACTIONS5("StructSpecifier", $$, @$, $1, $2, $3, $4, $5)}
        | STRUCT Tag {EXP_ACTIONS2("StructSpecifier", $$, @$, $1, $2)}
        | STRUCT OptTag LC error RC {ERROR_OK(@4.first_line,"stru ", 106)}
        ;
OptTag : {$$=NULL;}
        | ID {EXP_ACTIONS1("OptTag", $$, @$, $1)}
        ;
Tag : ID {EXP_ACTIONS1("Tag", $$, @$, $1)}

VarDec : ID {EXP_ACTIONS1("VarDec", $$, @$, $1)}
        | VarDec LB INT RB {EXP_ACTIONS4("VarDec", $$, @$, $1, $2, $3, $4)}
        | VarDec LB error RB {ERROR_MSG(@3.first_line,"VarDec err", 114)}
        | VarDec LB error {ERROR_MSG(@3.first_line,"VarDec ]?", 115)}
        ;
FunDec : ID LP VarList RP {EXP_ACTIONS4("FunDec", $$, @$, $1, $2, $3, $4)}
        | ID LP RP {EXP_ACTIONS3("FunDec", $$, @$, $1, $2, $3)}
        | ID LP error RP {ERROR_MSG(@3.first_line,"FunDec var-err ", 118)}
        | error LP VarList RP {ERROR_MSG(@1.first_line,"FunDec funcid-err ", 120)}
        | error LP RP {ERROR_MSG(@1.first_line,"FunDec funcid-err ", 121)}
        ;
VarList : ParamDec COMMA VarList {EXP_ACTIONS3("VarList", $$, @$, $1, $2, $3)}
        | ParamDec {EXP_ACTIONS1("VarList", $$, @$, $1)}
        ;
ParamDec : Specifier VarDec {EXP_ACTIONS2("ParamDec", $$, @$, $1, $2)}
        ;


CompSt : LC DefList StmtList RC {EXP_ACTIONS4("CompSt", $$, @$, $1, $2, $3, $4)}
        | LC error RC {ERROR_OK(@2.first_line,"CompSt err", 126)}
        ;
StmtList : {$$=NULL;}
        | Stmt StmtList {EXP_ACTIONS2("StmtList", $$, @$, $1, $2)}
        ;
Stmt : Exp SEMI {EXP_ACTIONS2("Stmt", $$, @$, $1, $2)}
        | CompSt {EXP_ACTIONS1("Stmt", $$, @$, $1)}
        | RETURN Exp SEMI {EXP_ACTIONS3("Stmt", $$, @$, $1, $2, $3)}
        | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE {EXP_ACTIONS5("Stmt", $$, @$, $1, $2, $3, $4, $5)}
        | IF LP Exp RP Stmt ELSE Stmt {EXP_ACTIONS7("Stmt", $$, @$, $1, $2, $3, $4, $5, $6, $7)}
        | WHILE LP Exp RP Stmt {EXP_ACTIONS5("Stmt", $$, @$, $1, $2, $3, $4, $5)}
        | error SEMI {ERROR_MSG(@1.first_line,"stmt err ", 137)}
        | Exp error {ERROR_MSG(@2.first_line,"stmt ;?", 143)}
        | RETURN Exp error {ERROR_MSG(@3.first_line,"stmt ;?", 150)}
        | RETURN error SEMI {ERROR_MSG(@2.first_line,"stmt return-err", 151)}
        | IF LP error RP Stmt {ERROR_MSG(@3.first_line,"stmt if-err", 154)}
        | IF LP error RP Stmt ELSE Stmt {ERROR_MSG(@3.first_line,"stmt if-err", 155)}
        | WHILE LP error RP Stmt {ERROR_MSG(@3.first_line,"stmt while-err", 156)}
        ;

DefList : {$$=NULL;}
        | Def DefList {EXP_ACTIONS2("DefList", $$, @$, $1, $2)}
        ;
Def : Specifier DecList SEMI {EXP_ACTIONS3("Def", $$, @$, $1, $2, $3)}
        | Specifier error SEMI {ERROR_MSG(@2.first_line,"def err", 156)}
        | Specifier DecList error {ERROR_OK(@3.first_line,"def ;?", 159)}
        ;
DecList : Dec {EXP_ACTIONS1("DecList", $$, @$, $1)}
        | Dec COMMA DecList {EXP_ACTIONS3("DecList", $$, @$, $1, $2, $3)}
        | Dec error {ERROR_OK(@2.first_line,"DecList err", 160)}
        ;
Dec : VarDec {EXP_ACTIONS1("Dec", $$, @$, $1)}
        | VarDec ASSIGN Exp {EXP_ACTIONS3("Dec", $$, @$, $1, $2, $3)}
        | VarDec ASSIGN error {ERROR_OK(@3.first_line,"VarDec err", 164)}
        ;

Exp : Exp ASSIGN Exp {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | Exp AND Exp {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | Exp OR Exp {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | Exp REL Exp {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | Exp PLUS Exp {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | Exp MINUS Exp {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | Exp STAR Exp {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | Exp DIV Exp {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | LP Exp RP {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | MINUS Exp %prec UMINUS {EXP_ACTIONS2("Exp", $$, @$, $1, $2)}
        | NOT Exp {EXP_ACTIONS2("Exp", $$, @$, $1, $2)}
        | ID LP Args RP {EXP_ACTIONS4("Exp", $$, @$, $1, $2, $3, $4)}
        | ID LP RP {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | Exp LB Exp RB {EXP_ACTIONS4("Exp", $$, @$, $1, $2, $3, $4)}
        | Exp DOT ID {EXP_ACTIONS3("Exp", $$, @$, $1, $2, $3)}
        | ID {EXP_ACTIONS1("Exp", $$, @$, $1)}
        | INT {EXP_ACTIONS1("Exp", $$, @$, $1)}
        | FLOAT {EXP_ACTIONS1("Exp", $$, @$, $1)}
        | ID LP error RP  {ERROR_MSG(@3.first_line,"exp () ", 171)}
        | Exp LB error RB  {ERROR_MSG(@3.first_line,"exp [] ", 172)}
        | Exp error {ERROR_OK(@2.first_line,"exp err ", 186)}
        | MINUS error {ERROR_OK(@2.first_line,"exp err ", 191)}
        | NOT error {ERROR_OK(@2.first_line,"exp err ", 192)}
        | LP error RP {ERROR_MSG(@2.first_line,"exp () ", 193)}
        | Exp LB error SEMI {ERROR_MSG(@1.first_line,"exp ]? ", 194)}
        | ID LP error SEMI {ERROR_MSG(@1.first_line,"exp )? ", 195)}
        ;
Args : Exp COMMA Args {EXP_ACTIONS3("Args", $$, @$, $1, $2, $3)}
        | Exp {EXP_ACTIONS1("Args", $$, @$, $1)}
        | error COMMA Args {ERROR_MSG(@1.first_line,"Args err ", 196)}
        ;

%%
void yyerror(const char* msg) {
    if(errline!=yylloc.first_line){
        errname=1;
        fprintf(stdout, "Error type B at Line %d: %s.\n", yylloc.first_line, msg);
        errline=yylloc.first_line;
        set_errstate();
    }
}
