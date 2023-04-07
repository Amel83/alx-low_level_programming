#include "main.h"
#include <stdio.h>

/**
 * print_binary - convert int to binary
 * @n: the integer number
 *
 * Return: binary numbers
 */
void print_binary(unsigned long int n)
{
	unsigned long int i;
	unsigned long int mask = 1 << 31;

	for (i = 0; i < 31; i++)
	{
		putchar((n & mask) ? '1' : '0');
		mask >>= 1;
	}
}
