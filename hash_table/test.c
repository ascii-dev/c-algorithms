#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "hash_table.h"

void test_hash_table_creation_successful();
void test_hash_function_returns_correct_value();
void test_add_works_as_expected();

int main() {
    printf("==============================================================\n");
    printf("HASH TABLE TESTS\n");
    printf("==============================================================\n");

    test_hash_table_creation_successful();
    test_hash_function_returns_correct_value();
    test_add_works_as_expected();

    return 0;
}

void test_hash_table_creation_successful() {
    printf("test hash table is created successfuly\n");

    HashTable *ht = construct_ht();

    assert(ht->size == 0);
    assert(ht->capacity == DEFAULT_CAPACITY);

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

void test_add_works_as_expected() {
    printf("test hash table add function works as expected\n");

    HashTable *ht = construct_ht();

    add(ht, "domino", "etremis");

    assert(strcmp(ht->array[6]->key, "domino") == 0);
    assert(strcmp(ht->array[6]->value, "etremis") == 0);

    destroy_ht(ht);
}
