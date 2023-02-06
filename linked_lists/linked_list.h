#ifndef ASCII_LINKED_LISTS
#define ASCII_LINKED_LISTS

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

#endif // ASCII_LINKED_LISTS
