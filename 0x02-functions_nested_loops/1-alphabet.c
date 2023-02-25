#include "main.h"

/*
 * print alphabet
 *
 *always Return: 0
 */
void print_alphabet(void)
{
	char c;
	for (c = 'a'; c <= 'z'; c++)
	{
		_putchar("%c", c);
	}
	_putchar('\n');
}
