#include <stdio.h>
#include <stdlib.h>
 
#define ERROR 0
#define OK 1
 
#define swap(a, b) { \
    __typeof(a) __temp = (a); \
    (a) = (b); (b) = __temp; \
}
 
typedef struct PQueue {
    int *data;
    int size, length;
} PQueue;
 
int cmp_value(int a, int b) {
    if (a < b) return 1;
    return 0;
}
 
void init(PQueue *pq, int n) {
    pq->data = (int *)malloc(sizeof(int) * n);
    pq->size = 0;
    pq->length = n;
}
 
int empty(PQueue *pq) {
    return pq->size == 0;
}
 
int front(PQueue *pq) {
    return pq->data[0];
}
 
int push(PQueue *pq, int value) {
    if (pq->size >= pq->length) {
        return ERROR;
    }
    pq->data[pq->size] = value;
    int c = pq->size, f;
    f = (c - 1) / 2;
    while (cmp_value(pq->data[c], pq->data[f])) {
        swap(pq->data[c], pq->data[f]);
        c = f;
        f = (c - 1) / 2;
    }
    pq->size++;
    return OK;
}
 
int pop(PQueue *pq) {
    if (empty(pq)) {
        return ERROR;
    }
    swap(pq->data[pq->size - 1], pq->data[0]);
    pq->size -= 1;
    int i = -1, l, r, max_index = 0;
    while (max_index != i) {
        i = max_index;
        l = 2 * i + 1;
        r = 2 * i + 2;
        if (l < pq->size && cmp_value(pq->data[l], pq->data[max_index])) {
            max_index = l;
        }
        if (r < pq->size && cmp_value(pq->data[r], pq->data[max_index])) {
            max_index = r;
        }
        if (max_index != i) {
            swap(pq->data[i], pq->data[max_index]);
        }
    }
    return OK;
}
 
 
void clear(PQueue *pq) {
    free(pq->data);
    free(pq);
}
 
int main() {
    int n, a;
    scanf("%d", &n);
    PQueue *pq = (PQueue *)malloc(sizeof(PQueue));
    init(pq, n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        push(pq, a);
    }
    while (!empty(pq)) {
        printf("%d ", front(pq));
        pop(pq);
    }
    printf("\n");
    clear(pq);
    return 0;
}