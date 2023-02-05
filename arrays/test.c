#include <stdio.h>
#include <assert.h>

#include "array.h"

void test_array_creation_with_set_capacity_of_10();
void test_array_creation_with_no_set_capacity();
void test_size_calculation_is_correct();
void test_is_empty_function();
void test_at_valid_index_successful();
void test_at_invalid_index_returns_minus_1();
void test_push_adds_new_item_to_array();
void test_pop_removes_item_from_array();
void test_find_item_in_array();
void test_find_item_not_in_array_returns_minus_1();
void test_insert_item_in_array();
void test_insert_item_in_invalid_index_returns_minus_1();
void test_prepend_item_in_array();


int main() {
    printf("==============================================================\n");
    printf("ARRAY TESTS\n");
    printf("==============================================================\n");
    test_array_creation_with_set_capacity_of_10();
    test_array_creation_with_no_set_capacity();
    test_size_calculation_is_correct();
    test_is_empty_function();
    test_at_valid_index_successful();
    test_at_invalid_index_returns_minus_1();
    test_push_adds_new_item_to_array();
    test_pop_removes_item_from_array();
    test_find_item_in_array();
    test_find_item_not_in_array_returns_minus_1();
    test_insert_item_in_array();
    test_insert_item_in_invalid_index_returns_minus_1();
    test_prepend_item_in_array();

    return 0;
}

void test_array_creation_with_set_capacity_of_10() {
    printf("test array creation with set capacity of 10\n");

    Array *new_array = construct(10);

    assert(capacity(new_array) == 10);

    destroy(new_array);
}

void test_array_creation_with_no_set_capacity() {
    printf("test array creation with no set capacity\n");

    Array *new_array = construct(0);

    assert(capacity(new_array) == 16);

    destroy(new_array);
}

void test_push_adds_new_item_to_array() {
    printf("test push() adds new item to array\n");
    
    Array *new_array = construct(5);
    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);
    push(new_array, 13);

    int test_array[] = {10, 11, 12, 13};

    for (int i = 0; i < 4; i++)
        assert(at(new_array, i) == test_array[i]);
    
    destroy(new_array);
}

void test_push_triggers_resize_function_call() {
    printf("test push() adds new item to array\n");
    
    Array *new_array = construct(2);
    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);
    push(new_array, 13);

    assert(size(new_array) == 4);

    int test_array[] = {10, 11, 12, 13};

    for (int i = 0; i < 4; i++)
        assert(at(new_array, i) == test_array[i]);
    
    destroy(new_array);
}

void test_pop_removes_item_from_array() {
    printf("test pop() removes item from array\n");

    Array *new_array = construct(5);
    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);
    push(new_array, 13);


    assert(pop(new_array) == 13);
    assert(pop(new_array) == 12);
    assert(pop(new_array) == 11);
    assert(pop(new_array) == 10);

    destroy(new_array);
}

void test_size_calculation_is_correct() {
    printf("test size calculation is correct\n");

    Array *new_array = construct(5);
    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    assert(size(new_array) == 3);

    destroy(new_array);
}

void test_is_empty_function() {
    printf("test is_empty() returns valid data\n");

    Array *new_array = construct(5);
    
    assert(is_empty(new_array) == true);

    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    assert(is_empty(new_array) == false);

    destroy(new_array);
}

void test_at_valid_index_successful() {
    printf("test at() with valid index returns valid data\n");

    Array *new_array = construct(5);

    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    assert(at(new_array, 1) == 11);
    assert(at(new_array, 2) == 12);

    destroy(new_array);
}

void test_at_invalid_index_returns_minus_1() {
    printf("test at() with invalid index returns -1\n");

    Array *new_array = construct(5);

    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    assert(at(new_array, 3) == -1);

    destroy(new_array);
}

void test_find_item_in_array() {
    printf("test find existing item returns the item\n");

    Array *new_array = construct(5);

    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    assert(find(new_array, 12) == 12);

    destroy(new_array);
}

void test_find_item_not_in_array_returns_minus_1() {
    printf("test find non-existing item returns -1\n");

    Array *new_array = construct(5);

    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    assert(find(new_array, 16) == -1);

    destroy(new_array);
}

void test_insert_item_in_array() {
    printf("test insert item in array successfully returns 0\n");

    Array *new_array = construct(6);

    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    int end_array[] = {10, 2, 11, 12};

    assert(insert(new_array, 1, 2) == 0);

    for (int i = 0; i < 4; i++)
        assert(at(new_array, i) == end_array[i]);

    destroy(new_array);
}

void test_insert_item_in_invalid_index_returns_minus_1() {
    printf("test insert item in invalid index returns -1\n");

    Array *new_array = construct(6);

    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    assert(insert(new_array, 60, 7) == -1);

    destroy(new_array);
}

void test_prepend_item_in_array() {
    printf("test prepend item in array\n");

    Array *new_array = construct(6);

    push(new_array, 10);
    push(new_array, 11);
    push(new_array, 12);

    int end_array[] = {2, 10, 11, 12};

    prepend(new_array, 2);

    for (int i = 0; i < 4; i++)
        assert(at(new_array, i) == end_array[i]);

    destroy(new_array);
}
