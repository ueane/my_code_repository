/*************************************************************************
	> File Name: select_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  8/12 10:07:36 2017
 ************************************************************************/

#include<iostream>
using namespace std;

#define swap(a, b) { \
    __typeof(a) __temp = (a) ; \
    (a) = (b) ; (b) = (__temp); \
}

void select_sort(int a[], int n) {
    int min_index;
    for(int  i = 0; i < n - 1; i++) {
        min_index = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[min_index]) {
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
    }
}


int main() {


}
