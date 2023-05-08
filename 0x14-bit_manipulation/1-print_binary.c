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
	unsigned long int i = 0;
	unsigned long int j = 1 << i;
	
	if ((i = sizeof(unsigned long int)*8))
	{
        	i++;
		if((n & j) == 0)
		{
			putchar('0');
		}
		else
		{
			putchar('1');
		}
	}
	putchar('\n');
}
