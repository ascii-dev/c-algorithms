#ifndef ASCII_HASH_TABLE
#define ASCII_HASH_TABLE

#define DEFAULT_CAPACITY 16
#define DELETED_KEY "<DUMMY>"

typedef struct {
    char *key;
    char *value;
} HashTableItem;

typedef struct {
    int size, capacity;
    HashTableItem **array;
} HashTable;

HashTable *construct_ht();
void destroy_ht(HashTable *ht);
int hash(HashTable *ht, const char *key);
void add(HashTable *ht, const char *key, const char *value);
int exists_ht(HashTable *ht, const char *key);
HashTableItem *get_ht(HashTable *ht, const char *key);
void print_ht(HashTable *ht);
void remove_ht(HashTable *ht, const char *key);

#endif // ASCII_HASH_TABLE