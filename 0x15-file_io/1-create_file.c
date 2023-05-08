#include "main.h"
#include <string.h>
/**
 * create_file - to create a file
 * @filename: pointer to the file
 * @text_content: pointer to where the text string is
 *
 * Return: 1 if success.
 */
int create_file(const char *filename, char *text_content)
{
	int w;
	int fd;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 600);
	if (fd == -1)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		w = write(fd, text_content, strlen(text_content));
		if (w == -1)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}

