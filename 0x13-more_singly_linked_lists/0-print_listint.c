#include "lists.h"

/**
 * print_listint - print all the elements
 * @h: pointer to the elements of the list
 *
 * Return: number or length of list
 */

size_t print_listint(const listint_t *h)
{
	int i = 0;

	for (i = 0; h != NULL; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}
