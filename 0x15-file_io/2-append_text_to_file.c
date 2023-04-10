#include <stdio.h>
/**
 * append_text_to_file - write text from the end of the file
 * @text_content: points to the written text
 * @filename: points to the file
 *
 * Return: pointer
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int i;
	FILE *fp;

	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		return (-1);
	}
	fp = fopen(filename, "a");
	if (fp == NULL)
	{
		return (-1);
	}
	i = fputs(text_content, fp);
	if (i == EOF)
	{
		fclose(fp);
		return (-1);
	}
	fclose(fp);
	return (1);
}

