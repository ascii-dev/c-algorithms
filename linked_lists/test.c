#include <stdio.h>
#include <assert.h>

#include "linked_list.h"

void test_linked_list_creation();

int main() {
    printf("==============================================================\n");
    printf("LINKED LIST TESTS\n");
    printf("==============================================================\n");

    test_linked_list_creation();

    return 0;
}

void test_linked_list_creation() {
    printf("test linked list is created successfully\n");
    LinkedList *new_ll = construct();

    assert(new_ll->size == 0);
    assert(new_ll->head == NULL);
    assert(new_ll->tail == NULL);
    assert(new_ll->list == NULL);

    destroy(new_ll);
}
