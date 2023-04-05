#include "lists.h"
/**
 * add_nodeint - add a new node at the begunning
 * @n: consists of integer
 * @head: pointer for the list at the start
 * Return: the head
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	if(head == NULL || *head == NULL)
		return (NULL);
	new_node = malloc(sizeof(listint_t));
	if(new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;
	
	return (*head);
}
