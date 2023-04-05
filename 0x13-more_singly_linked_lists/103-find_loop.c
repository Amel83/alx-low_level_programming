#include "lists.h"

/**
 * find_listint_loop - searches for the loop from list
 * @head: pointer to the first element of the list
 *
 * Return: returns(address of loop),  return(NULL) if no loop found
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *last, *temp;

	if (head == NULL)
		return (NULL);
	for (temp = head->next; temp != NULL; temp = temp->next)
	{
		if (temp == temp->next)
			return (temp);
		for (last = head; last != temp; last = last->next)
			if (last == temp->next)
				return (temp->next);
	}

	return (NULL);
}
