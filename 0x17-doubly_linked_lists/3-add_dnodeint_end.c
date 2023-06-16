#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - add node
 * @head: points the head
 * @n: data
 * Return: stop nagging me!!!
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *current = *head;
	dlistint_t *newnode = malloc(sizeof(dlistint_t));

	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		newnode->prev = current;
		current->next = newnode;
	}
	return (newnode);
}
