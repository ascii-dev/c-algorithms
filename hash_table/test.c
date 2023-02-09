#include <stdio.h>
#include <assert.h>

#include "hash_table.h"

void test_hash_table_creation_successful();
void test_hash_function_returns_correct_value();

int main() {
    printf("==============================================================\n");
    printf("HASH TABLE TESTS\n");
    printf("==============================================================\n");

    test_hash_table_creation_successful();
    test_hash_function_returns_correct_value();

    return 0;
}

void test_hash_table_creation_successful() {
    printf("test hash table is created successfuly\n");

    HashTable *ht = construct_ht();

    assert(ht->size == 0);
    assert(ht->capacity == 16);
    assert(ht->array != NULL);

    destroy_ht(ht);
}

void test_hash_function_returns_correct_value() {
    printf("test hash table returns correct function for key\n");

    HashTable *ht = construct_ht();
    
    assert(hash(ht, "domino") == 6);
    assert(hash(ht, "programix") == 9);
    assert(hash(ht, "jessie") == 3);
    assert(hash(ht, "lipa") == 6);
    assert(hash(ht, "garrix") == 13);
    assert(hash(ht, "trevor") == 2);

    destroy_ht(ht);
}
