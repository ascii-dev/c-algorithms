#include <stdio.h>
#include <assert.h>

#include "linked_queue.h"
#include "circular_buffer.h"

void test_linked_queue_creation();
void test_enqueue_lq_adds_data_to_tail();
void test_dequeue_lq_removes_data_from_head();
void test_empty_lq_checks_if_queue_empty();
void test_circular_buffer_creation();
void test_circular_buffer_enqueue();
void test_circular_buffer_dequeue();
void test_empty_cb_checks_if_queue_empty();
void test_full_cb_checks_if_queue_is_full();

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
    test_circular_buffer_creation();
    test_circular_buffer_enqueue();
    test_circular_buffer_dequeue();
    test_empty_cb_checks_if_queue_empty();
    test_full_cb_checks_if_queue_is_full();

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

void test_circular_buffer_creation() {
    printf("test circular buffer is created successfully\n");

    CircularBuffer *new_cb = construct_cb();

    assert(new_cb->array != NULL);
    assert(new_cb->size == 0);

    destroy_cb(new_cb);
}

void test_circular_buffer_enqueue() {
    printf("test that enqueue_cb works as expected\n");

    CircularBuffer *new_cb = construct_cb();
    assert(size_cb(new_cb) == 0);

    enqueue_cb(new_cb, 1);
    assert(size_cb(new_cb) == 1);
    assert(new_cb->array[0] == 1);
    assert(new_cb->start == 1);

    enqueue_cb(new_cb, 2);
    assert(size_cb(new_cb) == 2);
    assert(new_cb->array[1] == 2);
    assert(new_cb->start == 2);

    destroy_cb(new_cb);
}

void test_circular_buffer_dequeue() {
    printf("test that dequeue_cb works as expected\n");

    CircularBuffer *new_cb = construct_cb();
    enqueue_cb(new_cb, 1);
    enqueue_cb(new_cb, 2);
    enqueue_cb(new_cb, 3);
    enqueue_cb(new_cb, 4);

    assert(dequeue_cb(new_cb) == 1);
    assert(new_cb->size == 3);

    destroy_cb(new_cb);
}

void test_empty_cb_checks_if_queue_empty() {
    printf("test empty_cb checks if queue is empty\n");

    CircularBuffer *new_cb = construct_cb();
    assert(empty_cb(new_cb) == true);

    enqueue_cb(new_cb, 1);
    enqueue_cb(new_cb, 2);
    enqueue_cb(new_cb, 3);
    assert(empty_cb(new_cb) == false);

    destroy_cb(new_cb);
}

void test_full_cb_checks_if_queue_is_full() {
    printf("test full_cb checks if queue is full\n");

    CircularBuffer *new_cb = construct_cb();
    assert(full_cb(new_cb) == false);

    enqueue_cb(new_cb, 1);
    enqueue_cb(new_cb, 2);
    enqueue_cb(new_cb, 3);
    assert(full_cb(new_cb) == false);

    enqueue_cb(new_cb, 4);
    enqueue_cb(new_cb, 5);
    assert(full_cb(new_cb) == true);

    destroy_cb(new_cb);
}
