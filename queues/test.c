#include <stdio.h>
#include <assert.h>

#include "linked_queue.h"
#include "circular_buffer.h"

void test_linked_queue_creation();
void test_enqueue_lq_adds_data_to_tail();
void test_dequeue_lq_removes_data_from_head();
void test_empty_lq_checks_if_queue_empty();

int main() {
    printf("==============================================================\n");
    printf("LINKED QUEUE TESTS\n");
    printf("==============================================================\n");
    test_linked_queue_creation();
    test_enqueue_lq_adds_data_to_tail();
    test_dequeue_lq_removes_data_from_head();
    test_empty_lq_checks_if_queue_empty();

    printf("\n==============================================================\n");
    printf("ARRAY QUEUE TESTS\n");
    printf("==============================================================\n");

    return 0;
}

void test_linked_queue_creation() {
    printf("test linked queue is created successfully\n");

    LinkedQueue *new_lq = construct_lq();

    assert(new_lq->list == NULL);
    assert(new_lq->head == NULL);
    assert(new_lq->tail == NULL);
    assert(new_lq->size == 0);

    destroy_lq(new_lq);
}

void test_enqueue_lq_adds_data_to_tail() {
    printf("test enqueue adds data to tail\n");

    LinkedQueue *new_lq = construct_lq();

    enqueue_lq(new_lq, 0);
    assert(new_lq->head->data == 0);
    assert(new_lq->tail->data == 0);
    assert(size_lq(new_lq) == 1);

    enqueue_lq(new_lq, 1);
    assert(new_lq->head->data == 0);
    assert(new_lq->tail->data == 1);
    assert(size_lq(new_lq) == 2);

    destroy_lq(new_lq);
}

void test_empty_lq_checks_if_queue_empty() {
    printf("test empty_lq checks if queue is empty\n");

    LinkedQueue *new_lq = construct_lq();
    assert(empty_lq(new_lq) == true);

    enqueue_lq(new_lq, 1);
    enqueue_lq(new_lq, 2);
    enqueue_lq(new_lq, 3);
    assert(empty_lq(new_lq) == false);

    destroy_lq(new_lq);
}

void test_dequeue_lq_removes_data_from_head() {
    printf("test dequeue removes data from head\n");

    LinkedQueue *new_lq = construct_lq();

    enqueue_lq(new_lq, 1);
    enqueue_lq(new_lq, 2);
    enqueue_lq(new_lq, 3);
    enqueue_lq(new_lq, 4);

    assert(dequeue_lq(new_lq) == 1);
    assert(new_lq->head->data == 2);

    destroy_lq(new_lq);
}
