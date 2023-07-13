#include "hash_tables.h"

/**
 * slist - function for insert new node in sorted
 * @ht: pointer
 * @nnode: pointer
 */
void slist(shash_table_t *ht, shash_node_t *nnode)
{
	shash_node_t *sbucket = ht->shead;

	if (sbucket == NULL)
	{
		ht->shead = ht->stail = nnode;
		nnode->snext = nnode->sprev = NULL;
		return;
	}
	do {
		if (strcmp(nnode->key, sbucket->key) < 0)
		{
			nnode->snext = sbucket;
			nnode->sprev = sbucket->sprev;

			if (!sbucket->sprev)
				ht->shead = nnode;
			else
				sbucket->sprev->snext = nnode;
			sbucket->sprev = nnode;
			return;
		}
		sbucket = sbucket->snext;
	} while (sbucket);
	nnode->sprev = ht->stail;
	nnode->snext = ht->stail->snext;
	ht->stail->snext = nnode;
	ht->stail = nnode;
}

/**
 * shash_table_create - creates hash tables
 * @size: size
 * Return: pointer
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	if (size == 0)
		return (NULL);

	ht = calloc(1, sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	return (ht);
}

/**
 * shash_table_set - function that adds an element
 * @ht: pointer to hash table
 * @key: key to add the element
 * @value: value to add the element
 * Return: 1 for succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i = 0;
	char *valuec, *keyc;
	shash_node_t  *buc, *nnode;

	if (!ht || !key || !*key || !value)
		return (0);
	valuec = strdup(value);
	if (!valuec)
		return (0);
	i = key_index((const unsigned char *)key, ht->size);
	buc = ht->array[i];

	while (buc != NULL)
	{
		if (strcmp(key, buc->key) == 0)
		{
			free(buc->value);
			buc->value = valuec;
			if (buc->value == NULL)
				return (0);
			return (1);
		}
		buc = buc->next;
	}
	nnode = calloc(1, sizeof(shash_node_t));
	if (nnode == NULL)
	{
		free(valuec);
		return (0);
	}
	keyc = strdup(key);
	if (!keyc)
		return (0);
	nnode->key = keyc;
	nnode->value = valuec;
	nnode->next = ht->array[i];
	ht->array[i] = nnode;
	slist(ht, nnode);
	return (1);
}
/**
 * shash_table_get - function to retrieve the value
 * @ht: pointer to hash table
 * @key: key to retrive value
 * Return: value or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int i = 0;
	shash_node_t  *buc;

	if (!ht || !key || !*key)
		return (NULL);
	i = key_index((const unsigned char *)key, ht->size);
	buc = ht->array[i];
	while (buc)
	{
		if (!strcmp(key, buc->key))
			return (buc->value);
		buc = buc->next;
	}
	return (NULL);
}

/**
 * shash_table_print - print the key:value from table
 * @ht: pointer to hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *buc;
	int i = 0;

	if (!ht)
		return;
	buc = ht->shead;
	printf("{");
	while (buc)
	{
		if (i)
			printf(", ");
		printf("'%s': '%s'", buc->key, buc->value);
		i = 1;
		buc = buc->snext;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - print the key:value from hash table in reverse
 * @ht: pointer to hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *buc;
	int i = 0;

	if (!ht)
		return;
	buc = ht->stail;
	printf("{");
	while (buc)
	{
		if (i)
			printf(", ");
		printf("'%s': '%s'", buc->key, buc->value);
		i = 1;
		buc = buc->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - delete and free nodes
 * @ht: pointer to hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *buc, *freee;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		buc = ht->array[i];
		while (buc)
		{
			freee = buc;
			buc = buc->next;
			if (freee->key)
				free(freee->key);
			if (freee->value)
				free(freee->value);
			free(freee);
		}
	}
	free(ht->array);
	free(ht);
}
