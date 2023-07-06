#include "hash_tables.h"
/**
 *
 *
 */
hash_node_t* create_item(char* key, char* value)
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
	hash_table_t* table = (hash_table_t*) malloc(sizeof(hash_table_t));
	table->size = size;
	table->array = (hash_node_t**) calloc(table->size, sizeof(hash_node_t*));

	for (i = 0; i < table->size; i++)
		table->array[i] = NULL;
	return table;
}

void free_array(hash_node_t* array)
{
	free(array->key);
	free(array->value);
	free(array);
}

void free_table(hash_table_t* table)
{
	unsigned long int i;

	for (i = 0; i < table->size; i++)
	{
		hash_node_t* array = table->array[i];
		if (array != NULL)
			free_array(array);
	}
	free(table->array);
	free(table);
}
