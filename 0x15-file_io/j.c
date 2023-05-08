#include <stdio.h>
#include <sys/types.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * append_text_to_file - write text from the end of the file
 * @text_content: points to the written text
 * @filename: points to the file
 *
 * Return: pointer
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t bytes;
	int i, j;
	size_t byte = 0;
	
	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		return (-1);
	}
	j = open(filename, O_WRONLY | O_APPEND);
	if (j == '\0')
	{
		return (-1);
	}
	text_content = malloc( sizeof(char) * byte);
	bytes = read(j, text_content, byte);
	for (i = 0; i <bytes; i++)
	if (write(STDOUT_FILENO, &text_content[i], byte) == -1)
	{
		free(text_content);
		close(j);
		return (-1);
	}
	close(j);
	return (1);
}
