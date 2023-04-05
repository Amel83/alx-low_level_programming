#include "lists.h"
/**
 * add_nodeint_end - add a node at the end
 * @head: points the element in the list
 * @n: is number of data
 *
 * Return: the new node created
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node;
listint_t *temp = *head;

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = NULL;
if (*head == NULL)
{
*head = new_node;
return (new_node);
}
while (temp->next != NULL)
temp = temp->next;
temp->next = new_node;

return (new_node);
}
