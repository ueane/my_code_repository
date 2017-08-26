#include "q.h"
#include <stdlib.h>
#include <stdio.h>
void init_queue(Queue *q, int n) {
    q->data = (int *)malloc(n * sizeof(int));
    q->length = n;
    q->count = 0;
    q->head = 0;
    q->tail = -1;
}

void output_queue(Queue *q) {
    printf("Queue : ");
    int index = 0;
    for(int i = 0;i < q->count; i++) {
        index = (q->head + i) % q->length;
        printf("%d ",q->data[index]);
    }
    printf("\n");
}

int push_queue(Queue *q, int value) {
    if (q->count == q->length) {
        return ERROR;
    }
    ++q->tail;
    ++q->count;
    q->tail %= q->length;
    q->data[q->tail] = value;
    return OK;
}

int pop_queue(Queue *q) {
    if (empty_queue(q)) {
        return ERROR;
    }
    ++q->head;
    --q->count;
    q->head %= q->length;
    return OK;
}

int empty_queue(Queue *q) {
    return q->count == 0;
}

int front_queue(Queue *q) {
    return q->data[q->head];
}

void clear_queue(Queue *q) {
    free(q->data);
    free(q);
}

