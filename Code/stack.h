#ifndef STK
#define STK

#define STK_SIZE 1024
//n>>4:idx
//n&xf:type
/*
type:
0 FAIL
1 SUCCESS
2 RETURN
3 OVER
*/
struct stack
{
    int s[STK_SIZE];
    int top;
};

typedef struct stack stack_t;

void initstk(stack_t * stk);
int empty(stack_t * stk);
void push(stack_t * stk, int n);
int top(stack_t * stk);
void pop(stack_t * stk);

#endif