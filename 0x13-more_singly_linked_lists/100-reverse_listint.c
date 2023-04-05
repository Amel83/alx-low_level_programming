#include "lists.h"
/**
 * reverse_listint - toreverse the linked lists
 * @head: points the element
 *
 * Return: the reversed elements of the link
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = 0;
	listint_t *nextnode = *head;

	while (*head != NULL)
	{
		nextnode = nextnode->next;
		(*head)->next = (prev);
		prev = (*head);
		(*head) = nextnode;
	}
	(*head) = prev;
	return (*head);
}
