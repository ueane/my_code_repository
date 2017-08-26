#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct node
{
    int num;
    char str;
}node;

typedef struct tree{
    node k;
    struct tree *l, *r;
} tree, *ptree;

ptree init(char str,int num) {
    ptree p = (tree*)malloc(sizeof(tree));
    p->k.num = num;
    p->k.str = str;
    p->l = NULL;
    p->r = NULL;
    return p;
}

ptree insert(ptree s1, ptree s2) {
    ptree p = (tree*)malloc(sizeof(tree));
    p->k.str = '#';
    p->k.num = s1->k.num + s2->k.num;
    p->l = s1;
    p->r = s2;
    return p;
}

void output(ptree p) {
    if (p == NULL) {
        return ;
    }
    printf("%c", p->k.str);
    if (p->l == NULL && p->r == NULL) {
        return ;
    }
    printf("(");
    if (p->l) {
        output(p->l);
    }
    if (p->r) {
        printf(",");
        output(p->r);
    }
    printf(")");
    return ;
}

void find(ptree p, char ch, char *s, int len) {
    if(p->l == NULL && p->r == NULL && p->k.str != ch) {
        return ;
    }
    if(p->l == NULL && p->r == NULL && p->k.str == ch) {
        //strncpy(s, str, len);
        printf("%d\n", len);
    }
    if(p->l != NULL) {
        find(p->l, ch, s, len * 10);
    }
    if(p->r != NULL) {

        find(p->r, ch, s, len * 10 + 1);
    }
    return ;
}



int main() {
    ptree p[3000] = {0};
    int a[3000];

    memset(a,-1,sizeof(a));

    for(int i = 0; i < 26; i++) {
        scanf("%d", &a[i]);
    }
  
    for(int i = 0; i < 26; i++) {
        p[i] = init(i + 'a', a[i]);
    }

    int sum = 0;
    int z = 26;
    while(1) {
        sum = 0;
        for(int i = 0; i < 1000; i++) {
            if(a[i] == -1) {
                sum++;
            }
        }
        if(sum == 999) break;
        int book = 0, minn = 0x3f3f3f3f, book2 = 0;
        for(int i = 0; i < 1000; i++) {
            if(a[i] != -1 && minn > a[i]) {
                book = i;
                minn = a[i];
            }
        }
        a[book] = -1, minn = 0x3f3f3f3f;
        for(int i = 0; i < 1000; i++) {
            if(a[i] != -1 && minn > a[i]) {
                book2 = i;
                minn = a[i];
            }
        }
        a[book2] = -1;
        
        p[z] = insert(p[book], p[book2]);
        a[z] = p[z]->k.num;    
        z++;
    }
    
    int i;
    for(i = 0; i < 1000; i++) {
        if(a[i] != -1) {
            break;  
        }
    }

    output(p[i]);
    fflush(stdout);

    
    printf("\n");
    
    for(int j = 0; j < 26; j++) {
        char ans[100];
        printf("%c : ", j + 'a');
        find(p[i], j+'a', ans, 0);
        //printf("%s", ans);
        fflush(stdout);
    }
    

    return 0;
}
