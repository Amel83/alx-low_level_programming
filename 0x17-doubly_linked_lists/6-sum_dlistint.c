#include "lists.h"

/**
 * sum_dlistint - Sums all the data 
 * @head: points to the head
 * Return: the sum 
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
