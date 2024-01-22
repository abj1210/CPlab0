#include "obj.h"
#include "reg.h"

#include <string.h>

char argl[1024][100];
int argtop=0;
int argidx=0;
int loadidx=0;

void getObjHeader(FILE * fout){
    fprintf(fout, ".data\n");
    fprintf(fout, "_rstr: .asciiz \"Enter an integer:\"\n");
    fprintf(fout, "_wstr: .asciiz \"\\n\"\n");
    fprintf(fout, ".globl main\n");
    fprintf(fout, ".text\n");
}

void getReadFunc(FILE * fout){
    char s[100];
    LABEL(s, "read");
    SAVEINS(fout, s);
    LI(s, REG_v0, 4);
    SAVEINS(fout, s);
    LA(s, REG_a0, "_rstr");
    SAVEINS(fout, s);
    SYS(s);
    SAVEINS(fout, s);
    LI(s, REG_v0, 5);
    SAVEINS(fout, s);
    SYS(s);
    SAVEINS(fout, s);
    JR(s);
    SAVEINS(fout, s);
}

void getWriteFunc(FILE * fout){
    char s[100];
    LABEL(s, "write");
    SAVEINS(fout, s);
    LI(s, REG_v0, 1);
    SAVEINS(fout, s);
    SYS(s);
    SAVEINS(fout, s);
    LI(s, REG_v0, 4);
    SAVEINS(fout, s);
    LA(s, REG_a0, "_wstr");
    SAVEINS(fout, s);
    SYS(s);
    SAVEINS(fout, s);
    MOV(s, REG_v0, REG_zero);
    SAVEINS(fout, s);
    JR(s);
    SAVEINS(fout, s);
}

void callFunc(FILE * fout, char * func){
    char s[100];
    ADDI(s, REG_sp, REG_sp, -4);
    SAVEINS(fout, s);
    SW(s, REG_ra, REG_sp, 0);
    SAVEINS(fout, s);
    JAL(s, func);
    SAVEINS(fout, s);
    LW(s, REG_ra, REG_sp, 0);
    SAVEINS(fout, s);
    ADDI(s, REG_sp, REG_sp, 4);
    SAVEINS(fout, s);
}

