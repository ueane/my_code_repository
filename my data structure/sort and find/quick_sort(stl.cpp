/*************************************************************************
	> File Name: quick_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  8/12 10:24:04 2017
 ************************************************************************/
#include<stdio.h>
#include<iostream>
#include<time.h>

#define swap(a, b) { \
    __typeof (a) __temp = (a);\
    (a) = (b); (b) = __temp;\
}

using namespace std;
int a[100];


void quick_sort(int a[], int l, int r) {
    while(r - l > 0) {
    

    int x = l, y = r;
    int rand_index = rand() % (r - l + 1);
    swap(a[rand_index + l], a[l]);
    int z = a[l];
    while(x < y) {
        while(x < y && z < a[y])  --y;
        if(x < y) a[x++] = a[y];    
        while(x < y && a[x] < z) ++x;
        if(x < y) a[y--] = a[x];
    }
    a[x] = z;
    //quick_sort(a, l, x - 1);
    quick_sort(a, x + 1, r);
    r = x - 1;
    

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
    srand(time(0));
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&a[i]);
    }
    quick_sort(a, 0, n - 1);
    output(a, n);
    return 0;
}
