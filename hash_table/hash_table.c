/*
IMPLEMENT HASH TABLE (WITH ARRAY USING LINEAR PROBING)
- hash(k, m) - m is size of hash table
- add(key, value) - if key already exists, update value
- exists(key)
- get(key)
- remove(key)

TODO: work on making the value a string also, instead of ints
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

const int DELETED_FLAG = -1;
const int DECREMENT_THRESHOLD = 4; // we want to shrink at 1/4th capacity
const int INCREMENT_THRESHOLD = 2; // we want to expand once we're halfway through
const int RESIZE_VALUE = 2;

void _resize(HashTable *ht, int new_capacity);
void _expand(HashTable *ht);
void _shrink(HashTable *ht);

HashTable *construct_ht() {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = 0;
    ht->capacity = DEFAULT_CAPACITY;

    for (int i = 0; i < ht->capacity; i++)
        ht->array[i] = NULL;

    return ht;
}

void destroy_ht(HashTable *ht) {
    free(ht);
}

int hash(HashTable *ht, char key[]) {
    // TODO: work on a better hash function that doesn't rely
    // on all of the characters in key as this is going to
    // get super slow with the length of the key.
    int char_value = 0;
    int len = strlen(key);
    for (int i = 0; i < len; i++)
        char_value += key[i];
    
    return char_value % ht->capacity;
}

void add(HashTable *ht, char key[], char value[]) {
    _expand(ht);

    HashTableItem *item = malloc(sizeof(HashTableItem));
    item->key = key;
    item->value = value;

    int index = hash(ht, key);
    if (ht->array[index] != NULL) {
        while (index < ht->capacity)
            if (ht->array[index++] == NULL)
                break;
    }

    ht->array[index] = item;
    ht->size++;
}

int exists_ht(HashTable *ht, char key[]) {
    int index = hash(ht, key);
    while (ht->array[index] != NULL) {
        if (strcmp(ht->array[index++]->key, key) == 0)
            return 1;
        
    }

    return 0;
}

void _resize(HashTable *ht, int new_capacity) {
    int *array = malloc(sizeof(HashTableItem) * new_capacity);
    for (int i = 0; i < ht->capacity; i++)
        if (ht->array[i] != NULL) {
            HashTableItem *current = ht->array[i];
            add(ht, current->key, current->value);
        }

    ht->capacity = new_capacity;
}

void _expand(HashTable *ht) {
    if (ht->capacity - ht->size <= INCREMENT_THRESHOLD)
        _resize(ht, ht->capacity * RESIZE_VALUE);
}

void _shrink(HashTable *ht) {
    if (ht->capacity / ht->size <= DECREMENT_THRESHOLD)
        _resize(ht, ht->capacity / RESIZE_VALUE);
}
