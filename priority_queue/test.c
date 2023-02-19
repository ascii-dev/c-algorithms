#include <assert.h>
#include <stdio.h>

#include "priority_queue.h"

void test_max_heap_creation_succesful();

int main() {
    printf("==============================================================\n");
    printf("PRIORITY QUEUE TESTS\n");
    printf("==============================================================\n");
    test_max_heap_creation_succesful();

    return 0;
}

void test_max_heap_creation_succesful() {
    printf("test MaxHeap creation\n");

    MaxHeap *mh = construct_mh();

    assert(mh->size == 0);
    assert(mh->capacity == 1000);

    destroy_mh(mh);
}
