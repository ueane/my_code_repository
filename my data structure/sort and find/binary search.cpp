#include <stdio.h>
#include "test.h"
 
int binary_search(int *num, int x, int n) {
    int head, tail, mid;
    head = 0, tail = n - 1;
    mid = (head + tail) >> 1;
    while (head <= tail) {
        if (num[mid] == x) {
            return mid;
        } else if (num[mid] < x) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
        mid = (head + tail) >> 1;
    }
    return -1;
}
 
int main() {  
    return 0;
}
 
TEST(binary_search, expect_pass_test) {
    int arr[10] = {0};
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }
    for (int j = 0; j < 10; j++) {
        EXPECT_EQ(binary_search(arr, j, 10), j - 1);
    }
}
 
TEST(binary_search, assert_pass_test) {
    int arr[10] = {0};
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }
    for (int j = 0; j < 10; j++) {
        ASSERT_EQ(binary_search(arr, j, 10), j - 1);
    }
}

TEST(binary_search, expect_fail_test) {
    int arr[10] = {0};
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }
    for (int j = 0; j < 10; j++) {
        EXPECT_EQ(binary_search(arr, j, 10), j);
    }
}
 
TEST(binary_search, assert_fail_test) {
    int arr[10] = {0};
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }
    for (int j = 0; j < 10; j++) {
        ASSERT_EQ(binary_search(arr, j, 10), j);
    }
}
