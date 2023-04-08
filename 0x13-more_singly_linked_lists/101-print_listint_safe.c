#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers in loop.
 * @head: Pointer of elements in the list
 *
 * Return: address of the node and number
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *ptr, *temp;
	size_t i = 0;

	if (head == NULL)
		exit(98);

	ptr = head;
	while (ptr != NULL)
	{
		printf("[%p] %d\n", (void *)ptr, ptr->n);
		i++;
		if (ptr <= ptr->next)
		{
			printf("-> [%p] %d\n", (void *)ptr->next, ptr->next->n);
			break;
		}
		temp = ptr;
		ptr = ptr->next;

		if (temp <= ptr)
		{
			printf("-> [%p] %d\n", (void *)ptr, ptr->n);
			break;
		}
	}
	return (i);
}

