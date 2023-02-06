#include <stdio.h>
#include <assert.h>

#include "linked_list.h"

void test_linked_list_creation();
void test_push_front_adds_node_to_head();
void test_size_returns_correct_data();
void test_empty_function_returns_correct_data();
void test_pop_front_returns_data();

int main() {
    printf("==============================================================\n");
    printf("LINKED LIST TESTS\n");
    printf("==============================================================\n");

    test_linked_list_creation();
    test_push_front_adds_node_to_head();
    test_size_returns_correct_data();
    test_empty_function_returns_correct_data();
    test_pop_front_returns_data();

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

void test_size_returns_correct_data() {
    printf("test size returns correct data\n");

    LinkedList *new_ll = construct();

    assert(size(new_ll) == 0);

    push_front(new_ll, 1);

    assert(size(new_ll) == 1);
    
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(size(new_ll) == 4);

    destroy(new_ll);
}

void test_empty_function_returns_correct_data() {
    printf("test empty returns correct data\n");

    LinkedList *new_ll = construct();

    assert(empty(new_ll) == true);

    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(empty(new_ll) == false);

    destroy(new_ll);
}

void test_pop_front_returns_data() {
    printf("test pop_front returns correct data\n");

    LinkedList *new_ll = construct();
    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(pop_front(new_ll) == 4);

    destroy(new_ll);
}
