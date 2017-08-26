/*************************************************************************
	> File Name: insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  8/12 08:49:33 2017
 ************************************************************************/

#include<iostream>
using namespace std;

#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b) ; (b) = __temp; \
}


int a[1000];

void insert_sort(int a[], int n) {
    for(int i = 1; i < n; i++) {
        for(int j = i; j >= 1; --j) {
            if(a[j] < a[i - 1]) {
                swap(a[j], a[j - 1]);
            } else break;
        }
    }
    return ;
}

void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    insert_sort(a, n);
    output(a, n);
    return 0;
}
