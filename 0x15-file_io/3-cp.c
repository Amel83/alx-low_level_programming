#include "main.h"
/**
 * main - copy files from 1 to another
 * @argv: accepts the 2 arguments
 * @argc: accepts the number of arguments
 * Return: void
 */
int main(int argc, char *argv[])
{
	ssize_t r, w;
	int fd_from, fd_to;
	char *file_from, *buff, *file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = argv[1];
	file_to = argv[2];
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	fd_to = open(file_to, O_CREAT | O_TRUNC | O_WRONLY, 664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}
	buff = malloc(sizeof(char)* fd_from);
	while ((r = read(fd_from, buff, BUFFER_SIZE)) > 0)
	{
		w = write(fd_to, buff, r);
		if (w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return 0;
}

