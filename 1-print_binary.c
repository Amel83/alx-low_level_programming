#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to print in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int len = sizeof(unsigned long int) * 8;

	while (len--)
	{
		if ((n & (mask << len)) != 0)
		{
			_putchar('1');
		}
		else if (len == 0 || (n & (mask << (len - 1))) != 0)
		{
			_putchar('0');
		}
	}
}

