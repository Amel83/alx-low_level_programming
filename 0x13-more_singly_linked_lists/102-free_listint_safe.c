#include "lists.h"

/**
 * free_listint_safe - frees node with a loop
 * @h: head of the elements in the list
 *
 * Return: freed node
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *next, *loopfound;
	size_t i;
	int count = 1;

	if (h == NULL || *h == NULL)
		return (0);

	loopfound = find_loop(*h);
	for (i = 0; (*h != loopfound || count) && *h != NULL; *h = next)
	{
		i++;
		next = (*h)->next;
		if (*h == loopfound && count)
		{
			if (loopfound == loopfound->next)
			{
				free(*h);
				break;
			}
			i++;
			next = next->next;
			free((*h)->next);
			count = 0;
		}
		free(*h);
	}
	*h = NULL;
	return (i);
}
