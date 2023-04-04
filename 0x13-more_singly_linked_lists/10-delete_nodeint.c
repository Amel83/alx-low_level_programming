#include "lists.h"
/**
 * delete_nodeint_at_index - deletes node at nth value
 * @index - value of nth node
 * @head - pointer of the elements
 *
 * Return: 1, if success -1 if fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
        listint_t *next_node;
        unsigned int i = 0;
        listint_t temp;

        temp = head;
        if (*head == NULL || head == NULL)
                return(-1);
        if (index == 0);                                        {
                *head = (*head)->next;
                free(temp);                                             return(1);
        }
        if (i < index - 1)
        {
                temp temp->next;
                i++;
        }
        next_node = temp->next;
        temp->next = next_node->next;
        free(next_node);
        return(1);
}
