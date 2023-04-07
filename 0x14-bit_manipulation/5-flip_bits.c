#include "main.h"
/**
 * flip_bits - function that returns the number of bits you would need to flip
 * @m: first number
 * @n: second number
 *
 * Return: number of flip croo
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int i = 0;
	unsigned long int flip = (m ^ n);

	while (flip != 0)
	{
		i++;
		flip &= (flip - 1);
	}
	return (i);
}

