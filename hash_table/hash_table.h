typedef struct {
    int size, capacity;
    int *array;
} HashTable;

HashTable *construct_ht();
void destroy_ht(HashTable *ht);
int hash(HashTable *ht, char *key);
