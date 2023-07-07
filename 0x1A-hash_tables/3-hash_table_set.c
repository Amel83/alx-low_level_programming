#include "hash_tables.h"

#define CAPACITY 50000 
unsigned long hash_function(const char* str)
{
        int j;
    unsigned long i = 0;

    for ( j = 0; str[j]; j++)
        i += str[j];

    return i % CAPACITY;
}

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t* array = create_item(key, value);
	unsigned long int count = 0;
	unsigned long int index = hash_function(key);
	hash_node_t* current_item = ht->array[index];
	if (current_item == NULL)
	{
		if (count == ht->size)
		{
			printf("Insert Error: Hash Table is full\n");
			free_array(array);
			return (0);
		}
		ht->array[index] = array;
		count++;
	}
	return (1);
}
