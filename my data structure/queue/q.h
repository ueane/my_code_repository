#ifndef _QUEUE_H
#define _QUEUE_H
 
#define ERROR 0
#define OK 1
 
typedef struct Queue {
    int *data;
    int head, tail;
    int length, count;
} Queue;
 
void init_queue(Queue *q, int n);
int push_queue(Queue *q, int value);
int pop_queue(Queue *q);
int front_queue(Queue *q);
int empty_queue(Queue *q);
void clear_queue(Queue *q);
void output_queue(Queue *q);
 
#endif