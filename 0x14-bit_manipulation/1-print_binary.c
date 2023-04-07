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
	unsigned long int j = (unsigned long int)1 << (sizeof(unsigned long int)*8 - 1);
	unsigned long int i;
	
	for (i = 0; i < sizeof(unsigned long int)*8; i++)
	{
        	if((n & j) == 0)
		{
			putchar ('0');
		}
		else
		{
			putchar('1');
		}
		j >>= 1;
	}
	putchar('\n');
}
