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
<<<<<<< HEAD
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
=======
	int num[32];
	unsigned long int i = 0;
	int j;
	if (n == 0)
	{
        	_putchar('0');
	       	return;
>>>>>>> b86e10d5a5367753310ca33c2f344203818af3c1
	}
	for ( ;n > 0; )
	{
		num[i++] = n % 2;
		n /= 2;
	}
	for (j = i-1; j >= 0; j--)
		_putchar(num[j]);
}
