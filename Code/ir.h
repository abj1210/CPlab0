#ifndef IR
#define IR

#include "syntax_tree.h"

//LABEL x :
#define LAB(s, x) sprintf(s, "LABEL %s :", x)
//FUNCTION f :
#define FNC(s, f) sprintf(s, "FUNCTION %s :", f)
//x := y
#define ASN(s, x, y) sprintf(s, "%s := %s", x, y)
//x := y + z
#define ADD(s, x, y, z) sprintf(s, "%s := %s + %s", x, y, z)
//x := y - z
#define SUB(s, x, y, z) sprintf(s, "%s := %s - %s", x, y, z)
//x := y * z
#define MUL(s, x, y, z) sprintf(s, "%s := %s * %s", x, y, z)
//x := y / z
#define DIV(s, x, y, z) sprintf(s, "%s := %s / %s", x, y, z)
//x := &y
#define ADR(s, x, y) sprintf(s, "%s := &%s", x, y)
//x := *y
#define STR(s, x, y) sprintf(s, "%s := *%s", x, y)
//*x := y
#define LSR(s, x, y) sprintf(s, "*%s := %s", x, y)
//GOTO x
#define GTO(s, x) sprintf(s, "GOTO %s", x)
//IF x relop y GOTO z
#define IFG(s, x, relop, y, z) sprintf(s, "IF %s %s %s GOTO %s", x, relop, y, z)
//RETURN x
#define RET(s, x) sprintf(s, "RETURN %s", x)
//DEC x size
#define DEC(s, x, size) sprintf(s, "DEC %s %s", x, size)
//ARG x
#define ARG(s, x) sprintf(s, "ARG %s", x)
//x := CALL f
#define CAL(s, x, f) sprintf(s, "%s := CALL %s", x, f)
//PARAM x
#define PAM(s, x) sprintf(s, "PARAM %s", x)
//READ x
#define READ(s, x) sprintf(s, "READ %s", x)
//WRITE x
#define WRITE(s, x) sprintf(s, "WRITE %s", x)

#define MAKE_IMM(s, imm) sprintf(s, "#%d", imm)
#define MAKE_TEMP(s, idx) sprintf(s, "temp_%d", idx)
#define MAKE_LABEL(s, _mode) sprintf(s, "L_%x", _mode)


#define irgen_rule(n_name) void irgen_##n_name(tree_node * node)
#define prev_rule(n_name) void prev_##n_name(tree_node * node)
#define final_rule(n_name) void final_##n_name(tree_node * node)
#define add_irgen_rule(n_name) else if(name_eq(#n_name))irgen_##n_name(node);
#define add_prev_rule(n_name) else if(name_eq(#n_name))prev_##n_name(node);
#define add_final_rule(n_name) else if(name_eq(#n_name))final_##n_name(node);

void genIrcode(tree_node * now, FILE * out);

#endif