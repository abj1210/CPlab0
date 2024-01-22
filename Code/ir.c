#include "ir.h"
#include "syntax_check_update.h"
#include "stack.h"

#include <string.h>
#include <assert.h>
char ins[600];
FILE * outp;
stack_t labelstk;
int offset=0;
int idx=10;
/*
0:rbuf -> $v1
1:'0' -> $zero
8:'*4' 
9:'offset' -> $t9 
*/
int t_set[10]={0,0,0,0,0,0,0,0,0,0};
int get_const(int const_num){
    char s[100];
    char s1[20], s2[20];
    if(const_num==0){
        if(!t_set[1]){
            MAKE_TEMP(s1, 1);
            MAKE_IMM(s2, 0);
            ASN(ins, s1, s2);
            fprintf(outp, "%s\n", ins);
            t_set[1]=1;
        }
        return 1;
    }
    else {
        MAKE_TEMP(s1, idx);
        MAKE_IMM(s2, const_num);
        ASN(ins, s1, s2);
        fprintf(outp, "%s\n", ins);
        return idx++;
    };
}
int label=1;
prev_rule(Stmt){
    //printf("%d\n", (node->lab_mode&0xf));
    if(((node->lab_mode&0xf)==0x1)||((node->lab_mode&0xf)==0x0)||((node->lab_mode&0xf)==0x3)){
        
        int lab=top(&labelstk);
        pop(&labelstk);
        char s[20];
        MAKE_LABEL(s, lab);
        LAB(ins, s);
        fprintf(outp, "%s\n", ins);
    }
    if(0);
    check_first_son(IF){
        tree_node * exp=node->first_son->next_brother->next_brother;
        tree_node * st1 = exp->next_brother->next_brother;
        tree_node * st2 = st1->next_brother == NULL ? NULL : st1->next_brother->next_brother;
        if(st2!=NULL){
            st1->lab_mode=(label<<4)|0;//if-else
            st2->lab_mode=(label<<4)|4;//else
        }
        else st1->lab_mode=(label<<4)|1;//if
        exp->lab_mode=(label<<4)|2;
    }
    check_first_son(WHILE){
        tree_node * exp=node->first_son->next_brother->next_brother;
        tree_node * st1 = exp->next_brother->next_brother;
        st1->lab_mode=(label<<4)|3;//while
        exp->lab_mode=(label<<4)|2;
    }
}
prev_rule(Exp){
    //printf("%d\n", (node->lab_mode)&0x3);
    if(0);
    check_first_son(Exp){
        tree_node * o1=node->first_son;
        tree_node * op=node->first_son->next_brother;
        tree_node * o2=node->first_son->next_brother->next_brother;
        if(eq(op->type_name,"RELOP")){
            char s[20];
            MAKE_LABEL(s, (label<<4)|2);
            LAB(ins, s);
            fprintf(outp, "%s\n", ins);
            push(&labelstk, (label<<4)|2);
        }
        else if(eq(op->type_name,"AND")||eq(op->type_name,"OR")){
            if((node->lab_mode&0xf)==0x2){
                o1->lab_mode=node->lab_mode;
                o2->lab_mode=node->lab_mode;
            }
        }
        else if(eq(op->type_name,"LB")){
            if((node->lab_mode&0xf)==0x2){
                char s[20];
                MAKE_LABEL(s, (label<<4)|2);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                push(&labelstk, (label<<4)|2);
            }
            
        }
    }
    check_first_son(ID){
        if((node->lab_mode&0xf)==0x2){
            char s[20];
            MAKE_LABEL(s, (label<<4)|2);
            LAB(ins, s);
            fprintf(outp, "%s\n", ins);
            push(&labelstk, (label<<4)|2);
        }
        struct val_node * vn=findn(&f_hash, node->first_son->val.name);
        if(vn!=NULL&&eq(vn->name,"write")){
            node->first_son->next_brother->next_brother->lab_mode=0xff;
        }
    }
    check_first_son(NOT){
        tree_node * o1=node->first_son->next_brother;
        if((node->lab_mode&0xf)==0x2){
            o1->lab_mode=node->lab_mode;
        }
    }
}
prev_rule(FunDec){
    FNC(ins, node->first_son->val.name);
    fprintf(outp,"%s\n", ins);
}
prev_rule(ParamDec){
    node->first_son->next_brother->ptr=1;
}
prev_rule(VarDec){
    node->first_son->ptr=node->ptr;
}

