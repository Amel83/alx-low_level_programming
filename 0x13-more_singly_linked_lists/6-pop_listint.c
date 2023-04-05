#include "lists.h"
/**
 * pop_listint - it deletes the head and returns the head node data
 * @head: points the element
 * Return: nothing
 */
int pop_listint(listint_t **head)
{
	int i = 0;
	listint_t *temp;

	i = temp->n;
	*head = (*head)->next;
	free(temp);
	return (i);
	if (*head == NULL || head == NULL)
	return (0);
}
