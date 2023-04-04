#include "lists.h"
/**
 *
 *
 *
 *
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *temp;
	listint_t *new_node;

	temp = *head;
	if((*head = NULL))
		return(NULL);
	new_node = malloc(sizeof(listint_t));
	if((new_node = NULL))
		return (NULL);
	new_node->n = n;
	new_node->next = NULL;
	return (new_node);
	if((new_node == NULL))
		return (NULL);
	if((*head) == NULL)
	{
		(*head) = new_node;
		return(*head);
	}
	while(temp != NULL)
		temp = temp->next;
	temp->next = new_node;
	return(*head);
}
