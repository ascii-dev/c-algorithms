#ifndef ASCII_HASH_TABLE
#define ASCII_HASH_TABLE

#define DEFAULT_CAPACITY 16

typedef struct {
    char *key;
    char *value;
} HashTableItem;

typedef struct {
    int size, capacity;
    HashTableItem * array[DEFAULT_CAPACITY];
} HashTable;

HashTable *construct_ht();
void destroy_ht(HashTable *ht);
int hash(HashTable *ht, char key[]);
void add(HashTable *ht, char key[], char value[]);

#endif // ASCII_HASH_TABLE