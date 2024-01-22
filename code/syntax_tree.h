#ifndef SYT
#define SYT

#include<stdio.h>




static int errline=0;
struct syntex_tree_node
{
    char type_name[38];
    int mode;
    union
    {
        int type;
        char name[38];
        unsigned int inum;
        float fnum;
        int line;
    } val;

    int type_val;
    int type_d;
    char left_val;

    int temp_idx;
    int ptr;
    int lab_mode;

    struct syntex_tree_node * first_son, * next_brother, * father;
};

typedef struct syntex_tree_node tree_node;

static tree_node * tree_root=NULL;
static int err=0;

tree_node * get_root();

void set_errstate();

int get_errstate();

tree_node * back_to(tree_node * now);

tree_node * to_first_son(tree_node * now);

tree_node * to_next_bro(tree_node * now);

tree_node * create_node();

tree_node * add_node(tree_node * father, tree_node * now);

void print_tree(tree_node * now, int level, FILE * fp);

void del_tree(tree_node * now);

tree_node * make_line_node(const char * name, int line);

tree_node * make_common_token_node(const char * name, int type);

tree_node * make_intb10_node(const char * text);

tree_node * make_intb16_node(const char * text);

tree_node * make_intb8_node(const char * text);

tree_node * make_float_node(const char * text);

tree_node * make_id_node(const char * text);

void pass_type(tree_node * x, tree_node * y);





#endif