#include "lists.h"
/**
 * get_nodeint_at_end - returns the nth node of a listint_t linked lis
 * @index - theth number
 * 
 * Returns: head elements of the list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
        unsigned int i =0;

        for (i = 0; i < index; i++)
        {
                if(head == NULL)
                        return(NULL);
                head = head->next;
        }
        return (head);
}
