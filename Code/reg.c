#include "reg.h"
#include "obj.h"
#include <string.h>
#include <stdio.h>

struct tempReg{
    int regidx;
    int dirty;
    int addr;
    int use;
};

struct tempReg trlst[1024];
int savemap[1024][16];
int regmap[16];

int regcnt=8;
int reglim=16;
int templim=8;
int addrnow=0;
int t8=0;
int time=0;
void tempRegInit(){
    for(int i=0;i<16;i++){
        regmap[i]=-1;
    }
    for(int i=0;i<1024;i++){
        trlst[i].regidx=-1;
        trlst[i].dirty=0;
        trlst[i].addr=0;
    }
}
int selectMark(int x){
    if(trlst[x].regidx==-1) {
        int idxi=time%reglim;
        for(int i=0;i<reglim;i++){
            if(!trlst[regmap[(idxi+i)%reglim]].use)return regmap[(idxi+i)%reglim]; 
        }
    }
    else{
        if(trlst[regmap[trlst[x].regidx]].use) {
            for(int i=0;i<reglim;i++){
                if(!trlst[regmap[i]].use)return regmap[i]; 
            }
        }
        else return regmap[trlst[x].regidx];
    }
}
void resetval(){
    addrnow=0;
}
int saveValue(int mark, FILE *out){
    char s[100];
    int res=-1;
    SW(s, trlst[mark].regidx+regcnt, REG_fp, trlst[mark].addr);
    SAVEINS(out, s);
    res=trlst[mark].regidx;
    trlst[mark].use=0;
    return res;
}
int regAssign(char *val, FILE *out){
    if(strcmp(val, "temp_1")==0)return REG_zero;
    else if(strcmp(val, "temp_0")==0)return REG_v1;
    else{
        int x;
        char s[100];
        sscanf(val, "temp_%d", &x);
        trlst[x].dirty=time++;
        int flag=0;
        if(trlst[x].addr==0){
            addrnow-=4;
            ADDI(s, REG_sp, REG_fp, addrnow);
            SAVEINS(out, s);
            trlst[x].addr=addrnow;
            //fprintf(out, "ssss %d\n", addrnow);
            flag=1;
        }
        if(trlst[x].regidx==-1||regmap[trlst[x].regidx]!=x){
            for(int i=0;i<reglim;i++){
                if(regmap[i]==-1){
                    regmap[i]=x;
                    trlst[x].regidx=i;
                    break;
                }
            }
            if(trlst[x].regidx==-1||regmap[trlst[x].regidx]!=x){
                int mark=selectMark(x);
                trlst[x].regidx=trlst[mark].regidx;
                regmap[trlst[x].regidx]=x;
            }
            //fprintf(out, "ssss\n");
        }
        LW(s, trlst[x].regidx+regcnt, REG_fp, trlst[x].addr);
        SAVEINS(out, s);
        //printf("%d %d\n", x, trlst[x].regidx+regcnt);
        trlst[x].use=1;
        return trlst[x].regidx+regcnt;
    }
}
void loadArgs(char *tempval, int idx, FILE * out){
    int x;
    char s[100];
    sscanf(tempval, "temp_%d", &x);
    if(idx<4){
        MOV(s, regAssign(tempval, out), REG_a0+idx);
        SAVEINS(out, s);
        clearuse(tempval);
        saveValue(x, out);
    }
    else trlst[x].addr=4*idx-8;
}
void updateVal(char *val, FILE *out){
    int x;
    sscanf(val, "temp_%d", &x);
    trlst[x].dirty=time++;
    saveValue(x, out);
}
void clearuse(char *val){
    int x;
    sscanf(val, "temp_%d", &x);
    trlst[x].use=0;
}
void regSave(FILE * out){
    for(int i=0;i<templim;i++){
        regmap[i]=-1;
    }
    return ;
}
void regReset(FILE * out){
    for(int i=0;i<reglim;i++){
        regmap[i]=-1;
    }
    return ;
}
void assignMem(char *val, int size, FILE *out){
    int x;
    char s[100];
    sscanf(val, "temp_%d", &x);
    addrnow-=size;
    ADDI(s, REG_sp, REG_fp, addrnow);
    SAVEINS(out, s);
    trlst[x].addr=addrnow;
}
int getMemAddr(char *val){
    int x;
    sscanf(val, "temp_%d", &x);
    return trlst[x].addr;
}