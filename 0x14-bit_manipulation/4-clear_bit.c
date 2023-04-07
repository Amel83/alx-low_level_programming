#include "main.h"
/**
 * clear_bit -  function that sets the value of a bit to 0 at a given index
 * @index: fix the position required
 * @n: variable
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i;

	if (index >= 32)
	{
		return (-1);
	}
	i  = ~(1 << index);
	*n &= i;
	return (1);
}
