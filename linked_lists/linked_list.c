/*
 Implement singly linked list:
    - size() - returns number of data elements in list
    - empty() - bool returns true if empty
    - value_at(index) - returns the value of the nth item (starting at 0 for first)
    - push_front(value) - adds an item to the front of the list
    - pop_front() - remove front item and return its value
    - push_back(value) - adds an item at the end
    - pop_back() - removes end item and returns its value
    - front() - get value of front item
    - back() - get value of end item
    - insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
    - erase(index) - removes node at given index
    - value_n_from_end(n) - returns the value of the node at nth position from the end of the list
    - reverse() - reverses the list
    - remove_value(value) - removes the first item in the list with this value
*/

#include <stdlib.h>

#include "linked_list.h"

LinkedList *construct() {
    LinkedList *new_ll = malloc(sizeof(LinkedList));
    new_ll->head = NULL;
    new_ll->tail = NULL;
    new_ll->size = 0;
    new_ll->list = NULL;

    return new_ll;
}

void destroy(LinkedList *self) {
    Node *list = self->list;
    while (list != NULL) {
        Node *temp = list->next;
        free(list);
        list = temp;
    }
    free(self->list);
    free(self->head);
    free(self->tail);
}

void push_front(LinkedList *self, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = self->head;
    self->head = new_node;

    if (self->tail == NULL)
        self->tail = self->head;
    
    self->size++;
}

int size(LinkedList *self) {
    return self->size;
}

bool empty(LinkedList *self) {
    return self->size == 0;
}

int pop_front(LinkedList *self) {
    if (empty(self) == true) return -1;

    Node *temp = self->head;
    int data = temp->data;
    self->head = self->head->next;

    if (self->head == NULL)
        self->tail = NULL;

    free(temp);

    self->size--;

    return data;
}

void push_back(LinkedList *self, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (self->tail == NULL)
        self->tail = self->head = new_node;
    else {
        self->tail->next = new_node;
        self->tail = new_node;
    }

    self->size++;
}

int front(LinkedList *self) {
    if (empty(self) == true) return -1;

    return self->head->data;
}

int back(LinkedList *self) {
    if (empty(self) == true) return -1;

    return self->tail->data;
}

int pop_back(LinkedList *self) {
    if (empty(self) == true) return -1;

    int return_value = self->tail->data;
    Node *next_to_last = self->head;
    while (next_to_last->next != self->tail)
        next_to_last = next_to_last->next;

    next_to_last->next = NULL;
    free(self->tail);
    self->tail = next_to_last;
    self->size--;

    return return_value;
}

int value_at(LinkedList *self, int index) {
    if (empty(self) == true) return -1;
    if (index < 0 || index >= self->size) return -1;

    Node *current = self->head;
    for (int i = 1; i <= index; i++)
        current = current->next;

    return current->data;
}

int insert_at(LinkedList *self, int index, int value) {
    if (empty(self) == true) return -1;
    if (index < 0 || index > self->size) return -1;

    if (index == 0)
        push_front(self, value);
    else if (index == self->size)
        push_back(self, value);
    else {
        Node *new_node = malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = NULL;

        Node *current = self->head;
        for (int i = 1; i < index; i++)
            current = current->next;
        
        new_node->next = current->next;
        current->next = new_node;
        self->size++;
    }

    return 0;
}