irgen_rule(Program)blank
irgen_rule(ExtDefList)blank
irgen_rule(ExtDef)blank
irgen_rule(ExtDecList)blank
irgen_rule(Specifier)blank
irgen_rule(StructSpecifier){
    assert(0);
}
irgen_rule(OptTag)blank
irgen_rule(Tag)blank
irgen_rule(VarDec){
    if(0);
    check_first_son(ID){
        struct val_node * vn=findn(&v_hash, node->first_son->val.name);
        vn->total_size=1;
        node->type_d=vn->d;
        node->type_val = vn->idx;
        if(vn->temp_idx==-1){
            char s[20];
            node->temp_idx = idx;
            vn->temp_idx = idx;
            idx++;
        }
        else node->temp_idx = vn->temp_idx;
    }
    check_first_son(VarDec){
        node->temp_idx = node->first_son->temp_idx;
        if(node->first_son->ptr!=1){
            node->type_d=node->first_son->type_d-1;
            node->type_val=node->first_son->type_val;
            tree_node * sz=node->first_son->next_brother->next_brother;
            struct val_node * vn=findi(&v_hash, node->type_val);
            vn->d_size[node->type_d]=sz->val.inum;
            vn->total_size*=sz->val.inum;
            if(node->type_d==0){
                char s1[20], s2[20], s3[20];
                MAKE_TEMP(s1, idx);
                sprintf(s2, "%d", vn->total_size*4);
                DEC(ins, s1, s2);
                fprintf(outp, "%s\n", ins);

                MAKE_TEMP(s3, vn->temp_idx);
                ADR(ins, s3, s1);
                fprintf(outp, "%s\n", ins);
                idx++;
            }
        }
    }
}
irgen_rule(FunDec){
    
}
irgen_rule(VarList){
    
}
irgen_rule(ParamDec){
    char s[20];
    MAKE_TEMP(s, node->first_son->next_brother->temp_idx);
    PAM(ins, s);
    fprintf(outp, "%s\n", ins);
}
irgen_rule(CompSt){
    memset(t_set, 0, sizeof(t_set));
}
irgen_rule(StmtList)blank
irgen_rule(Stmt){
    if(0);
    check_first_son(RETURN){
        int t_idx = node->first_son->next_brother->temp_idx;
        char s1[20];
        MAKE_TEMP(s1, t_idx);
        if(node->first_son->next_brother->ptr){
            STR(ins, s1, s1);
            fprintf(outp, "%s\n", ins);
            node->first_son->next_brother->first_son->ptr=0;
        }
        RET(ins, s1);
        fprintf(outp, "%s\n", ins);
    }
    if(((node->lab_mode&0xf)==0x1)){
        memset(t_set, 0, sizeof(t_set));
        int lab=top(&labelstk);
        char s[20];
        MAKE_LABEL(s, lab);
        LAB(ins, s);
        fprintf(outp, "%s\n", ins);
        pop(&labelstk);
        pop(&labelstk);
    }
    else if(((node->lab_mode&0xf)==0x0)){
        memset(t_set, 0, sizeof(t_set));
        int lab=top(&labelstk);
        pop(&labelstk);
        int lab2=((lab>>4)<<4)|3;
        char s[20];
        MAKE_LABEL(s, lab2);
        GTO(ins, s);
        fprintf(outp, "%s\n", ins);
        MAKE_LABEL(s, lab);
        LAB(ins, s);
        fprintf(outp, "%s\n", ins);
        pop(&labelstk);
        push(&labelstk, lab2);
    }
    else if(((node->lab_mode&0xf)==0x3)){
        memset(t_set, 0, sizeof(t_set));
        int labf=top(&labelstk);
        pop(&labelstk);
        int labr=top(&labelstk);
        pop(&labelstk);
        char s[20];

        MAKE_LABEL(s, labr);
        GTO(ins, s);
        fprintf(outp, "%s\n", ins);

        MAKE_LABEL(s, labf);
        LAB(ins, s);
        fprintf(outp, "%s\n", ins);
    }
    else if(((node->lab_mode&0xf)==0x4)){
        memset(t_set, 0, sizeof(t_set));
        int lab=top(&labelstk);
        char s[20];
        MAKE_LABEL(s, lab);
        LAB(ins, s);
        fprintf(outp, "%s\n", ins);
        pop(&labelstk);
    }

}
irgen_rule(DefList){
    
}
irgen_rule(Def){
    
}
irgen_rule(DecList){
    
}
irgen_rule(Dec){
    if(node->first_son->next_brother != NULL){
        int t1=node->first_son->temp_idx,  t2=node->first_son->next_brother->next_brother->temp_idx;
        char s1[20], s2[20];
        MAKE_TEMP(s1, t1);
        MAKE_TEMP(s2, t2);
        if(node->first_son->next_brother->next_brother->ptr){
            STR(ins, s2, s2);
            fprintf(outp, "%s\n", ins);
            node->first_son->next_brother->next_brother->ptr=0;
        }
        ASN(ins, s1, s2);
        fprintf(outp, "%s\n", ins);
    }
}
irgen_rule(Exp){
    
    if(0);
    check_first_son(ID){
        if(node->first_son->next_brother==NULL){
            struct val_node * vn=findn(&v_hash, node->first_son->val.name);
            node->type_val=vn->idx;
            node->type_d=vn->d;
            if(vn->temp_idx==-1){
                char s[20];
                node->temp_idx = idx;
                vn->temp_idx = idx;
                idx++;
            }
            else node->temp_idx = vn->temp_idx;
            
        }
        else{
            struct val_node * vn=findn(&f_hash, node->first_son->val.name);
            if(eq(vn->name,"read")){
                char s1[20];
                MAKE_TEMP(s1, 0);
                READ(ins, s1);
                fprintf(outp, "%s\n", ins); 
                node->temp_idx = 0;
            }
            else if(eq(vn->name,"write")){
                tree_node * arg = node->first_son->next_brother->next_brother;
                int t_idx=arg->temp_idx;
                char s1[20];
                MAKE_TEMP(s1, t_idx);
                WRITE(ins, s1);
                fprintf(outp, "%s\n", ins); 
                node->temp_idx=get_const(0);
            }
            else{
                char s1[20];
                node->temp_idx=idx;
                MAKE_TEMP(s1, idx++);
                CAL(ins, s1, node->first_son->val.name);
                fprintf(outp, "%s\n", ins);
            }
        }
    }
    check_first_son(INT){
        node->temp_idx = get_const(node->first_son->val.inum);
    }
    check_first_son(Exp){
        tree_node * o1=node->first_son;
        tree_node * op=node->first_son->next_brother;
        tree_node * o2=node->first_son->next_brother->next_brother;
        char t1[20], t2[20] ;
        MAKE_TEMP(t1, o1->temp_idx);
        MAKE_TEMP(t2, o2->temp_idx);
        if(o2->ptr){
            STR(ins, t2, t2);
            fprintf(outp, "%s\n", ins);
            o2->ptr=0;
        }
        if(eq(op->type_name,"ASSIGNOP")){
            if(o1->ptr){
                LSR(ins, t1, t2);
                fprintf(outp, "%s\n", ins); 
            }
            else{
                ASN(ins, t1, t2);
                fprintf(outp, "%s\n", ins); 
            }
        }
        else if(eq(op->type_name, "LB")){
            node->type_val=node->first_son->type_val;
            node->temp_idx=node->first_son->temp_idx;
            struct val_node * vn=findi(&v_hash, node->type_val);
            node->type_d=node->first_son->type_d-1;
            int t1= node->first_son->next_brother->next_brother->temp_idx;
            char s1[20], s2[20], s3[20], s4[20], s5[20];
            node->ptr=1;
            if(node->temp_idx==vn->temp_idx){
                MAKE_TEMP(s1, 9);
                MAKE_TEMP(s2, t1);
                MAKE_TEMP(s3, get_const(4));
                MUL(ins, s1, s2, s3);
                fprintf(outp, "%s\n", ins);

                MAKE_TEMP(s4, node->temp_idx);
                MAKE_TEMP(s5, idx);
                ADD(ins, s5, s4, s1);
                fprintf(outp, "%s\n", ins);
                node->temp_idx=idx;
                idx++;
            }
            else{
                MAKE_TEMP(s1, 9);
                MAKE_TEMP(s2, t1);
                MAKE_IMM(s3, vn->d_size[node->type_d]);
                MUL(ins, s1, s1, s3);
                fprintf(outp, "%s\n", ins);
                MAKE_TEMP(s4, get_const(4));
                MAKE_TEMP(s5, 8);
                MUL(ins, s5, s2, s4);
                fprintf(outp, "%s\n", ins);
                ADD(ins, s1, s1, s5);
                fprintf(outp, "%s\n", ins);
                MAKE_TEMP(s5, node->temp_idx);
                MAKE_TEMP(s4, vn->temp_idx);
                ADD(ins, s5, s4, s1);
                fprintf(outp, "%s\n", ins);
            }
        }
        else if(o1->ptr){
            STR(ins, t1, t1);
            fprintf(outp, "%s\n", ins);
            o1->ptr=0;
        }

        if(eq(op->type_name, "PLUS")){
            char t3[20];
            node->temp_idx=idx;
            MAKE_TEMP(t3, idx++);
            ADD(ins, t3, t1, t2);
            fprintf(outp, "%s\n", ins); 
        }
        else if(eq(op->type_name, "MINUS")){
            char t3[20];
            node->temp_idx=idx;
            MAKE_TEMP(t3, idx++);
            SUB(ins, t3, t1, t2);
            fprintf(outp, "%s\n", ins); 
        }
        else if(eq(op->type_name, "STAR")){
            char t3[20];
            node->temp_idx=idx;
            MAKE_TEMP(t3, idx++);
            MUL(ins, t3, t1, t2);
            fprintf(outp, "%s\n", ins); 
        }
        else if(eq(op->type_name, "DIV")){
            char t3[20];
            node->temp_idx=idx;
            MAKE_TEMP(t3, idx++);
            DIV(ins, t3, t1, t2);
            fprintf(outp, "%s\n", ins); 
        }
        else if(eq(op->type_name, "DOT")){
            assert(0);
        }
        
        
        
    }
    check_first_son(LP){
        node->temp_idx = node->first_son->next_brother->temp_idx;
        node->ptr = node->first_son->next_brother->ptr;
    }
    check_first_son(MINUS){
         
        char t3[20], t1[20], t2[20];
        MAKE_TEMP(t1, get_const(0));
        MAKE_TEMP(t2, node->first_son->next_brother->temp_idx);
        if(node->first_son->next_brother->ptr){
            STR(ins, t2, t2);
            fprintf(outp, "%s\n", ins);
            node->first_son->next_brother->ptr=0;
        }
        node->temp_idx=idx;
        MAKE_TEMP(t3, idx++);
        SUB(ins, t3, t1, t2);
        fprintf(outp, "%s\n", ins); 
    }

    if((node->lab_mode&0xf) == 0x2){
        if(0);
        check_first_son(Exp){
            tree_node * o1=node->first_son;
            tree_node * op=node->first_son->next_brother;
            tree_node * o2=node->first_son->next_brother->next_brother;
            char s1[20], s2[20], s3[20], s4[20];
            MAKE_TEMP(s1, o1->temp_idx);
            MAKE_TEMP(s2, o2->temp_idx);   
            if(o1->ptr){
                STR(ins, s1, s1);
                fprintf(outp, "%s\n", ins);
            }
            if(o2->ptr){
                STR(ins, s2, s2);
                fprintf(outp, "%s\n", ins);
            }
            if(eq(op->type_name,"RELOP")){
                MAKE_LABEL(s4, (label<<4)|0);
                push(&labelstk, (label<<4)|0);
                MAKE_LABEL(s3, (label<<4)|1);
                push(&labelstk, (label<<4)|1);
                
                label++;
                /*
                    RELGT = 261,                    RELGT  
                    RELLT = 262,                    RELLT  
                    RELGE = 263,                    RELGE  
                    RELLE = 264,                    RELLE  
                    RELEQ = 265,                    RELEQ  
                    RELNE = 266,                    RELNE  
                */
                if(op->val.type==261){
                    IFG(ins, s1, ">", s2, s3);
                    fprintf(outp, "%s\n", ins);
                }
                else if(op->val.type==262){
                    IFG(ins, s1, "<", s2, s3);
                    fprintf(outp, "%s\n", ins);
                }
                else if(op->val.type==263){
                    IFG(ins, s1, ">=", s2, s3);
                    fprintf(outp, "%s\n", ins);
                }
                else if(op->val.type==264){
                    IFG(ins, s1, "<=", s2, s3);
                    fprintf(outp, "%s\n", ins);
                }
                else if(op->val.type==265){
                    IFG(ins, s1, "==", s2, s3);
                    fprintf(outp, "%s\n", ins);
                }
                else if(op->val.type==266){
                    IFG(ins, s1, "!=", s2, s3);
                    fprintf(outp, "%s\n", ins);
                }
                GTO(ins, s4);
                fprintf(outp, "%s\n", ins);
            }
            else if(eq(op->type_name,"AND")){
                char s[20];
                int labbs=top(&labelstk);
                pop(&labelstk);
                int labbf=top(&labelstk);
                pop(&labelstk);
                int labbr=top(&labelstk);
                pop(&labelstk);
                int labas=top(&labelstk);
                pop(&labelstk);
                int labaf=top(&labelstk);
                pop(&labelstk);
                int tf=(label<<4)|0;
                int ts=(label<<4)|1;
                label++;

                MAKE_LABEL(s, labbf);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                MAKE_LABEL(s, labaf);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                MAKE_LABEL(s, tf);
                GTO(ins, s);
                fprintf(outp, "%s\n", ins);

                MAKE_LABEL(s, labbs);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                MAKE_LABEL(s, ts);
                GTO(ins, s);
                fprintf(outp, "%s\n", ins);

                MAKE_LABEL(s, labas);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                MAKE_LABEL(s, labbr);
                GTO(ins, s);
                fprintf(outp, "%s\n", ins);

                push(&labelstk, tf);
                push(&labelstk, ts);
            }
            else if(eq(op->type_name,"OR")){
                char s[20];
                int labbs=top(&labelstk);
                pop(&labelstk);
                int labbf=top(&labelstk);
                pop(&labelstk);
                int labbr=top(&labelstk);
                pop(&labelstk);
                int labas=top(&labelstk);
                pop(&labelstk);
                int labaf=top(&labelstk);
                pop(&labelstk);
                int tf=(label<<4)|0;
                int ts=(label<<4)|1;
                label++;

                MAKE_LABEL(s, labbf);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                MAKE_LABEL(s, tf);
                GTO(ins, s);
                fprintf(outp, "%s\n", ins);

                MAKE_LABEL(s, labbs);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                MAKE_LABEL(s, labas);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                MAKE_LABEL(s, ts);
                GTO(ins, s);
                fprintf(outp, "%s\n", ins);

                MAKE_LABEL(s, labaf);
                LAB(ins, s);
                fprintf(outp, "%s\n", ins);
                MAKE_LABEL(s, labbr);
                GTO(ins, s);
                fprintf(outp, "%s\n", ins);

                push(&labelstk, tf);
                push(&labelstk, ts);
            }
            else if(eq(op->type_name,"LB")){
                char s1[20], s2[20], s3[20], s4[20];
                MAKE_TEMP(s1, node->temp_idx);
                MAKE_TEMP(s2, get_const(0));
                if(node->ptr){
                    STR(ins, s1, s1);
                    fprintf(outp, "%s\n", ins);
                    node->ptr=0;
                }

                MAKE_LABEL(s4, (label<<4)|0);
                push(&labelstk, (label<<4)|0);
                MAKE_LABEL(s3, (label<<4)|1);
                push(&labelstk, (label<<4)|1);
                
                label++;

                IFG(ins, s1, "!=", s2, s3);
                fprintf(outp, "%s\n", ins);

                GTO(ins, s4);
                fprintf(outp, "%s\n", ins);
            }
        }
        check_first_son(NOT){
            char s[20];
            int labs=top(&labelstk);
            pop(&labelstk);
            int labf=top(&labelstk);
            pop(&labelstk);
            int tf=(label<<4)|0;
            int ts=(label<<4)|1;
            label++;

            MAKE_LABEL(s, labf);
            LAB(ins, s);
            fprintf(outp, "%s\n", ins);
            MAKE_LABEL(s, ts);
            GTO(ins, s);
            fprintf(outp, "%s\n", ins);

            MAKE_LABEL(s, labs);
            LAB(ins, s);
            fprintf(outp, "%s\n", ins);
            MAKE_LABEL(s, tf);
            GTO(ins, s);
            fprintf(outp, "%s\n", ins);

            push(&labelstk, tf);
            push(&labelstk, ts);
        }
        else{
            char s1[20], s2[20], s3[20], s4[20];
            MAKE_TEMP(s1, node->temp_idx);
            MAKE_TEMP(s2, get_const(0));
            if(node->ptr){
                STR(ins, s1, s1);
                fprintf(outp, "%s\n", ins);
                node->ptr=0;
            }

            MAKE_LABEL(s4, (label<<4)|0);
            push(&labelstk, (label<<4)|0);
            MAKE_LABEL(s3, (label<<4)|1);
            push(&labelstk, (label<<4)|1);
            
            label++;

            IFG(ins, s1, "!=", s2, s3);
            fprintf(outp, "%s\n", ins);

            GTO(ins, s4);
            fprintf(outp, "%s\n", ins);
        }
    }
}
irgen_rule(Args){
    
    node->temp_idx = node->first_son->temp_idx;
    char t1[20];
    MAKE_TEMP(t1, node->first_son->temp_idx);
    if(node->first_son->ptr){
        STR(ins, t1, t1);
        fprintf(outp, "%s\n", ins);
        node->first_son->ptr=0;
    }
}

