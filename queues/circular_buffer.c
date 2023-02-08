/*
IMPLEMENT QUEUES USING FIXED-SIZE ARRAY
    - enqueue(value) - adds item at end of available storage
    - dequeue() - returns value and removes least recently added element
    - empty()
    - full()
*/
#include <stdio.h>
#include <stdlib.h>

#include "circular_buffer.h"

const int BUFFER_LENGTH = 5;

CircularBuffer *construct_cb() {
    CircularBuffer *new_cb = malloc(sizeof(CircularBuffer));
    new_cb->size = 0;
    new_cb->start = 0;
    new_cb->end = 0;
    new_cb->array = (int *) malloc(sizeof(int) * BUFFER_LENGTH);

    return new_cb;
}

int size_cb(CircularBuffer *self) {
    return self->size;
}

void destroy_cb(CircularBuffer *self) {
    free(self->array);
    free(self);
}

int enqueue_cb(CircularBuffer *self, int value) {
    if (full_cb(self) == true) return -1;

    self->array[self->start++] = value;
    self->start %= BUFFER_LENGTH;
    self->size++;

    return 0;
}

int dequeue_cb(CircularBuffer *self) {
    if (empty_cb(self) == true) return -1;

    int value = self->array[self->end++];
    self->end %= BUFFER_LENGTH;
    self->size--;

    return value;
}

bool empty_cb(CircularBuffer *self) {
    return self->size == 0;
}

bool full_cb(CircularBuffer *self) {
    return self->size == BUFFER_LENGTH - 1;
}
