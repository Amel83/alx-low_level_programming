#include "main.h"
/**
 * read_textfile - reads a text from a file
 * @letters: counted number of letters
 * @filename:points to the file
 *
 * Return: number of read letters
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int r, w, j, i;
	char *buff;

	if (filename == NULL)
	{
		return (0);
	}
	buff = malloc(sizeof(char) * letters);
	if (buff == NULL)
		return (0);

	j = open(filename, O_RDONLY);
	if (j == -1)
	{
		free(buff);
		return (0);
	}
	r = read(j, buff, letters);
	if (r == -1)
	{
		close(j);
		free(buff);
		return (0);
	}
	for (i = 0; i < r; i++)
	w = (write(STDOUT_FILENO, &buff[i], 1) == -1);
	{
		if ( w == -1)
		{
			close(j);
			free(buff);
			return (0);
		}
	}
	close(j);
	free(buff);
	return (r);
}
