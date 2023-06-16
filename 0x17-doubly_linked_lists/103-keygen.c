#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * main - generate a keygen
 * @argc: no of arguments
 * @argv: arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	unsigned int num, i;
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}
	len = strlen(argv[1]);
	p[0] = l[(len ^ 59) & 63];
	for (num = 0, add = 0; num < len; num++)
		add += argv[1][num];
	p[1] = l[(add ^ 79) & 63];
	for (num = 0, i = 1; num < len; num++)
		i *= argv[1][num];
	p[2] = l[(i ^ 85) & 63];
	for (i = argv[1][0], num = 0; num < len; num++)
		if ((char)i <= argv[1][num])
			i = argv[1][num];
	srand(i ^ 14);
	p[3] = l[rand() & 63];
	for (i = 0, num = 0; num < len; num++)
		i += argv[1][num] * argv[1][num];
	p[4] = l[(i ^ 239) & 63];
	for (i = 0, num = 0; (char)num < argv[1][0]; num++)
		i = rand();
	p[5] = l[(i ^ 229) & 63];
	printf("%s\n", p);
	return (0);
}
