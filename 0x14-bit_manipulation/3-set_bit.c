#include "main.h"
/**
 * set_bit - function that sets the value of a bit to 1 at a given index
 * @index: given position
 * @n: variable to use
 *
 * Return: value of the bit at index index or -1 if an error occured
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= 32)
	{
		return (-1);
	}
	*n |= (1 << index);

	return (1);
}

