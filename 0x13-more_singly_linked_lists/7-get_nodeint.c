#include "lists.h"
/**
 * get_nodeint_at_index  - return the nth node of a listint_t linked list
 * @index: the length of number
 * @head: pointer to the listen elemenfs
 *
 * Return: pointer to  elements of the list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	for (i = 0; i < index; i++)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
