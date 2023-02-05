/*
IMPLEMENT A VECTOR (MUTABLE ARRAY WITH AUTOMATIC RESIZING):
* Practice coding using arrays and pointers, and pointer math to jump to an index instead of using indexing.
* New raw data array with allocated memory
* Can allocate int array under the hood, just not use its features
* Start with 16, or if starting number is greater, use power of 2 - 16, 32, 64, 128
    - size() - number of items
    - capacity() - number of items it can hold
    - is_empty()
    - at(index) - returns item at given index, blows up if index out of bounds
    - push(item)
    - insert(index, item) - inserts item at index, shifts that index's value and trailing elements to the right
    - prepend(item) - can use insert above at index 0
    - pop() - remove from end, return value
    - delete(index) - delete item at index, shifting all trailing elements left
    - remove(item) - looks for value and removes index holding it (even if in multiple places)
    - find(item) - looks for value and returns first index with that value, -1 if not found
    - resize(new_capacity) // private function
* When you reach capacity, resize to double the size
* Wwhen popping an item, if size is 1/4 of capacity, resize to half
*/
#include <stdlib.h>

#include "array.h"

const int DEFAULT_CAPACITY = 16;
const int CAPACITY_FACTOR = 2;
const int CAPACITY_DECREMENT_FACTOR = 4;

void resize(Array *self, int new_capacity);

Array *construct(int capacity) {
    if (capacity <= 0) {
        capacity = DEFAULT_CAPACITY;
    }

    Array *new_array = malloc(sizeof(Array));
    new_array->size = 0;
    new_array->capacity = capacity;
    new_array->array = (int *) malloc(sizeof(int) * capacity);

    return new_array;
}

void destroy(Array *self) {
    free(self->array);
    free(self);
}

int size(Array *self) {
    return self->size;
}

int capacity(Array *self) {
    return self->capacity;
}

bool is_empty(Array *self) {
    return self->size == 0;
}

int at(Array *self, int index) {
    if (index < 0 || index >= self->size) return -1;
    return self->array[index];
}

void push(Array *self, int item) {
    if (self->size + 1 >= self->capacity)
        resize(self, self->capacity * CAPACITY_FACTOR);

    self->array[self->size++] = item;
}

int pop(Array *self) {
    if (is_empty(self)) return (int) -1;
    return self->array[--self->size];
}

int find(Array *self, int item) {
    int *array = self->array;

    for (int i = 0; i < self->size; i++)
        if (array[i] == item) return item;
    
    return -1;
}

int insert(Array *self, int index, int item) {
    if (index < 0 || index >= self->size) return -1;

    if (self->size + 1 >= self->capacity)
        resize(self, self->capacity * CAPACITY_FACTOR);

    for (int i = self->size; i >= index; i--)
        self->array[i] = self->array[i - 1];

    self->array[index] = item;
    self->size++;

    return 0;
}

void prepend(Array *self, int item) {
    insert(self, 0, item);
}

void delete_at(Array *self, int index) {
    if (index < 0 || index >= self->size) return;

    for (int i = index; i < self->size; i++)
        self->array[i] = self->array[i + 1];

    self->size--;

    if (self->size < self->capacity / CAPACITY_DECREMENT_FACTOR)
        resize(self, self->capacity);
}

void remove_item(Array *self, int item) {
    for (int i = 0; i < size(self); i++)
        if (self->array[i] == item)
            delete_at(self, i);
}

/* Commenting this out because I have a new version below using realloc but 
still want to keep this around for study purposes.
void resize(Array *self, int new_capacity) {
    int new_size = new_capacity;
    if (self->size < self->capacity / CAPACITY_DECREMENT_FACTOR)
        new_size = self->capacity / CAPACITY_DECREMENT_FACTOR;

    int new_array[new_size];

    self->capacity = new_capacity;

    for (int i = 0; i < self->size; i++)
        new_array[i] = self->array[i];

    self->array = new_array;
}
*/

void resize(Array *self, int new_capacity) {
    int new_size = new_capacity;
    if (self->size < self->capacity / CAPACITY_DECREMENT_FACTOR)
        new_size = self->capacity / CAPACITY_DECREMENT_FACTOR;

    self->capacity = new_capacity;

    self->array = realloc(self->array, sizeof(int) * self->capacity);
}
