/*************************************************************************
	> File Name: slist.cpp
	> Author: 
	> Mail: 
	> Created Time: 三  8/ 2 08:23:19 2017
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"test.h"


#define ERROR 0
#define OK 1

typedef struct vector {
    int size;
    int length;
    int *data;
}vector;

void init(vector *vec, int n = 50) {
    vec->size = n;
    vec->length = 0;
    vec->data = (int *)malloc(sizeof(int)*n);
}

int expand(vector *vec) {
    int *temp = vec->data;
    vec->data = (int *) realloc (vec->data,2 * vec->size * sizeof(int));
    if(vec->data == NULL) {
        vec->data = temp;
        return ERROR;
    }
    vec->size*=2;
    return OK;
}

int insert(vector *vec, int n, int index) {
    if(index < 0 || index > vec->length) {
        return ERROR;
    }
    if(vec->length == vec->size) {
        if(expand(vec) == ERROR) {
            return ERROR;
        }
    }
    for(int i = vec->length; i > index; i--) {
        vec->data[i] = vec->data[i-1];
    }
    vec->data[index] = n;
    vec->length++;
    return OK;
}

int delete_node(vector *vec, int index) {
    if(index < 0 || index >= vec->length) {
        return ERROR;
    }
    for(int i = index; i < vec->length - 1; i++) {
        vec->data[i] = vec->data[i+1];
    }
    vec->length--;
    return OK;
}

void clear(vector *vec) {
    if(vec->size == 0) {
        return ;
    }
    free(vec->data);
    free(vec);
}

void output(vector *vec) {
    if(vec->length != 0){
        printf("%d",vec->data[0]);
        for(int i = 1; i < vec->length; i++) {
            printf(" %d",vec->data[i]);
        }
        printf("\n");
    }
}

int main() {
    
    int n,m,ind;
    vector *s = (vector *) malloc (sizeof(vector));
    init(s);
    while(scanf("%d%d",&n,&m) != EOF) {
        if(n == 0) {
            scanf("%d",&ind);
            insert(s,m,ind);
            output(s);
        }
        else if(n == 1) {
            delete_node(s,m);
            output(s);
        }
        else {
            printf("ERROR\n");
        }
    }
    
    return 0;
}

TEST(vector, insert) {
    vector *s = (vector*)malloc(sizeof(vector));
    init(s,100);
    for(int i = 0; i < 10; i++) {
        ASSERT_EQ(insert(s, i+1, i), OK);
    }
}


TEST(vector, delete_node) {
    vector *s = (vector*)malloc(sizeof(vector));
    init(s,100);
    for(int i = 0; i < 10; i++) {
        insert(s, i+1, i);
    }
    for(int i = 0; i < 10; i++) {
        ASSERT_EQ(delete_node(s,0),OK);
    }
}

TEST(vector, expand) {
    vector *s = (vector*)malloc(sizeof(vector));
    init(s,2);
    for(int i = 0; i < 2; i++) {
        insert(s, i+1, i);
    }
    int flag;
    for(int i = 2; i < 4; i++) {
        flag = insert(s, i+1, i);
    }
        ASSERT_EQ(flag, OK);
    for(int i = 4; i < 9; i++) {
        flag = insert(s, i+1, i);
    }
    ASSERT_EQ(flag, OK);
}
