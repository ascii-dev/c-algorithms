#ifndef ASCII_CIRCULAR_BUFFER
#define ASCII_CIRCULAR_BUFFER

#include <stdbool.h>

typedef struct {
    int *array;
    int size;
} CircularBuffer;

CircularBuffer *construct();
void destroy(CircularBuffer *self);

#endif // ASCII_CIRCULAR_BUFFER
