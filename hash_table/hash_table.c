/*
IMPLEMENT HASH TABLE (WITH ARRAY USING LINEAR PROBING)
- hash(k, m) - m is size of hash table
- add(key, value) - if key already exists, update value
- exists(key)
- get(key)
- remove(key)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"

const int DELETED_FLAG = -1;

HashTable *construct_ht() {
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = 0;
    ht->capacity = 16;
    ht->array = (int *) malloc(sizeof(int) * ht->capacity);

    for (int i = 0; i < ht->capacity; i++)
        ht->array[i] = (int) NULL; // casting probably isn't the right way

    return ht;
}

void destroy_ht(HashTable *ht) {
    free(ht->array);
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
