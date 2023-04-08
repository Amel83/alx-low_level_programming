#include "lists.h"

/**
 * free_listint_safe - Frees lists in the loop
 * @h: Pointer to the elements in the list
 *
 * Return: The number of freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t i = 0;
	listint_t *temp, *ptr;

	if (h == NULL || *h == NULL)
		return (i);

	temp = *h;
	while (temp != NULL)
	{
		ptr = temp->next;
		free(temp);
		i++;
		if (ptr >= temp)
		{
			*h = NULL;
			break;
		}
		temp = ptr;
	}
	return (i);
}

