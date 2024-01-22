#ifndef REG
#define REG

#include <stdio.h>

#define REG_zero    0
#define REG_at      1
#define REG_v0      2
#define REG_v1      3
#define REG_a0      4
#define REG_a1      5
#define REG_a2      6
#define REG_a3      7
#define REG_t0      8
#define REG_t1      9
#define REG_t2      10
#define REG_t3      11
#define REG_t4      12
#define REG_t5      13
#define REG_t6      14
#define REG_t7      15
#define REG_s0      16
#define REG_s1      17
#define REG_s2      18
#define REG_s3      19
#define REG_s4      20
#define REG_s5      21
#define REG_s6      22
#define REG_s7      23
#define REG_t8      24
#define REG_t9      25
#define REG_k0      26
#define REG_k1      27
#define REG_gp      28
#define REG_sp      29
#define REG_fp      30
#define REG_ra      31

void tempRegInit();
void resetval();
void updateVal(char *val, FILE * out);
void loadArgs(char *tempval, int idx, FILE *out);
int regAssign(char *val, FILE *out);
void regSave(FILE * out);
void regReset(FILE * out);
void assignMem(char *val, int size, FILE *out);
int getMemAddr(char *val);
void clearuse(char *val);


#endif