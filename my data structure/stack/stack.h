 
#ifndef _STACK_H
#define _STACK_H
 
#define ERROR 0
#define OK 1
 
typedef struct Stack {
    int *data;
    int size, top;
} Stack;
 
void init_stack(Stack *s, int n);
int push_stack(Stack *s, int value);
int pop_stack(Stack *s);
int seek_stack(Stack *s);
int emtpy_stack(Stack *s);
void output_stack(Stack *s);
void clear_stack(Stack *s);
 
#endif