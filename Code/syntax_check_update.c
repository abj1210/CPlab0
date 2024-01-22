#include "syntax_check_update.h"
#include <stdlib.h>
#include <string.h>
struct hash_table v_hash, t_hash, f_hash;
int now_func=-1;
int ret_type=-1;
int cnt=0;
int now_struct=0;
int type_now=-1;
void init_hash(){
    init(1024, &v_hash);
    init(1024,&t_hash);
    init(1024,&f_hash);
    int idx = make_val_insert(&f_hash, "read", 0);
    struct val_node * vn = findi(&f_hash, idx), * intn = make_type_insert(&t_hash, "int");
    vn->type_idx = intn->type_idx;
    idx = make_val_insert(&f_hash, "write", 0);
    vn = findi(&f_hash, idx);
    vn->type_idx = intn->type_idx;
    int vidx = make_val_insert(&v_hash, "?write?", 0);
    struct val_node * vvn = findi(&v_hash, vidx);
    vvn->type_idx=intn->type_idx;
    vn->next = vvn;
}
char * get_name(){
    char * name=malloc(10*sizeof(char));
    sprintf(name, "?%d", cnt);
    cnt++;
    return name;
}
int type_eq(int idx1, int idx2){
    struct val_node * vn1=findi(&t_hash, idx1);
    struct val_node * vn2=findi(&t_hash, idx2);
    if(idx1==idx2)return 1;
    else if(vn1==NULL||vn2==NULL)return 0;
    else{
        if(eq(vn1->name, "int")||eq(vn1->name, "float"))return 0;
        struct val_node * c1, * c2;
        c1=vn1->next;
        c2=vn2->next;
        while(1){
            if(c1==NULL&&c2==NULL)return 1;
            else if(c1!=NULL&&c2==NULL)return 0;
            else if(c1==NULL&&c2!=NULL)return 0;
            else {
                if(!type_eq(c1->type_idx,c2->type_idx))return 0;
                c1=c1->next;
                c2=c2->next;
            }
        }
    }
}
check_rule(Program)blank
check_rule(ExtDefList)blank
check_rule(ExtDef){
    
    tree_node * declst=node->first_son->next_brother;
    if(eq(declst->type_name,"SEMI"))return ;
    else if(eq(declst->type_name,"ExtDecList")){
        
        int type_idx=node->first_son->type_val;
        for(tree_node * i=declst;;i=i->first_son->next_brother->next_brother){
            struct val_node * vn=findi(&v_hash, i->type_val);
            if(vn!=NULL)vn->type_idx=type_idx;
            if(i->first_son->next_brother==NULL)break;
        }
    }
    else if(eq(declst->type_name,"FunDec")){
        if(declst->type_val<0)ERROR_C(declst->val.line, 4, "Function Redifinition");
    }
    now_func=-1;
}
check_rule(ExtDecList){
    pass_type(node, node->first_son);
}
check_rule(Specifier){
    
    if(0);
    check_first_son(TYPE){
        struct val_node * vn=NULL;
        if(node->first_son->val.type==275)vn=make_type_insert(&t_hash, "int");
        else if(node->first_son->val.type==276)vn=make_type_insert(&t_hash, "float");
        node->type_val=vn->type_idx;
        if(now_func==-1){
            ret_type=vn->type_idx;
            now_func=-2;
        }
        node->type_d=vn->d;
    }
    check_first_son(StructSpecifier){
        pass_type(node, node->first_son);
        if(now_func==-1){
            ret_type=node->type_val;
            now_func=-2;
        }
    }
    type_now=node->type_val;
    
}
check_rule(StructSpecifier){
    tree_node * tag=node->first_son->next_brother;
    if(eq(tag->type_name, "Tag")){
        struct val_node * vn=findn(&t_hash, tag->first_son->val.name);
        if(vn==NULL)ERROR_C(tag->val.line, 17, "Undefined struct type");
        else{
            node->type_val=vn->type_idx;
            node->type_d=-1;
            node->left_val=0;
        }
    }
    else{
        int idx=0;
        if(eq(tag->type_name, "OptTag"))idx=tag->type_val;
        if(idx<0)ERROR_C(node->val.line, 16, "Struct type Redifination");
        else{
            struct val_node * vn=NULL;
            tree_node * deflst;
            if(eq(tag->type_name, "OptTag")){
                vn=findn(&t_hash, tag->first_son->val.name);
                deflst=tag->next_brother->next_brother;
            }
            else{
                vn=make_type_insert(&t_hash, get_name());
                deflst=tag->next_brother;
            }
            vn->next=findi(&v_hash, deflst->type_val);
            node->type_val=vn->type_idx;
            node->type_d=-1;
            node->left_val=0;
        }
    }
    now_struct--;
}
check_rule(OptTag){
    node->type_val=make_val_insert(&v_hash, node->first_son->val.name, 0);
    make_type_insert(&t_hash, node->first_son->val.name);
}
check_rule(Tag)blank
check_rule(VarDec){
    if(0);
    check_first_son(ID){
        node->type_val=make_val_insert(&v_hash, node->first_son->val.name, 1);
        //printf("VD%d\n", node->type_val);
        if(node->type_val<0){
            if(now_struct==0)ERROR_C(node->val.line, 3, "Value Redifinition");
            else ERROR_C(node->val.line, 15, "Domain redefinition / Domain initialized during definition");
        }
        else{
            node->type_d=0;
            node->left_val=1;
        }
    }
    check_first_son(VarDec){
        pass_type(node, node->first_son);
        if(node->type_d>=0)node->type_d++;
        struct val_node * vn=findi(&v_hash, node->type_val);
        if(vn!=NULL)vn->d=node->type_d;
    }
}
check_rule(FunDec){
    tree_node * id=node->first_son;
    tree_node * vl=id->next_brother->next_brother;
    node->type_val=make_val_insert(&f_hash, id->val.name, 0);
    struct val_node * vn=findn(&f_hash, id->val.name);
    now_func=node->type_val;
    node->type_d=0;
    node->left_val=0;
    
    if(vn!=NULL)vn->type_idx=ret_type;
    if(!(eq(vl->type_name, "RP"))){
        if(vn!=NULL)vn->next=findi(&v_hash, vl->type_val);
    }
}
check_rule(VarList){
    pass_type(node, node->first_son);
    if(node->first_son->next_brother!=NULL){
        struct val_node * vn0=findi(&v_hash, node->type_val);
        struct val_node * vn1=findi(&v_hash, node->first_son->next_brother->next_brother->type_val);
        if(vn0!=NULL)vn0->next=vn1;
    }

}
check_rule(ParamDec){
    struct val_node * vn=findi(&v_hash, node->first_son->next_brother->type_val);
    if(vn!=NULL)vn->type_idx=node->first_son->type_val;
    pass_type(node, node->first_son->next_brother);
}
check_rule(CompSt)blank
check_rule(StmtList)blank
check_rule(Stmt){
    if(0);
    check_first_son(RETURN){
        struct val_node * vn=findi(&f_hash, now_func);
        if(vn!=NULL){
            if(!type_eq(vn->type_idx,node->first_son->next_brother->type_val)||vn->d!=node->first_son->next_brother->type_d)
                ERROR_C(node->first_son->next_brother->val.line, 8, "Return type don't match");
        }
    }
    check_first_son(WHILE){
        tree_node * exp=node->first_son->next_brother->next_brother;
        struct val_node * vn=findi(&t_hash, exp->type_val);
        if(vn==NULL||! eq(vn->name, "int")|| exp->type_d!=0)ERROR_C(exp->val.line, 7, "Operands don't match");
    }
    check_first_son(IF){
        tree_node * exp=node->first_son->next_brother->next_brother;
        struct val_node * vn=findi(&t_hash, exp->type_val);
        if(vn==NULL||! eq(vn->name, "int")|| exp->type_d!=0)ERROR_C(exp->val.line, 7, "Operands don't match");
    }

}
check_rule(DefList){
    pass_type(node, node->first_son);
    if(now_struct>0&&node->first_son->next_brother!=NULL){
        struct val_node * vn=findi(&v_hash, node->type_val);
        struct val_node * v1=findi(&v_hash, node->first_son->next_brother->type_val);
        if(vn!=NULL){
            while(vn->next!=NULL)vn=vn->next;
            vn->next=v1;
        }
    }
}
check_rule(Def){
    tree_node * declst=node->first_son->next_brother;
    int type_idx=node->first_son->type_val;
    for(tree_node * i=declst;;i=i->first_son->next_brother->next_brother){
        struct val_node * vn=findi(&v_hash, i->type_val);
        if(vn!=NULL){
            
            vn->type_idx=type_idx;
        }
        if(i->first_son->next_brother==NULL)break;
    }
    if(now_struct>0){
        pass_type(node, declst);              
    }
}
check_rule(DecList){
    pass_type(node, node->first_son);
    if(now_struct>0&&node->first_son->next_brother!=NULL){
        struct val_node * vn=findi(&v_hash, node->type_val);
        struct val_node * v1=findi(&v_hash, node->first_son->next_brother->next_brother->type_val);
        if(vn!=NULL)vn->next=v1;
    }
}
check_rule(Dec){
    pass_type(node, node->first_son);
    if(node->first_son->next_brother!=NULL){
        tree_node * o1=node->first_son;
        tree_node * o2=node->first_son->next_brother->next_brother;
        pass_type(node, o1);
        if(now_struct>0)ERROR_C(o2->val.line, 15, "Domain redefinition / Domain initialized during definition");   
        else if(type_eq(type_now, o2->type_val) && o1->type_d==o2->type_d){
            if(!o1->left_val)ERROR_C(o2->val.line, 6, "Left value error");
        }
        else ERROR_C(o2->val.line, 5, "Types don't match between assignop");
    }
}
check_rule(Exp){
    
    if(0);
    check_first_son(ID){
        if(node->first_son->next_brother==NULL){
            struct val_node * vn=findn(&v_hash, node->first_son->val.name);
            if(vn==NULL)ERROR_C(node->val.line, 1, "Undefined value");
            else {
                node->type_val=vn->type_idx;
                
                node->type_d=vn->d;
                node->left_val=vn->l_val;
            }
        }
        else{
            struct val_node * vn=findn(&f_hash, node->first_son->val.name);
            if(vn==NULL){
                vn=findn(&v_hash, node->first_son->val.name);
                if(vn!=NULL)ERROR_C(node->val.line, 11, "Call a non-function value");
                else ERROR_C(node->val.line, 2, "Undefined function");
            }
            else {
                node->type_val=vn->type_idx;
                node->type_d=0;
                node->left_val=vn->l_val;
                tree_node * args=node->first_son->next_brother->next_brother;
                if(eq(args->type_name, "RP")){
                    if(vn->next!=NULL)ERROR_C(node->val.line, 9, "Function parameters don't match");
                }
                else{
                    struct val_node * arg=vn->next;
                    for(tree_node * i=args;;i=i->first_son->next_brother->next_brother){
                        if(arg==NULL){
                            ERROR_C(i->val.line, 9, "Function parameters don't match");
                            break;
                        }
                        else if(!type_eq(i->type_val,arg->type_idx)||i->type_d!=arg->d){
                            ERROR_C(i->val.line, 9, "Function parameters don't match");
                            break;
                        }
                        else arg=arg->next;
                        if(i->first_son->next_brother==NULL){
                            if(arg!=NULL)ERROR_C(i->val.line, 9, "Function parameters don't match");
                            break;
                        }
                    }
                }
            }

        }
    }
    check_first_son(INT) pass_type(node, node->first_son);
    check_first_son(FLOAT) pass_type(node, node->first_son);
    check_first_son(MINUS){
        struct val_node * vn=findi(&t_hash, node->first_son->next_brother->type_val);
        if(vn!=NULL&& ((eq(vn->name, "int")&& node->first_son->next_brother->type_d==0) || (eq(vn->name, "float")&& node->first_son->next_brother->type_d==0))){
            pass_type(node, node->first_son->next_brother);
        }
        else ERROR_C(node->first_son->next_brother->val.line, 7, "Operands don't match");
    }
    check_first_son(NOT){
        struct val_node * vn=findi(&t_hash, node->first_son->next_brother->type_val);
        if(vn!=NULL&& ((eq(vn->name, "int")&& node->first_son->next_brother->type_d==0) )){
            pass_type(node, node->first_son->next_brother);
        }
        else ERROR_C(node->first_son->next_brother->val.line, 7, "Operands don't match");
    }
    check_first_son(LP) pass_type(node, node->first_son->next_brother);
    check_first_son(Exp){
        tree_node * o1=node->first_son;
        tree_node * op=node->first_son->next_brother;
        tree_node * o2=node->first_son->next_brother->next_brother;
        if(eq(op->type_name,"AND")||eq(op->type_name,"OR")){
            struct val_node * vn=findi(&t_hash, o1->type_val);
            if((vn!=NULL && eq(vn->name, "int"))&& o1->type_val==o2->type_val&& o1->type_d==0 && o2->type_d==0){
                pass_type(node, o1);
            }
            else ERROR_C(node->val.line, 7, "Operands don't match");
        }
        else if(eq(op->type_name,"RELOP")||eq(op->type_name,"PLUS")||eq(op->type_name,"MINUS")||eq(op->type_name,"STAR")||eq(op->type_name,"DIV")){
            struct val_node * vn=findi(&t_hash, o1->type_val);
            if((vn!=NULL && (eq(vn->name, "int")||eq(vn->name, "float")))&& o1->type_val==o2->type_val && o1->type_d==0 && o2->type_d==0){
                pass_type(node, o1);
                if(eq(op->type_name,"RELOP"))node->type_val=findn(&t_hash, "int")->type_idx;
            }
            else ERROR_C(node->val.line, 7, "Operands don't match");
        }
        else if(eq(op->type_name,"ASSIGNOP")){
            if(o1->left_val){
                if(!type_eq(o1->type_val, o2->type_val) || o1->type_d!=o2->type_d)
                    ERROR_C(node->val.line, 5, "Types don't match between assignop");
                else pass_type(node, o1);
            }
            else ERROR_C(node->val.line, 6, "Left value error");
            
        }
        else if(eq(op->type_name,"LB")){
            struct val_node * vn=findi(&t_hash, o1->type_val);
            if(vn!=NULL &&o1->type_d>0){
                vn=findi(&t_hash, o2->type_val);
                if((vn!=NULL && eq(vn->name, "int"))&& o2->type_d==0){
                    pass_type(node, o1);
                    node->type_d--;
                }
                else ERROR_C(node->first_son->next_brother->next_brother->val.line, 12, "A non-integer in array access");
            }
            else ERROR_C(node->val.line, 10, "Access non-array values");
        }
        else if(eq(op->type_name,"DOT")){
            struct val_node * vn=findi(&t_hash, node->first_son->type_val);
            tree_node * id=node->first_son->next_brother->next_brother;
            if(vn==NULL||(eq(vn->name, "int"))||(eq(vn->name, "float"))||node->first_son->type_d!=0)ERROR_C(node->val.line, 13, "Access non-struct values");
            else{
                struct val_node * tgt=NULL;
                for(struct val_node * i=vn->next;i!=NULL;i=i->next){
                    if(eq(i->name,id->val.name)){
                        tgt=i;
                    }
                }
                if(tgt!=NULL){
                    node->type_val=tgt->type_idx;
                    node->type_d=tgt->d;
                    node->left_val=tgt->l_val;
                }
                else ERROR_C(node->val.line, 14, "Undefined domain");

            }
        }
    }
}
check_rule(Args){
    pass_type(node, node->first_son);
}

void update_tree(tree_node * node){
    if(get_errstate())return ;
    add_check_rule(Program)
    add_check_rule(ExtDefList)
    add_check_rule(ExtDef)
    add_check_rule(ExtDecList)
    add_check_rule(Specifier)
    add_check_rule(StructSpecifier)
    add_check_rule(OptTag)
    add_check_rule(Tag)
    add_check_rule(VarDec)
    add_check_rule(FunDec)
    add_check_rule(VarList)
    add_check_rule(ParamDec)
    add_check_rule(CompSt)
    add_check_rule(StmtList)
    add_check_rule(Stmt)
    add_check_rule(DefList)
    add_check_rule(Def)
    add_check_rule(DecList)
    add_check_rule(Dec)
    add_check_rule(Exp)
    add_check_rule(Args)
    
    return ;
};