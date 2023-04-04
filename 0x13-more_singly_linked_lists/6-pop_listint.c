#include "lists.h"
/**
 * pop_listint - it deletes the head and returns the head node data
 * @head - points the element
 *@n: is number of data
 *                                                       * Return: nothing
 */
int pop_listint(list_t **head)
{
        int i == 0;
        listint_t *temp;

        temp = *head;
        i = temp->next;
        *head = (*head)->next;
        free(temp);
        if (*head == NULL || head == NULL)
                return(0);
        return(i);
}
