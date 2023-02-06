#include <stdio.h>
#include <assert.h>

#include "linked_list.h"

void test_linked_list_creation();
void test_push_front_adds_node_to_head();

int main() {
    printf("==============================================================\n");
    printf("LINKED LIST TESTS\n");
    printf("==============================================================\n");

    test_linked_list_creation();
    test_push_front_adds_node_to_head();

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

void test_push_front_adds_node_to_head() {
    printf("test linked list push_front adds node to head\n");

    LinkedList *new_ll = construct();
    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(new_ll->head->data == 4);
    assert(new_ll->tail->data == 1);

    destroy(new_ll);
}
