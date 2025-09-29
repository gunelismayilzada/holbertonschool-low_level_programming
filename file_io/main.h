#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

/**
 * error_exit - Prints an error message and exits with a specific code
 * @code: Exit code
 * @message: Error message format
 * @arg: Argument to format into message
 */
void error_exit(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
 * main - Copies the content of a file to another file
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 on success, exits with specific codes on failure
 */
int main(int ac, char **av)
{
	int file_from, file_to, r, w;
	char buffer[1024];
	struct stat st_from, st_to;

	if (ac != 3)
		error_exit(97, "Usage: cp file_from file_to\n", "");

	/* Check if source and destination are the same file */
	if (stat(av[1], &st_from) == 0 && stat(av[2], &st_to) == 0)
	{
		if (st_from.st_ino == st_to.st_ino && st_from.st_dev == st_to.st_dev)
			error_exit(98, "Error: Can't read from file %s\n", av[1]);
	}

	file_from = open(av[1], O_RDONLY);
	if (file_from == -1)
		error_exit(98, "Error: Can't read from file %s\n", av[1]);

	file_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close(file_from);
		error_exit(99, "Error: Can't write to %s\n", av[2]);
	}

	while ((r = read(file_from, buffer, 1024)) > 0)
	{
		w = write(file_to, buffer, r);
		if (w != r)
		{
			close(file_from);
			close(file_to);
			error_exit(99, "Error: Can't write to %s\n", av[2]);
		}
	}

	if (r == -1)
	{
		close(file_from);
		close(file_to);
		error_exit(98, "Error: Can't read from file %s\n", av[1]);
	}

	if (close(file_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from), exit(100);

	if (close(file_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to), exit(100);

	return (0);
}
