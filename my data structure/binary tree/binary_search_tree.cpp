/*************************************************************************
	> File Name: tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  8/ 8 08:09:26 2017
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"test.h"
#include<time.h>

typedef  struct Node {
    int data;
    struct Node *lchild, *rchild;
} Node , *Tree;

Node *init(int data) {
    Node *p = (Node *)malloc(sizeof(Node ));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}

Node *insert(Tree bt, int data) {
    if (bt == NULL) {
        bt = init(data);
    }
    if (bt->data > data) {
        bt->lchild = insert(bt->lchild, data);
    } else if(bt->data < data) {
        bt->rchild = insert(bt->rchild, data);
    }
    return bt;
}

Node *search(Tree bt, int data) {
    if(bt == NULL || bt->data == data) {
        return bt;
    }
    if(bt->data > data) {
        return search(bt->lchild, data);
    } else {
        return search(bt->rchild, data);
    }
}

void clear(Tree bt) {
    if(bt == NULL) {
        return ;
    }
    clear(bt->lchild);
    clear(bt->rchild);
    free(bt);
}

void preorder(Tree bt) {
    if(bt == NULL) return ;
    printf("%d ",bt->data);
    preorder(bt->lchild);
    preorder(bt->rchild);
}

void inorder(Tree bt) {
    if(bt == NULL) return ;
    inorder(bt->lchild);
    printf("%d ",bt->data);
    inorder(bt->rchild);
}


void inorder1(Tree bt, int *k) {
    if(bt == NULL) return ;
    inorder1(bt->lchild,&*k);
    *k = *k + 1;
    inorder1(bt->rchild,&*k);
}


void postorder(Tree bt) {
    if(bt == NULL) return ;
    postorder(bt->lchild);
    postorder(bt->rchild);
    printf("%d ",bt->data);
}

int main() {
#ifdef abc
    Tree tree = NULL;
    int opr, n;
    while(scanf("%d", &opr) != EOF) {
        switch(opr) {
            case 0 : 
                scanf("%d", &n);
                tree = insert(tree, n);
                break;
            case 1 :
                scanf("%d",&n);
                printf("%p\n", search(tree, n));
                break;
            case 2 : preorder(tree);printf("\n"); break; 
            case 3 : inorder(tree); printf("\n"); break;
            case 4 : postorder(tree); break;
        }
    }
#endif
    return 0;
}

TEST (bt_tree, insert) {
    Tree tree = NULL, p = NULL, q = NULL;
    int n;
    for(int i = 0; i < 5; i++) {
        n = rand() % 100;
        tree = insert(tree, n);
        p = search(tree, n);
        ASSERT_EQ(p->data, n);
    }
}

TEST (bt_tree, search) {
    Tree tree = NULL, p = NULL;
    int a[100];
    for(int i = 0; i < 5; i++) {
        a[i] = rand() % 100;
        tree = insert(tree, a[i]);
    }
    for(int i = 0; i < 5; i++) {
        p = search(tree, a[i]);
        ASSERT_EQ(p->data, a[i]);
    }
}


TEST (bt_tree, insert2) {
    Tree tree = NULL, p = NULL, q = NULL;
    int n;
    int a[100];
    for(int i = 0; i < 5; i++) {
        n = rand() % 100;
        tree = insert(tree, n);
    }
    int k = 0;

    inorder1(tree,&k);                                             
    printf("%d\n", k);
}






