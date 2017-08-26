/*************************************************************************
	> File Name: kmp.cpp
	> Author: 
	> Mail: 
	> Created Time: 二  8/15 08:05:58 2017
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void get_next(char *t, int *next) {
    next[0] = -1;
    int j = 1, match = -1;
    while(t[j]) {
        while(match != -1 && t[match + 1] != t[j]) {
            match = next[match];
        }
        if(t[match + 1] == t[j]){
            next[j] = match + 1;
            match++;
        } else {
            next[j] = match;
        }
        j++;
    }
    return 0;
}

void kmp_match(char *s, char *t, int *next) {
    int i = 0, j = 0;
    int times = 0;
    while(s[i]) {
        while(j != -1 && t[j + 1] != s[i]) {
            times++;
            j = next[j];
        }
        if(t[j + 1] == s[i]) {
            times++;
            j++;
        }
        i++;
        if(t[j + 1] == '\0') {
            printf("yes\n");
            return;
        }    
    }
    printf("no\n");
}

int main() {
    int next[100];
    char s[] = "aecaeaecaed";
    char t[] = "aecaed";
    get_next(t, next);
    for(int i = 0; t[i]; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");
    kmp_match(s, t, next);
    
    return 0;
}
