#include "main.h"
/**
 * get_bit -  function that returns the value of a bit at a given index.
 * @index: is the index, starting from 0
 * @n: nhmber used
 *
 * Return: the value of the bit at index index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int i;

	unsigned int long j;

	if (index >= 32)
	{
		return (-1);
	}
	j = 1 << index;
	i = (n & j) >> index;
	return (i);
}
