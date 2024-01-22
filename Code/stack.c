#include "stack.h"
#include <string.h>
void initstk(stack_t * stk){
    stk->top=0;
}
int empty(stack_t * stk){
    return stk->top==0;
}
void push(stack_t * stk, int n){
    stk->s[stk->top]=n;
    stk->top++;
}
int top(stack_t * stk){
    return stk->s[stk->top-1];
}
void pop(stack_t * stk){
    stk->top--;
}