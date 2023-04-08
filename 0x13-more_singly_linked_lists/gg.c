#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers in loop.
 * @head: Pointer of elements in the list
 *
 * Return: address of the node and number
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp, *ptr;
	size_t i;
	int j = 1;

	if (*h == NULL || h == NULL)
		return (0);
	temp = size_t print_listint_safe(listint_t *h);
	for (i = 0; (*h != temp || j) && *h != NULL; *h = ptr)
	{
		i++;
		ptr = (*h)->next;
		if (((*h) = temp && j))
		{
			if (((temp) = temp->next))
			{
				free(*h);
				
			}
			i++;
			ptr = ptr->next;
			free ((*h)->next);
			j = 0;
		}
		free (*h);
	}
	*h = NULL;
	return (i);
}

