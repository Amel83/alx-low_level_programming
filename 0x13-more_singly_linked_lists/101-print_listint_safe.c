#include "lists.h"
/**
 * find_loop - print lists with a loop
 * @head: points to the linked list
 *
 * Return: return(NULL), if no address to print or return(address of loop)
 */
listint_t *find_loop(listint_t *head)
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

/**
 * print_listint_safe - prints a looo of linked list
 * @head: pointer to the start  of the list
 *
 * Return: i which is the number of lists
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i = 0;
	int count;
	listint_t *loopfound;

	loopfound = find_loop((listint_t *) head);
	for (i = 0, count = 1; (head != loopfound || count) && head != NULL; i++)
	{
		printf("[%p] %d\n", (void *) head, head->n);
		if (head == loopfound)
			count = 0;
		head = head->next;
	}
	if (loopfound  != NULL)
		printf("-> [%p] %d\n", (void *) head, head->n);
	return (i);
}
