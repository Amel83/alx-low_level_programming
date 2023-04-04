#include "lists.h"
/**
 * listint_len - number of the list
 * @h: pointer for the lists
 *
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	int i = 0;

	for (i = 0; h != NULL; i++)
	{
		h = h->next;
	}
	return (i);
}
