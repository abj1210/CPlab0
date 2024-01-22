#ifndef OBJ
#define OBJ

#define SAVEINS(out, s) fprintf(out, "%s\n", s);

#define LABEL(s, x) sprintf(s, "%s:", x);

#define SW(s, r, base, off) sprintf(s, "    sw $%d, %d($%d)", r, off , base);
#define LW(s, r, base, off) sprintf(s, "    lw $%d, %d($%d)", r, off , base);
#define LI(s, r, k) sprintf(s, "    li $%d, %d", r, k);
#define LA(s, r, a) sprintf(s, "    la $%d, %s", r, a);

#define SYS(s) sprintf(s, "    syscall");

#define J(s, x) sprintf(s, "    j %s", x);
#define JR(s) sprintf(s, "    jr $ra");
#define JAL(s, func) sprintf(s, "    jal %s", func);

#define MOV(s, r1, r2) sprintf(s, "    move $%d, $%d", r1, r2);
#define MFL(s, x) sprintf(s, "    mflo $%d", x);

#define ADDI(s, rr, r1, imm) sprintf(s, "    addi $%d, $%d, %d", rr, r1, imm);
#define ADDR(s, rr, r1, r2) sprintf(s, "    add $%d, $%d, $%d", rr, r1, r2);
#define SUBR(s, rr, r1, r2) sprintf(s, "    sub $%d, $%d, $%d", rr, r1, r2);
#define MULR(s, rr, r1, r2) sprintf(s, "    mul $%d, $%d, $%d", rr, r1, r2);
#define DIVR(s, r1, r2) sprintf(s, "    div $%d, $%d", r1, r2);

#define BR(s, rel, x, y, z) sprintf(s, "    b%s $%d, $%d, %s", #rel, x, y, z);

#define JUDGE_FUN_TYPE(s, lab) else if(sscanf(s, "FUNCTION %s :", lab)==1)
#define JUDGE_LAB_TYPE(s, lab) else if(sscanf(s, "LABEL %s :", lab)==1)
#define JUDGE_ASN_TYPE(s, x, y, op, z) else if(sscanf(s, "%s := %s %s %s", x, y, op, z)==2)
#define JUDGE_MOP_TYPE(s, x, y, op, z) else if(sscanf(s, "%s := %s %s %s", x, y, op, z)==4)
#define JUDGE_CAL_TYPE(s, x, f) else if(sscanf(s, "%s := CALL %s", x, f)==2)
#define JUDGE_RET_TYPE(s, ret) else if(sscanf(s, "RETURN %s", ret)==1)
#define JUDGE_GTO_TYPE(s, lab) else if(sscanf(s, "GOTO %s", lab)==1)
#define JUDGE_IFG_TYPE(s, x, rel, y, z) else if(sscanf(s, "IF %s %s %s GOTO %s", x, rel, y, z)==4)
#define JUDGE_ARG_TYPE(s, x) else if(sscanf(s, "ARG %s", x)==1)
#define JUDGE_PRM_TYPE(s, x) else if(sscanf(s, "PARAM %s", x)==1)
#define JUDGE_DEC_TYPE(s, x, size) else if(sscanf(s, "DEC %s %d", x, &size)==2)
#define JUDGE_RFN_TYPE(s, x) else if(sscanf(s, "READ %s", x)==1)
#define JUDGE_WFN_TYPE(s, x) else if(sscanf(s, "WRITE %s", x)==1)


#include <stdio.h>
void objtrans(FILE * fin, FILE * fout);

#endif