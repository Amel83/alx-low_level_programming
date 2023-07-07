#include "hash_tables.h"
/**
 *
 *
 */
hash_node_t* create_item(const char* key, const char* value)
{
    hash_node_t* array = (hash_node_t*) malloc(sizeof(hash_node_t));
    array->key = (char*) malloc(strlen(key) + 1);
    array->value = (char*) malloc(strlen(value) + 1);
    strcpy(array->key, key);
    strcpy(array->value, value);
    return array;
}

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i;
	hash_table_t* ht = (hash_table_t*) malloc(sizeof(hash_table_t));
	ht->size = size;
	ht->array = (hash_node_t**) calloc(ht->size, sizeof(hash_node_t*));

	for (i = 0; i < ht->size; i++)
		ht->array[i] = NULL;
	return ht;
}

void free_array(hash_node_t* array)
{
	free(array->key);
	free(array->value);
	free(array);
}

void free_table(hash_table_t* ht)
{
	unsigned long int i;

	for (i = 0; i < ht->size; i++)
	{
		hash_node_t* array = ht->array[i];
		if (array != NULL)
			free_array(array);
	}
	free(ht->array);
	free(ht);
}
