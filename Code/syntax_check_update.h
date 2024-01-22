#ifndef SCU
#define SCU

#include "syntax_tree.h"
#include "hash.h"

#define ERROR_C(loc, errno, msg) printf("Error type %d at Line %d: %s.\n", errno, loc, msg)
#define eq(n1, n2) strcmp(n1, n2)==0
#define name_eq(n_name) strcmp(node->type_name, n_name)==0
#define check_rule(n_name) void check_##n_name(tree_node * node)
#define add_check_rule(n_name) else if(name_eq(#n_name))check_##n_name(node);
#define check_first_son(n_name) else if(eq(node->first_son->type_name, #n_name))
#define blank {return ;}

void update_tree(tree_node * node);

extern struct hash_table v_hash, t_hash, f_hash;
extern int now_struct;

void init_hash();
char * get_name();

#endif