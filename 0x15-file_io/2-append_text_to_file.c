#include <stdlib.h>
#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
/**
 * append_text_to_file - adding chars at the end of a file
 * @filename: file to adjust
 * @text_content: file to add
 * Return: the added file
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t len;
	ssize_t ret;
	int fd;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		len = my_strlen(text_content);
		ret = write(fd, text_content, len);
		if (ret != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

/**
 * my_strlen - to count the length of string
 * @str: pointer to string
 * Return: the number of chars
 */
size_t my_strlen(char *str)
{
	size_t length = 0;

	while (*str++ != '\0')
	{
		length++;
	}
	return (length);
}

