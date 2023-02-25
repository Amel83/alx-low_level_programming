#include "main.h"

/*
 * print alphabet
 *
 *always Return: 0
 */
void print_alphabet(void)
{
	char i;
	for (i = 'a'; i <= 'z'; i++)
	{
		_putchar('%c', i);
	}
	_putchar('\n');
}