void objtrans(FILE * fin, FILE * fout){
    getObjHeader(fout);
    getReadFunc(fout);
    getWriteFunc(fout);
    tempRegInit();
    char ir[100], s[100];
    while(fgets(ir, 100, fin)!=NULL){
        char lab[20], ret[20], x[20], y[20], op[20], z[20], rel[20], f[100];
        int size;
        if(0);
        JUDGE_FUN_TYPE(ir, lab){
            argidx=0;
            resetval();
            LABEL(s, lab);
            SAVEINS(fout, s);
            ADDI(s, REG_sp, REG_sp, -4);
            SAVEINS(fout, s);
            SW(s, REG_fp, REG_sp, 0);
            SAVEINS(fout, s);
            MOV(s, REG_fp, REG_sp);
            SAVEINS(fout, s);
            regReset(fout);
        }
        JUDGE_LAB_TYPE(ir, lab){
            LABEL(s, lab);
            SAVEINS(fout, s);
        }
        JUDGE_ASN_TYPE(ir, x, y, op, z){
            if(x[0]=='*'){
                char xtemp[20];
                sscanf(x,"*%s", xtemp);
                SW(s, regAssign(y, fout), regAssign(xtemp, fout), 0);
                SAVEINS(fout, s);
                clearuse(y);
                clearuse(xtemp);
            }
            else{
                int regx=regAssign(x, fout);
                if(regx!=REG_zero&&regx!=REG_v1){
                    if(y[0]=='#'){
                        int yimm;
                        sscanf(y,"#%d", &yimm);
                        LI(s, regx, yimm);
                        SAVEINS(fout, s);
                    }
                    else if(y[0]=='*'){
                        char ytemp[20];
                        sscanf(y,"*%s", ytemp);
                        LW(s, regx, regAssign(ytemp, fout), 0);
                        SAVEINS(fout, s);
                        clearuse(ytemp);
                    }
                    else if(y[0]=='&'){
                        char ytemp[20], addr[60];
                        sscanf(y,"&%s", ytemp);
                        sprintf(addr, "%d($fp)", getMemAddr(ytemp));
                        LA(s, regx, addr);
                        SAVEINS(fout, s);
                    }
                    else{
                        MOV(s, regx, regAssign(y, fout));
                        SAVEINS(fout, s);
                        clearuse(y);
                    }
                    updateVal(x, fout);
                }
                clearuse(x);
            }
        }
        JUDGE_MOP_TYPE(ir, x, y, op, z){
            if(strcmp(op, "+")==0){
                if(z[0]=='#'){
                    int zimm;
                    sscanf(z, "#%d", &zimm);
                    ADDI(s, regAssign(x, fout), regAssign(y, fout), zimm);
                    SAVEINS(fout, s);
                }
                else{
                    ADDR(s, regAssign(x, fout), regAssign(y, fout), regAssign(z, fout));
                    SAVEINS(fout, s);
                    clearuse(z);
                }
            }
            else if(strcmp(op, "-")==0){
                if(z[0]=='#'){
                    int zimm;
                    sscanf(z, "#%d", &zimm);
                    ADDI(s, regAssign(x, fout), regAssign(y, fout), -zimm);
                    SAVEINS(fout, s);
                }
                else{
                    SUBR(s, regAssign(x, fout), regAssign(y, fout), regAssign(z, fout));
                    SAVEINS(fout, s);
                    clearuse(z);
                }
            }
            else if(strcmp(op, "*")==0){
                if(z[0]=='#'){
                    int zimm;
                    sscanf(z, "#%d", &zimm);
                    LI(s, REG_v1, zimm);
                    SAVEINS(fout, s);
                    MULR(s, regAssign(x, fout), regAssign(y, fout), REG_v1);
                    SAVEINS(fout, s);
                }
                else{
                    MULR(s, regAssign(x, fout), regAssign(y, fout), regAssign(z, fout));
                    SAVEINS(fout, s);
                    clearuse(z);
                }
            }
            else if(strcmp(op, "/")==0){
                if(z[0]=='#'){
                    int zimm;
                    sscanf(z, "#%d", &zimm);
                    LI(s, REG_v1, zimm);
                    SAVEINS(fout, s);
                    DIVR(s, regAssign(y, fout), REG_v1);
                    SAVEINS(fout, s);
                    MFL(s, regAssign(x, fout));
                    SAVEINS(fout, s);
                }
                else{
                    DIVR(s, regAssign(y, fout), regAssign(z, fout));
                    SAVEINS(fout, s);
                    MFL(s, regAssign(x, fout));
                    SAVEINS(fout, s);
                    clearuse(z);
                }
            }
            clearuse(x);
            clearuse(y);
            updateVal(x, fout);
        }
        JUDGE_CAL_TYPE(ir, x, f){
            int i, off=0;
            for(i=0;i<argtop-4;i++){
                off+=4;
                ADDI(s, REG_sp, REG_sp, -4);
                SAVEINS(fout, s);
                SW(s, regAssign(argl[i], fout), REG_sp, 0);
                SAVEINS(fout, s);
                clearuse(argl[i]);
            }
            for(i;i<argtop;i++){
                MOV(s, REG_a0+(argtop-i-1), regAssign(argl[i], fout));
                SAVEINS(fout, s);
                clearuse(argl[i]);
            }
            argtop=0;
            regSave(fout);
            callFunc(fout, f);
            if(off!=0){
                ADDI(s, REG_sp, REG_sp, off);
                SAVEINS(fout, s);
            }
            MOV(s, regAssign(x, fout), REG_v0);
            SAVEINS(fout, s);
            clearuse(x);
            updateVal(x, fout);
        }
        JUDGE_RET_TYPE(ir, ret){
            int regi=regAssign(ret, fout);
            MOV(s, REG_v0, regi);
            SAVEINS(fout, s);
            MOV(s, REG_sp, REG_fp);
            SAVEINS(fout, s);
            LW(s, REG_fp, REG_sp, 0);
            SAVEINS(fout, s);
            ADDI(s, REG_sp, REG_sp, 4);
            SAVEINS(fout, s);
            JR(s);
            SAVEINS(fout, s);
            clearuse(ret);
        }
        JUDGE_GTO_TYPE(ir, lab){
            J(s, lab);
            SAVEINS(fout, s);
        }
        JUDGE_IFG_TYPE(ir, x, rel, y, z){
            int regx, regy;
            int needclrx, needclry;
            if(x[0]=='#'){
                needclrx = 0;
                int ximm;
                sscanf(x, "#%d", &ximm);
                LI(s, REG_v1, ximm);
                SAVEINS(fout, s);
                regx = REG_v1;
            }
            else{
                needclrx = 1;
                regx = regAssign(x, fout);
            }

            if(y[0]=='#'){
                needclry = 0;
                int yimm;
                sscanf(y, "#%d", &yimm);
                LI(s, REG_v1, yimm);
                SAVEINS(fout, s);
                regy = REG_v1;
            }
            else{
                needclry = 1;
                regy = regAssign(y, fout);
            }
            if(strcmp(rel, "==")==0){
                BR(s, eq, regx, regy, z);
            }
            else if(strcmp(rel, "!=")==0){
                BR(s, ne, regx, regy, z);
            }
            else if(strcmp(rel, ">")==0){
                BR(s, gt, regx, regy, z);
            }
            else if(strcmp(rel, "<")==0){
                BR(s, lt, regx, regy, z);
            }
            else if(strcmp(rel, ">=")==0){
                BR(s, ge, regx, regy, z);
            }
            else if(strcmp(rel, "<=")==0){
                BR(s, le, regx, regy, z);
            }
            SAVEINS(fout, s);
            if(needclrx)clearuse(x);
            if(needclry)clearuse(y);
        }
        JUDGE_ARG_TYPE(ir, x){
            strcpy(argl[argtop++], x);
        }
        JUDGE_PRM_TYPE(ir, x){
            loadArgs(x, argidx++, fout);
        }
        JUDGE_DEC_TYPE(ir, x, size){
            assignMem(x, size, fout);
        }
        JUDGE_RFN_TYPE(ir, x){
            callFunc(fout, "read");
            MOV(s, regAssign(x, fout), REG_v0);
            SAVEINS(fout, s);
            clearuse(x);
        }
        JUDGE_WFN_TYPE(ir, x){
            MOV(s, REG_a0, regAssign(x, fout));
            SAVEINS(fout, s);
            clearuse(x);
            callFunc(fout, "write");
        }
    }
}

