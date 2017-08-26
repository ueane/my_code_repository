/*************************************************************************
	> File Name: bubble_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  8/12 08:49:03 2017
 ************************************************************************/

#include<iostream>
using namespace std;
int a[1000];

#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b) ; (b) = __temp; \
}

void bubble_sort(int a[], int n) {
    int times = 1;
    for(int i = n - 1; i >= 1 && times; i--) {
        times = 0;
        for(int j = 0; j < i; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                times++;
            } 
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
    bubble_sort(a, n);
    output(a, n);

    return 0;
}
