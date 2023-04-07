#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - function to change binaryn numbers to integer
 * @b: points to 0, 1
 *
 * Return: unsigned int or NULL
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int a = 0;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		a = a << 1;
		if (b[i] == '1')
		a = a | 1;
	}
	return (a);
}
