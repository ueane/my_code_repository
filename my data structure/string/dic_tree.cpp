/*************************************************************************
	> File Name: dic_tree.cpp
	> Author: 
	> Mail: 
	> Created Time: 一  8/21 09:26:57 2017
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MC(T, n) (T*)malloc(sizeof(T) * n)
#define CC(T, n) (T*)calloc(n , sizeof(T));


typedef struct Node {
    int flag;
    struct Node *next[26];
    struct Node *fail;
} Node;

Node *get_new_node() {
    Node *p = CC(Node , 1);
    return p;
}

int insert(Node *tree, char *str) {
    Node *p = tree;
    while(str[0]) {
        if (p->next[str[0] - 'a'] == NULL) {
            p->next[str[0] - 'a'] = get_new_node();
        }   
        p = p->next[str[0] - 'a'];
        str++;
    }
    p->flag++;
    return 1;
}

void clear(Node *tree) {
    if(tree == NULL) return ;
    for(int i = 0; i < 26; i++) {
        clear(tree->next[i]);
    }
    free(tree);
    return ;
}

void output(Node *tree, int k, char *pos) {
    pos[k] = '\0';
    while((tree->flag)--) printf("%s\n", pos);

    for(int i = 0; i < 26; i++) {
        if(tree->next[i] != NULL) {
            pos[k] = i+'a';
            output(tree->next[i], k + 1, pos);
        }
    }
}

Node *__get_automaton_fail(Node *father, int index, Node *root) {
    if (father == root) {
        return root;
    }
    if (father->fail == NULL) {
        father_fail = __get_automaton_fail(father_father, )
    }
    if (father_fail->next[index] != NULL) {
        return father_fail->next[index];
    }
    if (father_fail->fail == root) {
        return root;
    } 
    int 
    if (father_fail->fail == NULL) {
        


    }
    
    
}

void __build_automaton(Node *node, Node *root) { //当前节点 , 根节点
    for(int i = 0; i < 26; i++) {
        if(tree->next[i] == NULL) continue;
        node->next[i].fail = __get_automaton_fail(node->fail, i, root);
    }
    
    
    
    
    
}

void build_automaton(Node *tree) {
    __build_automaton(tree, tree);
}

int main() {
    Node *tree = get_new_node();
    int n;
    char str[100];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        insert(tree, str);
    }

    tree.fail = NULL;
    build_automaton(tree);
    

//    char s[100];

 //   output(tree, 0, s);


    return 0;
}
