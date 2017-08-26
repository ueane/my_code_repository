#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "q.h"
#ifdef TESTCASE
    #include "queue_testcase.h"
#endif
 
int main() {
    srand(time(0));
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, 100);
    char ch;
    while (scanf("%c", &ch) != EOF) {
        int opr, value;
        opr = rand() % 5;
        value = rand() % 100;
        if (opr != 0) {
            push_queue(q, value);
            printf("push %d\n", value);
        } else {
            pop_queue(q);
            printf("pop queue\n");
        }
        output_queue(q);
    }
    clear_queue(q);
    return 0;
}
/*
TEST(queue, push_queue) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, 100);
    for(int i = 0; i < 100; i++) {
        ASSERT_EQ(push_queue(q, i) , OK);
    }
        ASSERT_EQ(push_queue(q, 101), ERROR);
}

TEST(queue, pop_queue) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, 100);
    for(int i = 0; i < 100; i++) {
        push_queue(q, i);
    }
    for(int i = 0; i < 100; i++) {
        ASSERT_EQ(pop_queue(q), OK);
    }
        ASSERT_EQ(pop_queue(q), ERROR);
}

TEST(queue, empty_queue) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, 100);
    
    for(int i = 0; i < 100; i++) {
        push_queue(q, i);
        ASSERT_EQ(empty_queue(q), ERROR);
    }
    for(int i = 0; i < 100; i++) {
        pop_queue(q);
    }
    ASSERT_EQ(empty_queue(q), OK);
}


TEST(queue, front_queue) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q, 100);
    for(int i = 0; i < 100; i++) {
        push_queue(q, i);
    }
    ASSERT_EQ(front_queue(q), 0);
    pop_queue(q);
    ASSERT_EQ(front_queue(q), 1);
}


TEST(queue, output_queue) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q,10);
    for(int i = 0; i < 10; i++) {
        push_queue(q, i);
    }
}

TEST(queue, clear_queue) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init_queue(q,10);
    ASSERT_EQ(clear_queue(q),1);
}
*/