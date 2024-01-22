#include "syntax_tree.h"
#include "hash.h"
#include "parser.tab.h"
#include "syntax_check_update.h"
#include <stdlib.h>
#include <string.h>

tree_node * get_root(){
    return tree_root;
}

void set_errstate(){
    err=1;
}

int get_errstate(){
    return err;
}

tree_node * back_to(tree_node * now){
    return now->father;
}

tree_node * to_first_son(tree_node * now){
    return now->first_son;
}

tree_node * to_next_bro(tree_node * now){
    return now->next_brother;
}

tree_node * create_node(){
    tree_node * new_node=malloc(sizeof(tree_node));
    new_node->father=NULL;
    new_node->first_son=NULL;
    new_node->next_brother=NULL;
}

tree_node * add_node(tree_node * father, tree_node * now){
    if(now==NULL)return NULL;
    if(father==NULL)tree_root=now;
    else{
        now->father=father;
        if(father->first_son==NULL)father->first_son=now;
        else{
            tree_node * i;
            for(i=father->first_son; i->next_brother!=NULL; i=i->next_brother);
            i->next_brother=now;
        }
    }
    return now;
}

void print_tree(tree_node * now, int level, FILE * fp){
    if(err)return ;
    if(now==NULL)return ;
    for(int i=0;i<level;i++)fprintf(fp,"  ");
    fprintf(fp,"%s", now->type_name);
    switch (now->mode)
    {
    case 0: 
        if(now->val.type==ITYPE)fprintf(fp,": int");
        else if(now->val.type==FTYPE)fprintf(fp,": float");
        fprintf(fp,"\n");
        break;

    case 1: 
        fprintf(fp,": %s\n", now->val.name);
        break;
    
    case 2: 
        fprintf(fp,": %u\n", now->val.inum);
        break;

    case 3: 
        fprintf(fp,": %f\n", now->val.fnum);
        break;
    
    case 4: 
        fprintf(fp," (%d)\n", now->val.line);
        break;
    default:
        break;
    }
    print_tree(now->first_son, level+1,fp);
    print_tree(now->next_brother, level,fp);
}

void del_tree(tree_node * now){
    if(now==NULL)return ;
    del_tree(now->first_son);
    del_tree(now->next_brother);
    free(now);
}

tree_node * make_line_node(const char * name, int line){
    tree_node * new_node=create_node();
    strcpy(new_node->type_name, name);
    new_node->mode=4;
    new_node->val.line=line;
    new_node->type_val=-1;
    new_node->type_d=-1;
    new_node->left_val=0;
    new_node->temp_idx=-1;
    new_node->lab_mode=-1;
    new_node->ptr=0;
    return new_node;
}

tree_node * make_common_token_node(const char * name, int type){
    tree_node * new_node=create_node();
    strcpy(new_node->type_name, name);
    if(eq(name,"STRUCT"))now_struct++;
    new_node->mode=0;
    new_node->val.type=type;
    new_node->type_val=-1;
    new_node->type_d=-1;
    new_node->left_val=0;
    return new_node;
}

tree_node * make_intb10_node(const char * text){
    tree_node * new_node=create_node();
    strcpy(new_node->type_name, "INT");
    new_node->mode=2;
    int num=-1;
    char s[10];
    int res=sscanf(text, "%u%s", &num, s);
    if(res!=1)return NULL;
    new_node->val.inum=num;
    //printf("%d", t_hash.n);
    struct val_node * vn=make_type_insert(&t_hash, "int");
    new_node->type_val=vn->type_idx;
    new_node->type_d=0;
    new_node->left_val=0;
    return new_node;
}

tree_node * make_intb16_node(const char * text){
    tree_node * new_node=create_node();
    strcpy(new_node->type_name, "INT");
    new_node->mode=2;
    int num=-1;
    char s[10];
    int res=sscanf(text, "0%*c%x%s", &num, s);
    if(res!=1)return NULL;
    new_node->val.inum=num;
    new_node->type_val=make_type_insert(&t_hash, "int")->type_idx;
    new_node->type_d=0;
    new_node->left_val=0;
    return new_node;
}

tree_node * make_intb8_node(const char * text){
    tree_node * new_node=create_node();
    strcpy(new_node->type_name, "INT");
    new_node->mode=2;
    int num=-1;
    char s[10];
    int res=sscanf(text, "0%o%s", &num, s);
    if(res!=1)return NULL;
    new_node->val.inum=num;
    new_node->type_val=make_type_insert(&t_hash, "int")->type_idx;
    new_node->type_d=0;
    new_node->left_val=0;
    return new_node;
}

tree_node * make_float_node(const char * text){
    tree_node * new_node=create_node();
    strcpy(new_node->type_name, "FLOAT");
    new_node->mode=3;
    new_node->val.fnum=atof(text);
    new_node->type_val=make_type_insert(&t_hash, "float")->type_idx;
    new_node->type_d=0;
    new_node->left_val=0;
    return new_node;
}

tree_node * make_id_node(const char * text){
    if(strlen(text)>=32)return NULL;
    tree_node * new_node=create_node();
    strcpy(new_node->type_name, "ID");
    new_node->mode=1;
    strcpy(new_node->val.name, text);
    new_node->type_val=-1;
    new_node->type_d=-1;
    new_node->left_val=1;
    return new_node;
}

void pass_type(tree_node * x, tree_node * y){
    x->type_val=y->type_val;
    x->type_d=y->type_d;
    x->left_val=y->left_val;
}
