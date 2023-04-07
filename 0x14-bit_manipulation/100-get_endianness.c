#include <stdio.h>
#include "main.h"
/**
 * get_endianness - function that checks the endianness.
 * 
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	char *c;
	unsigned int x = 0x76543210;
	
	x = 2;
	c = (char*) &x;
	if (*c)
		return (1);
	return (0);

}
