#ifndef HASH
#define HASH

struct hash_table{
   struct val_node ** u_list;
    int n;
};


int get_hash(const char * name, int n);

void init(int n, struct hash_table * hash);

int insert(struct hash_table * hash, const char * name, struct val_node * entry);

struct val_node * findn(struct hash_table * hash, const char * name);

struct val_node * findi(struct hash_table * hash, int idx);

struct val_node * make_type_insert(struct hash_table * hash, const char * name);

int make_val_insert(struct hash_table * hash, const char * name, int l_v);

void del(struct hash_table * hash);


struct val_node{
    char name[260];
    int idx;
    int temp_idx;
    int type_idx;
    int d;
    int total_size;
    int d_size[10];
    int l_val;
    struct val_node * next;
};



#endif