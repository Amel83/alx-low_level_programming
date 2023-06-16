#include "lists.h"

/**
 * get_dnodeint_at_index - adds a node at index
 * @head: points to the first list
 * @index: positiin to add the new node
 * Return: If fail NULL on success head
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
