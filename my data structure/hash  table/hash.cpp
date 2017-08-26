/*************************************************************************
	> File Name: hash.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  8/13 08:37:28 2017
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define MC(T,n) (T*)malloc(sizeof(T) * n)


typedef struct hashtable{
    char **data;
    int size;
}hashtable;

void init(hashtable *h, int n) {
    h->data = (char **)malloc(sizeof(char) * n);
    memset(h->data, 0, sizeof(char *) * n);
    h->size = n;
}

int hash_code(hashtable *h, const char *value) {
    unsigned int code = 0;
    for(int i = 0; value[i]; i++) {
        code = (code << 3) ^ value[i] ^ (code >> 5);
    }
    return (int)(code % h->size);
}

int search(hashtable *h, char *value) {
    int index = hash_code(h, value);
    int times = 0;
    while(h->data[index] != NULL) {
        if(strcmp(h->data[index], value) == 0) return 1;
        times++;
        index += times * times;
        index %= h->size;
    }
    return 0;
}

int insert(hashtable *h, char * value) {
    int index = hash_code(h, value);
    int times = 0;
    while(h->data[index] != NULL) {
        times++;
        index += times * times;
        index %= h->size;
    }
    h->data[index] = strdup(value);
    return 1;
}



void clear(hashtable *h) {
    for(int i = 0; i < h->size; i++) {
        if(h->data[i] != NULL){
            free(h->data[i]);
        }
    }
    free(h->data);
    free(h);
}

int main() {
    hashtable *h = MC(hashtable, 1);
    init(h, 100);
    printf("%d\n", hash_code(h, "ab"));
    printf("%d\n", hash_code(h, "ba"));

    return 0;
}

