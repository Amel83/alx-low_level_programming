#include "lists.h"
/**
 * free_listint2 - frees occupied memories
 * @head - points tothe elements
 *
 * Return: void
 */
void free_listint2(ilistint_t **head)
{
        listint_t *temp;

        if (head == NULL)
                return;
        while (*head != NULL)
        {
                temp = *head;
                *head = (*head)->next;
                free(temp);

        }
}
