#include <stdio.h>
#include <stdlib.h>
 
#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b); (b) = __temp; \
}
 
typedef struct DataInfo {
    char ch;
    int freq;
} DataInfo;
 
typedef struct Node {
    DataInfo data;
    struct Node *lchild, *rchild;
} Node;
 
int cmp_node(DataInfo a, DataInfo b) {
    if (a.freq <= b.freq) return 1;
    return 0;
}
 
Node *init(char ch, int freq) {
    DataInfo data;
    data.ch = ch;
    data.freq = freq;
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}
 
char get_ch(int ind) {
    if (ind < 26) return ind + 'a';
    return ' ';
}
 
int get_ind(char ch) {
    if (ch == '@') return -1;
    if (ch <= 'z' && ch >= 'a') return ch - 'a';
    return 26;
}
 
void get_encode(Node *tree, char encode[][28], char *buffer) {
    if (tree == NULL) return ;
    if (get_ind(tree->data.ch) != -1) {
        for (int i = 1; i <= buffer[0]; i++) {
            encode[get_ind(tree->data.ch)][i] = buffer[i];
        }
        encode[get_ind(tree->data.ch)][0] = buffer[0];
        return ;
    }
    buffer[++buffer[0]] = '0';
    get_encode(tree->lchild, encode, buffer);
    buffer[0]--;
    buffer[++buffer[0]] = '1';
    get_encode(tree->rchild, encode, buffer);
    buffer[0]--;
    return ;
}
 
int main() {
    Node *arr[27];
    int freq;
    for (int i = 0; i < 27; i++) {
        scanf("%d", &freq);
        arr[i] = init(get_ch(i), freq);
    }
    for (int i = 0; i < 26; i++) {
        if (cmp_node(arr[1]->data, arr[0]->data)) {
            swap(arr[0], arr[1]);
        }
        for (int j = 2; j < 27 - i; j++) {
            if (cmp_node(arr[j]->data, arr[0]->data)) {
                swap(arr[0], arr[1]);
                swap(arr[j], arr[0]);
            } else if (cmp_node(arr[j]->data, arr[1]->data)) {
                swap(arr[j], arr[1]);
            }
        }
        printf("combin : %c(%d) %c(%d)\n",
               arr[0]->data.ch, arr[0]->data.freq, arr[1]->data.ch, arr[1]->data.freq);
        Node *temp = init('@', arr[0]->data.freq + arr[1]->data.freq);
        temp->lchild = arr[0];
        temp->rchild = arr[1];
        arr[0] = temp;
        for (int j = 2; j < 27 - i; j++) {
            arr[j - 1] = arr[j];
        }
    }
    char encode[28][28] = {0};
    Node *halfman_tree_root = arr[0];
    get_encode(halfman_tree_root, encode, encode[27]);
    for (int i = 0; i < 27; i++) {
        printf("%c : %s\n", get_ch(i), encode[i] + 1);
    }
    return 0;
}