#ifndef ASCII_CIRCULAR_BUFFER
#define ASCII_CIRCULAR_BUFFER

#include <stdbool.h>

typedef struct {
    int *array;
    int size;
    int start;
    int end;
} CircularBuffer;

CircularBuffer *construct_cb();
void destroy_cb(CircularBuffer *self);
int enqueue_cb(CircularBuffer *self, int value);
int size_cb(CircularBuffer *self);
int dequeue_cb(CircularBuffer *self);
bool empty_cb(CircularBuffer *self);
bool full_cb(CircularBuffer *self);

#endif // ASCII_CIRCULAR_BUFFER
