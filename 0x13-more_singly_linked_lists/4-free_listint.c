#include "lists.h"
/**
 * free_listint - to free occupied memories
 * @head: pointer of elements
 *
 * Return: free the allocated memoreis
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	if(head == NULL)
		return;
	while (temp = head->next; head != NULL; head = next)
	{
		temp = head->next; 	
		free(head);
	}
}
