#include "hash_tables.h"
/**
 *
 *
 */
hash_node_t* create_item(char* key, char* value)
{
    hash_node_t* item = (hash_node_t*) malloc(sizeof(hash_node_t));
    item->key = (char*) malloc(strlen(key) + 1);
    item->value = (char*) malloc(strlen(value) + 1);
    strcpy(item->key, key);
    strcpy(item->value, value);
    return item;
}

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t* table = (hash_table_t*) malloc(sizeof(hash_table_t))
	table->size = size;
	table->items = (Ht_item**) calloc(table->size, sizeof(Ht_item*));

	for (int i = 0; i < table->size; i++)
	table->items[i] = NULL;
	return table;
}
