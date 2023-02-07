#ifndef ASCII_LINKED_LISTS
#define ASCII_LINKED_LISTS

#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    Node *list;
    int size;
} LinkedList;

LinkedList *construct();
void destroy(LinkedList *self);
void push_front(LinkedList *self, int value);
int size(LinkedList *self);
bool empty(LinkedList *self);
int pop_front(LinkedList *self);
void push_back(LinkedList *self, int value);
int front(LinkedList *self);
int back(LinkedList *self);
int pop_back(LinkedList *self);
int value_at(LinkedList *self, int index);
int insert_at(LinkedList *self, int index, int value);
int erase_at(LinkedList *self, int index);
int remove_value(LinkedList *self, int value);
int value_n_from_end(LinkedList *self, int n);

#endif // ASCII_LINKED_LISTS
