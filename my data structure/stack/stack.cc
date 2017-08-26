#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
 
void init_stack(Stack *s, int n) {
    s->data = (int *)malloc(n * sizeof(int));
    s->size = n;
    s->top = -1;
}
 
int push_stack(Stack *s, int value) {
    if (s->top == s->size - 1) {
        return ERROR;
    }
    ++s->top;
    s->data[s->top] = value;
    return OK;
}
 
int pop_stack(Stack *s) {
    if (emtpy_stack(s)) {
        return ERROR;
    }
    --s->top;
    return OK;
}
 
int seek_stack(Stack *s) {
    return s->data[s->top];
}
 
int emtpy_stack(Stack *s) {
    return s->top == -1;
}
 
void output_stack(Stack *s) {
    for (int i = s->top; i >= 0; --i) {
        printf("|\t%5d\t|\n", s->data[i]);
        printf("|---------------|\n");
    }
    printf("\n");
}
 
void clear_stack(Stack *s) {
    free(s->data);
    free(s);
}