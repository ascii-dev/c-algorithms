#include <stdio.h>
#include <assert.h>

#include "linked_list.h"

void test_linked_list_creation();
void test_push_front_adds_node_to_head();
void test_size_returns_correct_data();
void test_empty_function_returns_correct_data();
void test_pop_front_returns_data();
void test_push_back_adds_node_to_tail();
void test_front_function_returns_correct_data();
void test_back_function_returns_correct_data();
void test_pop_back_returns_correct_data();
void test_value_at_returns_correct_data();
void test_insert_at_inserts_correctly_at_index();
void test_erase_at_inserts_correctly_at_index();

int main() {
    printf("==============================================================\n");
    printf("LINKED LIST TESTS\n");
    printf("==============================================================\n");

    test_linked_list_creation();
    test_push_front_adds_node_to_head();
    test_size_returns_correct_data();
    test_empty_function_returns_correct_data();
    test_pop_front_returns_data();
    test_push_back_adds_node_to_tail();
    test_front_function_returns_correct_data();
    test_back_function_returns_correct_data();
    test_pop_back_returns_correct_data();
    test_value_at_returns_correct_data();
    test_insert_at_inserts_correctly_at_index();
    test_erase_at_inserts_correctly_at_index();

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
    assert(size(new_ll) == 3);

    destroy(new_ll);
}

void test_push_back_adds_node_to_tail() {
    printf("test push_back adds node to tail\n");

    LinkedList *new_ll = construct();

    push_back(new_ll, 1);
    assert(new_ll->tail->data == 1);
    assert(new_ll->head->data == 1);
    assert(size(new_ll) == 1);

    push_back(new_ll, 2);
    assert(new_ll->tail->data == 2);
    assert(new_ll->head->next == new_ll->tail);
    assert(new_ll->head->data == 1);
    assert(size(new_ll) == 2);

    destroy(new_ll);
}

void test_front_function_returns_correct_data() {
    printf("test front returns correct data\n");

    LinkedList *new_ll = construct();
    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(front(new_ll) == 4);
    assert(size(new_ll) == 4);

    destroy(new_ll);
}

void test_back_function_returns_correct_data() {
    printf("test back returns correct data\n");

    LinkedList *new_ll = construct();
    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(back(new_ll) == 1);
    assert(size(new_ll) == 4);

    destroy(new_ll);
}

void test_pop_back_returns_correct_data() {
    printf("test pop_back returns correct data\n");

    LinkedList *new_ll = construct();
    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(pop_back(new_ll) == 1);
    assert(new_ll->tail->data == 2);
    assert(new_ll->size == 3);

    destroy(new_ll);
}

void test_value_at_returns_correct_data() {
    printf("test value_at returns correct data\n");

    LinkedList *new_ll = construct();
    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(value_at(new_ll, 2) == 2);
    assert(value_at(new_ll, 4) == -1);

    destroy(new_ll);
}

void test_insert_at_inserts_correctly_at_index() {
    printf("test insert_at returns correct data\n");

    LinkedList *new_ll = construct();
    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(insert_at(new_ll, 1, 0) == 0);
    assert(value_at(new_ll, 0) == 4);
    assert(value_at(new_ll, 1) == 0);
    assert(value_at(new_ll, 2) == 3);

    destroy(new_ll);
}

void test_erase_at_inserts_correctly_at_index() {
    printf("test erase_at returns correct data\n");

    LinkedList *new_ll = construct();
    push_front(new_ll, 1);
    push_front(new_ll, 2);
    push_front(new_ll, 3);
    push_front(new_ll, 4);

    assert(erase_at(new_ll, 1) == 0);
    assert(value_at(new_ll, 0) == 4);
    assert(value_at(new_ll, 1) == 2);

    destroy(new_ll);
}
