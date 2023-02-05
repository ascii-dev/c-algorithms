#ifndef ASCII_ARRAYS
#define ASCII_ARRAYS

#include <stdbool.h>

typedef struct {
    int size, capacity;
    int* array;
} Array;

Array *construct(int capacity);
void destroy(Array *self);
int size(Array *self);
int capacity(Array *self);
bool is_empty(Array *self);
int at(Array *self, int index);
void push(Array *self, int item);
int insert(Array *self, int index, int item);
void prepend(Array *self, int item);
int pop(Array *self);
void delete_item(Array *self, int index);
int remove_item(Array *self, int item);
int find(Array *self, int item);

#endif