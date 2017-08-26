/*************************************************************************
	> File Name: 12.cpp
	> Author: 
	> Mail: 
	> Created Time: 四  8/10 09:59:47 2017
 ************************************************************************/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"test.h"
#include<time.h>

#define swap(a,b) { \
    __typeof(a) __temp = (a); \
    (a) = (b) ; (b) = __temp; \
} \

typedef struct pqueue {
    int *data;
    int size, length;
} pqueue;

void init(pqueue *pq, int n) {
    pq->data = (int *)malloc(sizeof(int) * n);
    pq->size = 0;
    pq->length = n;
}

int empty(pqueue *pq) {
    return pq->size == 0;
}

int front(pqueue *pq) {
    return pq->data[0];
}

int cmp_value(int a, int b) {
    if(a > b) return 1;
    return 0;
}

int push(pqueue *pq, int value) {
    if(pq->size >= pq->length) return 0;
    pq->data[pq->size] = value;
    int c = pq->size, father;
    father = (c - 1) / 2;
    while(cmp_value(pq->data[c] , pq->data[father])) {
        swap(pq->data[c], pq->data[father]);
        c = father;
        father = (c-1)/2;
    }
    pq->size++;
    return 1;
}

int pop(pqueue *pq) {
    if(empty(pq)) {
        return 0;
    }
    swap(pq->data[pq->size - 1], pq->data[0]);
    pq->size -= 1;
    int i = -1, l, r, max_val = 0;
    while(max_val != i) {
        i = max_val;
        l = ( 2*i + 1 );
        r = ( 2*i + 2 );
        if(l < pq->size && pq->data[l] > pq->data[max_val]) {
            max_val = l;
        }
        if(r < pq->size && pq->data[r] > pq->data[max_val]) {
            max_val = r;
        }
        if(max_val != i) {
            swap(pq->data[i], pq->data[max_val]);
        }
    }
    return 1;
}

void clear(pqueue *pq) {
    free(pq->data);
    free(pq);
}

int main() {
    /*
    int n,a;
    scanf("%d",&n);
    pqueue *pq = (pqueue *)malloc(sizeof(pqueue));
    init(pq, n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        push(pq, a);
    }
    while(!empty(pq)) {
        printf("%d ", front(pq));
        pop(pq);
    }
    printf("\n");
    clear(pq);
    */
    return 0;
}

TEST(pqueue, push) {
    pqueue *pq = (pqueue *)malloc(sizeof(pqueue));
    init(pq, 10);
    int arr[11];
    for(int i = 0; i < 10; i++) {
        arr[i] = rand() % 50;
    }
    int ans;
    for(int i = 0; i < 10 ;i++) {
        ans = push(pq, arr[i]);
        ASSERT_EQ(ans, 1);
    }
    ans = push(pq, 1);
    ASSERT_EQ(ans, 0);
}

TEST(pqueue, front) {
    pqueue *pq = (pqueue *)malloc(sizeof(pqueue));
    init(pq, 10);
    for(int i = 1; i <= 10; i++) {
        push(pq, i);
    }
    for(int i = 10; i >= 1; i--) {
        ASSERT_EQ(front(pq), i);
        pop(pq);
    }
}

TEST(pqueue, pop) {
    pqueue *pq = (pqueue *)malloc(sizeof(pqueue));
    ASSERT_EQ(pop(pq), 0);
    init(pq, 10);
    for(int i = 1; i <= 10; i++) {
        push(pq, i);
    }
    for(int i = 10; i >= 2; i--) {
        pop(pq);
        ASSERT_EQ(front(pq), i-1);
    }
    ASSERT_NE(pop(pq), 10);
}

TEST(pqueue, empty) {
    pqueue *pq = (pqueue *)malloc(sizeof(pqueue));
    init(pq, 1);
    ASSERT_EQ(empty(pq), 1);
    push(pq, 2);
    ASSERT_EQ(empty(pq), 0);

}