final_rule(Args){
    if(node->lab_mode!=0xff){
        char s1[20];
        MAKE_TEMP(s1, node->temp_idx);
        ARG(ins, s1);
        fprintf(outp, "%s\n", ins);
    }
}

void genIrcode(tree_node * now, FILE * out){
    outp=out;
    tree_node * node = now;
    if(now==NULL)return ;
    if(get_errstate())return ;
    add_prev_rule(Stmt)
    add_prev_rule(Exp)
    add_prev_rule(FunDec)
    add_prev_rule(ParamDec)
    add_prev_rule(VarDec)



    genIrcode(now->first_son, out);

    if(get_errstate())return ;
    add_irgen_rule(Program)
    add_irgen_rule(ExtDefList)
    add_irgen_rule(ExtDef)
    add_irgen_rule(ExtDecList)
    add_irgen_rule(Specifier)
    add_irgen_rule(StructSpecifier)
    add_irgen_rule(OptTag)
    add_irgen_rule(Tag)
    add_irgen_rule(VarDec)
    add_irgen_rule(FunDec)
    add_irgen_rule(VarList)
    add_irgen_rule(ParamDec)
    add_irgen_rule(CompSt)
    add_irgen_rule(StmtList)
    add_irgen_rule(Stmt)
    add_irgen_rule(DefList)
    add_irgen_rule(Def)
    add_irgen_rule(DecList)
    add_irgen_rule(Dec)
    add_irgen_rule(Exp)
    add_irgen_rule(Args)

    genIrcode(now->next_brother, out);

    if(get_errstate())return ;
    add_final_rule(Args)
}