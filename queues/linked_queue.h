#ifndef ASCII_LINKED_QUEUES
#define ASCII_LINKED_QUEUES

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedQueue {
    Node *head;
    Node *tail;
    Node *list;
    int size;
} LinkedQueue;

LinkedQueue *construct_lq();
void destroy_lq(LinkedQueue *self);
void enqueue_lq(LinkedQueue *self, int value);
int size_lq(LinkedQueue *self);
int dequeue_lq(LinkedQueue *self);
bool empty_lq(LinkedQueue *self);

#endif // ASCII_LINKED_QUEUES
