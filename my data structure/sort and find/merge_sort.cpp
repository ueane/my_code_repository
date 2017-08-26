/*************************************************************************
	> File Name: merge_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: 六  8/12 08:49:52 2017
 ************************************************************************/

#include<iostream>
using namespace std;


int a[1000];

void merge_sort(int a[], int l, int r) {
    if(r < l) return ;
    if(r == l) return ;
    if(r - l == 1) {
        if(a[l] > a[r]) {
            swap(a[l], a[r]);
        }
        return ;
    }
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);
    merge_sort(a, mid + 1, r);
    int *temp = (int *)malloc((r - l + 1) * sizeof(temp));
    
    int ind1 = l, ind2 = mid + 1, k = 0;
    while(ind1 <= mid || ind2 <= r) {
        if(ind2 > r) {
            temp[k++] = a[ind1++];
        } else if(ind1 > mid) {
            temp[k++] = a[ind2++];
        } else if(a[ind2] < a[ind1]) {
            temp[k++] = a[ind2++];
        } else {
            temp[k++] = a[ind1++];
        }
    }
    
    for(int i = l; i <= r; i++) {
        a[i] = temp[i - l];
    }
    free(temp);
    return ;
}

void output(int a[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    merge_sort(a, 0, n-1);
    output(a, n);
    return 0;
}
