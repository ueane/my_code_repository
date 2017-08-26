/*************************************************************************
	> File Name: 10.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  8/10 08:10:58 2017
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b) ; (b) = __temp;\
}\

void heap_sort(int *arr, int n) {
    for(int i = 1; i < n; i++) {
        int current = i, father = (current - 1)/2;
        while(arr[current] > arr[father]) {
            swap(arr[current], arr[father]);
            current = father;
            father = (current - 1) /2;
        }
    }
    for(int i = n - 1; i >= 1; i--) {
        swap(arr[i], arr[0]);
        int l, r, max_val = 0;
        while(true) {
            l = 2*max_val + 1;
            r = 2*max_val + 2;
            if(l < i && arr[l] > arr[max_val]) {
                max_val = l;
            }
            if(r < i && arr[r] > arr[max_val]) {
                max_val = r;
            }
            if(max_val == r || max_val == l) {
                swap(arr[max_val], arr[(max_val - 1) / 2]);
            } else {
                break;
            }
        }
    }
    return ;
}



int main() {
   int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d",arr+i);
    }
    heap_sort(arr, n);
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
