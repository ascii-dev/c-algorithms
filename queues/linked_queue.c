/*
IMPLEMENT QUEUES USING LINKED LIST, WITH TAIL POINTER
    - enqueue(value) - adds value at position at tail
    - dequeue() - returns value and removes least recently added element (front)
    - empty()
*/
#include <stdio.h>
#include <stdlib.h>

#include "linked_queue.h"

LinkedQueue *construct_lq() {
    LinkedQueue *new_lq = malloc(sizeof(LinkedQueue));
    new_lq->head = NULL;
    new_lq->tail = NULL;
    new_lq->list = NULL;
    new_lq->size = 0;

    return new_lq;
}

void destroy_lq(LinkedQueue *self) {
    Node *list = self->list;
    while (list != NULL) {
        Node *temp = list->next;
        free(list);
        list = temp;
    }
    free(self->list);
    free(self->head);
    free(self->tail);
}

int size_lq(LinkedQueue *self) {
    return self->size;
}

void enqueue_lq(LinkedQueue *self, int value) {
    Node *item = malloc(sizeof(Node));
    item->next = NULL;
    item->data = value;

    if (self->tail == NULL)
        self->head = self->tail = item;
    else {
        self->tail->next = item;
        self->tail = item;
    }

    self->size++;
}

int dequeue_lq(LinkedQueue *self) {
    if (size_lq(self) == 0) return -1;

    int value = self->head->data;
    Node *next = self->head->next;

    free(self->head);

    self->head = next;
    if (self->head == NULL)
        self->tail = NULL;
    
    self->size--;
    
    return value;
}

bool empty_lq(LinkedQueue *self) {
    return size_lq(self) == 0;
}
