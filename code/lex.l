%{
#define YYSTYPE tree_node*
#include<stdio.h>
#include<string.h>
#include "syntax_tree.h"
#include "parser.tab.h"

int yycolumn = 1;
#define YY_USER_ACTION \
 yylloc.first_line = yylloc.last_line = yylineno; \
 yylloc.first_column = yycolumn; \
 yylloc.last_column = yycolumn + yyleng - 1; \
 yycolumn += yyleng;

#define DEBUG 1

#define COMMON_ACTIONS(VAL_TYPE, RET_TYPE, NAME) \
        if(DEBUG){\
                fprintf(yyout,#VAL_TYPE);\
                fprintf(yyout,"  (id=0x%02x) %s\n", RET_TYPE, yytext);\
        }\
        yylval=make_common_token_node(#NAME, VAL_TYPE);\
        return RET_TYPE;

#define INT_ACTIONS(BASE) \
        if(DEBUG){\
                fprintf(yyout,"INTB");\
                fprintf(yyout, #BASE);\
                fprintf(yyout,"  (id=0x%02x) %s\n", INT, yytext);\
        }\
        yylval=make_intb##BASE##_node(yytext);\
        if(yylval==NULL){\
                fprintf(stderr,"Error type A at Line %d : Invalid int form \"%s\" \n", yylineno, yytext);\
                return YYerror;\
        }\
        return INT;

#define FLOAT_ACTIONS(TYPE) \
        if(DEBUG){\
                fprintf(yyout, #TYPE);\
                fprintf(yyout,"  (id=0x%02x) %s\n", FLOAT, yytext);\
        }\
        yylval=make_float_node(yytext);\
        return FLOAT;

#define ID_ACTIONS \
        if(DEBUG)fprintf(yyout,"ID     (id=0x%02x) %s\n", ID, yytext);\
        yylval=make_id_node(yytext);\
        return ID;
%}

%option yylineno

comment_1 ("//")(.)
comment_2 "/*"([^*]|\*+[^*/])*\*+"/"
white [\t ]
digit [0-9]
l_letter [a-z]
u_letter [A-Z]


intnum 0|([1-9]{digit}*)
intnumb16 (0(x|X))[0-9a-zA-Z]+
intnumb8 0({digit}+)

float ({intnum})(".")({digit}+)
efloat (({digit}*("."){digit}+)|({digit}+(".")))(e|E)((\+|-)?({digit}+))

id ({l_letter}|{u_letter}|_)({l_letter}|{u_letter}|{digit}|_)*



%%
{white}+ ;
"\n"  {yycolumn=1;}
{comment_1} {if(DEBUG)fprintf(yyout,"This is a comment: %s\n", yytext);}
{comment_2} {if(DEBUG)fprintf(yyout,"This is a comment: %s\n", yytext);}
";"   {COMMON_ACTIONS(SEMI,SEMI,SEMI)}
","   {COMMON_ACTIONS(COMMA,COMMA,COMMA)}
"="   {COMMON_ACTIONS(ASSIGN,ASSIGN,ASSIGNOP)}
">"   {COMMON_ACTIONS(RELGT,REL,RELOP)}
"<"   {COMMON_ACTIONS(RELLT,REL,RELOP)}
">="  {COMMON_ACTIONS(RELGE,REL,RELOP)}
"<="  {COMMON_ACTIONS(RELLE,REL,RELOP)}
"=="  {COMMON_ACTIONS(RELEQ,REL,RELOP)}
"!="  {COMMON_ACTIONS(RELNE,REL,RELOP)}
"+"   {COMMON_ACTIONS(PLUS,PLUS,PLUS)}
"-"   {COMMON_ACTIONS(MINUS,MINUS,MINUS)}
"*"   {COMMON_ACTIONS(STAR,STAR,STAR)}
"/"   {COMMON_ACTIONS(DIV,DIV,DIV)}
"&&"  {COMMON_ACTIONS(AND,AND,AND)}
"||"  {COMMON_ACTIONS(OR,OR,OR)}
"."   {COMMON_ACTIONS(DOT,DOT,DOT)}
"!"   {COMMON_ACTIONS(NOT,NOT,NOT)}
"int" {COMMON_ACTIONS(ITYPE,TYPE,TYPE)}
"float" {COMMON_ACTIONS(FTYPE,TYPE,TYPE)}
"("   {COMMON_ACTIONS(LP,LP,LP)}
")"   {COMMON_ACTIONS(RP,RP,RP)}
"["   {COMMON_ACTIONS(LB,LB,LB)}
"]"   {COMMON_ACTIONS(RB,RB,RB)}
"{"   {COMMON_ACTIONS(LC,LC,LC)}
"}"   {COMMON_ACTIONS(RC,RC,RC)}
"struct" {COMMON_ACTIONS(STRUCT,STRUCT,STRUCT)}
"return" {COMMON_ACTIONS(RETURN,RETURN,RETURN)}
"if"  {COMMON_ACTIONS(IF,IF,IF)}
"else" {COMMON_ACTIONS(ELSE,ELSE,ELSE)}
"while" {COMMON_ACTIONS(ELSE,ELSE,ELSE)}
{intnum} {INT_ACTIONS(10)}
{intnumb16} {INT_ACTIONS(16)}
{intnumb8} {INT_ACTIONS(8)}
{float}  {FLOAT_ACTIONS(FLOAT)}
{efloat}  {FLOAT_ACTIONS(EFLOAT)}

{id}   {ID_ACTIONS}
.      {fprintf(stderr,"Error type A at Line %d : Invalid character \"%s\" \n", yylineno, yytext);return YYerror;}
%%
int yywrap()
{
return 1;
}
