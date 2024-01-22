#include "hash.h"
#include <stdlib.h>
#include <string.h>
int get_hash(const char * name, int n){
    int hash=0;
    for(int i=0;name[i]!='\0';i++)hash^=(((int)(name[i]))<<((i%4)*8));
    return hash%n;
}

void init(int n, struct hash_table * hash){

    hash->u_list=malloc(sizeof(struct val_node *)*n);
    
    for(int i=0;i<n;i++)hash->u_list[i]=NULL;
    hash->n=n;
}

int insert(struct hash_table * hash, const char * name, struct val_node * entry){
    int code=get_hash(name, hash->n);
    for(int i=code;;i=(i+1)%hash->n){
        if(hash->u_list[i]==NULL){
            hash->u_list[i]=entry;
            return i;
        }
        if((i+1)%hash->n==code)return -1;
    }
}

struct val_node * findn(struct hash_table * hash, const char * name){
    int code=get_hash(name, hash->n);
    for(int i=code;;i=(i+1)%hash->n){
        if(hash->u_list[i]==NULL);
        else if(strcmp(hash->u_list[i]->name, name)==0)return hash->u_list[i];
        if((i+1)%hash->n==code)return NULL;
    }
}

struct val_node * findi(struct hash_table * hash, int idx){
    if(idx<0)return NULL;
    return hash->u_list[idx];
}

struct val_node * make_type_insert(struct hash_table * hash, const char * name){
    struct val_node * vn=findn(hash, name);
    if(vn==NULL){
        vn=malloc(sizeof(struct val_node));
        strcpy(vn->name, name);
        vn->d=-1;
        vn->l_val=0;
        vn->next=NULL;
        vn->type_idx=insert(hash, name, vn);
    }
    return vn;
}

int make_val_insert(struct hash_table * hash, const char * name, int l_v){
    struct val_node * vn=findn(hash, name);
    if(vn==NULL){
        vn=malloc(sizeof(struct val_node));
        strcpy(vn->name, name);
        vn->d=0;
        vn->temp_idx=-1;
        vn->type_idx=-1;
        vn->l_val=l_v;
        vn->next=NULL;
        vn->idx=insert(hash, name, vn);
        return vn->idx;
    }
    else return -(vn->idx)-1;
    
}
