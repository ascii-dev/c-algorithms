#include <stdio.h>
#include <assert.h>

#include "array.h"

void test_array_creation_with_set_capacity_of_10();
void test_array_creation_with_no_set_capacity();

int main() {
    printf("==============================================================\n");
    printf("ARRAY TESTS\n");
    printf("==============================================================\n");
    test_array_creation_with_set_capacity_of_10();
    test_array_creation_with_no_set_capacity();

    return 0;
}

void test_array_creation_with_set_capacity_of_10() {
    printf("testing array creation with set capacity of 10\n");

    Array *new_array = construct(10);

    assert(capacity(new_array) == 10);

    destroy(new_array);
}

void test_array_creation_with_no_set_capacity() {
    printf("testing array creation with no set capacity\n");

    Array *new_array = construct(0);

    assert(capacity(new_array) == 16);

    destroy(new_array);
}
