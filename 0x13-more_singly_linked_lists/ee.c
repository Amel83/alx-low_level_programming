#include "lists.h"

/**
 * print_listint_safe -  function that prints a linked list, with a loop
 * @head: Pointer for the elements of the list
 *
 * Return: address & of the list or exit 98 of head is null
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *ptr, *temp;
	size_t i = 0;

	if (head == NULL)
		exit(98);

	ptr = head;
	temp = head->next;

	while (temp != NULL && temp != ptr)
	{
        	printf("[%p] %d\n", (void *)ptr, ptr->n);
		i++;
		ptr = ptr->next;
		temp = temp->next;
		if (temp != NULL)
			temp= temp->next;
	}
	if (temp == NULL)
	{
		printf("[%p] %d\n", (void *)ptr, ptr->n);
		i++;
	}
	else
	{
		printf("[%p] %d\n", (void *)ptr, ptr->n);
		i++;
	while (ptr != temp)
        {
                printf("[%p] %d\n", (void *)ptr, ptr->n);
                i++;
                ptr = ptr->next;
        }
	}
	if (temp != NULL)
	{
		printf("-> [%p] %d\n", (void *)temp, temp->n);
                i++;
                ptr = ptr->next;
	}
	return (i);
}

