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
	int num[32];
	unsigned long int i = 0;
	int j;
	if (n == 0)
	{
        	_putchar('0');
	       	return;
	}
	for ( ;n > 0; )
	{
		num[i++] = n % 2;
		n /= 2;
	}
	for (j = i-1; j >= 0; j--)
		_putchar(num[j]);
}
