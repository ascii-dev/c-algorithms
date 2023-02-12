#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "hash_table.h"

void test_hash_table_creation_successful();
void test_hash_function_returns_correct_value();
void test_add_works_as_expected();
void test_exists_checks_for_key_membership();
void test_get_returns_correct_value();

int main() {
    printf("==============================================================\n");
    printf("HASH TABLE TESTS\n");
    printf("==============================================================\n");

    test_hash_table_creation_successful();
    test_hash_function_returns_correct_value();
    test_add_works_as_expected();
    test_exists_checks_for_key_membership();
    test_get_returns_correct_value();

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

void test_exists_checks_for_key_membership() {
    printf("test exists function checks for key membership\n");

    HashTable *ht = construct_ht();

    add(ht, "domino", "etremis");

    assert(exists_ht(ht, "domino") == 1);
    assert(exists_ht(ht, "lipa") == 0);

    destroy_ht(ht);
}

void test_get_returns_correct_value() {
    printf("test get function returns correct value\n");

    HashTable *ht = construct_ht();

    add(ht, "lipa", "dua");
    add(ht, "domino", "extremis");

    HashTableItem *item = get_ht(ht, "domino");

    assert(strcmp(item->key, "domino") == 0);
    assert(strcmp(item->value, "extremis") == 0);

    HashTableItem *another_item = get_ht(ht, "trevor");

    assert(another_item == NULL);

    destroy_ht(ht);
}
