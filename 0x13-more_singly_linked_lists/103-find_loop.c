#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the element of the head
 *
 * Return: address of the node where the loop starts loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *temp, *ptr;

	if (head == NULL || head->next == NULL)
		return (NULL);
	temp = head->next;
	ptr = head->next->next;
	while (ptr && ptr->next)
	{
		if (temp == ptr)
		{
			temp = head;
			while (temp != ptr)
			{
				temp = temp->next;
				ptr = ptr->next;
			}
			return (temp);
		}
		temp = temp->next;
		ptr = ptr->next->next;
	}
	return (NULL);
}

