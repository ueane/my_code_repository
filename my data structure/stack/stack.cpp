#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
    srand(time(0));
    Stack *s = (Stack *)malloc(sizeof(Stack));
    init_stack(s, 100);
    char ch;
    while (scanf("%c", &ch) != EOF) {
        int opr, value;
        opr = rand() % 3;
        value = rand() % 100;
        if (opr != 0) {
            push_stack(s, value);
            printf("push %d\n", value);
        } else {
            pop_stack(s);
            printf("pop queue\n");
        }
        output_stack(s);
    }
    clear_stack(s);
    return 0;
}