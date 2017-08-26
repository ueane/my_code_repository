#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define INIT_STACK(s, n, T) (init_stack(s, n, sizeof(T)))
#define PUSH_STACK(s, value) ({ \
    __typeof(value) __temp = (value); \
    push_stack(s, (const char *)&(__temp)); \
})
//() 这个小括号是为了将内部的转换成表达式, 返回值是宏中的最后一行

#define EMPTY_STACK(s) (empty_stack(s))
#define TOP_STACK(s, T) (*((T *)top_stack(s)))
#define POP_STACK(s) (pop_stack(s))
#define CLEAR_STACK(s) (clear_stack(s))
#define MC(T, n)((T*)malloc(sizeof(T) * n))



typedef struct Stack {
    char *data;
    int top, size;
    int value_size;
} Stadk;

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

typedef struct preorderargs {
    Node *root;
    int status;
} preorderargs;


void quick_sort(int *arr, int l, int r) {
    if(r <= l) return ;
    int x,y,z;
    x = l, y = r, z = arr[l];
    while(x < y) {
        while(x < y && arr[y] >= z) --y;
        if(x < y) arr[x++] = arr[y];
        while(x < y && arr[x] <= z) ++x;
        if(x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x - 1);
    quick_sort(arr, x + 1, r);
    return ;
}





int __preorder(Node *root) {
   // if(root == NULL) return 1; //0号代码段
    printf("%d ", root->val); // 存储递归过程中的重要变量
   // root->lchild && preorder(root->lchild);
   // root->rchild && preorder(root->rchild);
    return 1;
}

int __order(Node *root) {
    //if(roor == NULL) return 1;
    //root->lchild && preorder(root->lchild);
    //root->rchild && preorder(root->rchild);
    printf("%d ", root->val);
    return 1;
}


int order(Node *root) {
    Stack *s = MC(Stack, 1);
    INIT_STACK(s, 1000, preorderargs);
    preorderargs pa;
    pa.root = root;
    pa.status = 0;
    while(!EMPTY_STACK(s)) {
        preorderargs *tpa =&TOP_STACK(s, preorderargs).status;
        switch (TOP_STACK(s, preorderargs).status) {
            case 0: 
                if (tpa.root == NULL) {
                    tpa->status = 4;
                    break;
                } else {
                    tpa->status = 3;
                }
                break;
            case 3:
                __order(tpa->root);
                tpa->status = 4;
                break;
            case 1:
                if(tpa->root->lchild) {
                    pa.root = tpa->root->lchild;
                    pa.status = 0;
                    PUSH_STACK(s, pa);
                }
                tpa->status = 1;
                break;
            case 2:
                if(tpa->root->rchild) {
                    pa.root = tpa->root->rchild;
                    pa.status = 0;
                    PUSH_STACK(s, pa);
                }
                tpa->status = 4;
                break;
            case 4:
                POP_STACK(s);
                break;
            default :
                printf("0\n");
        }
    }
    return 1;
}
int preorder(Node *root) {
    Stack *s = MC(Stack, 1);
    INIT_STACK(s, 1000, preorderargs);
    preorderargs pa;
    pa.root = root;
    pa.status = 0;
    while(!EMPTY_STACK(s)) {
        preorderargs *tpa =&TOP_STACK(s, preorderargs).status;
        switch (TOP_STACK(s, preorderargs).status) {
            case 0: 
                if (tpa.root == NULL) {
                    tpa->status = 4;
                    break;
                } else {
                    tpa->status = 1;
                }
                break;
            case 1:
                __preorder(tpa->root);
                tpa->status = 2;
                break;
            case 2:
                if(tpa->root->lchild) {
                    pa.root = tpa->root->lchild;
                    pa.status = 0;
                    PUSH_STACK(s, pa);
                }
                tpa->status = 3;
                break;
            case 3:
                if(tpa->root->rchild) {
                    pa.root = tpa->root->rchild;
                    pa.status = 0;
                    PUSH_STACK(s, pa);
                }
                tpa->status = 4;
                break;
            case 4:
                POP_STACK(s);
                break;
            default :
                printf("0\n");
        }
    }
    return 1;
}
void init_stack(Stack *s, int n, int value_size) {
    s->data = (char *)malloc(value_size * n);
    s->top = -1;
    s->size = n;
    s->value_size = value_size;
    return ;
}

int push_stack(Stack *s, const char *value) {
    if(s->top == s->size - 1) 
        return 0;
    ++(s->top);
    memcpy(s->data + s->top * s->value_size, value, s->value_size);
    return 1;
}

int empty_stack(Stack *s) {
    return s->top == -1;
}

int pop_stack(Stack *s) {
    if(empty_stack(s)) {
        return 0;
    }
    --(s->top);
    return 1;
}

char *top_stack(Stack *s) {
    if(empty_stack(s)) {
        return NULL;
    }    
    return s->data + s->top * s->value_size;
}

void clear_stack(Stack *s) {
    free(s->data);
    free(s);
}

int main() {
    Stack *s = MC(Stack, 1);
    INIT_STACK(s, 100, double);
    PUSH_STACK(s, 3.6);
    PUSH_STACK(s, 7.8);
    while(!EMPTY_STACK(s)) {
        printf("%lf\n", TOP_STACK(s, double));
        POP_STACK(s);
    }
    CLEAR_STACK(s);
    return 0;
}
