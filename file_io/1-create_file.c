#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * create_file - Creates a file and writes text_content to it.
 * @filename: Name of the file to create.
 * @text_content: Null-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len = 0, written;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
		len = strlen(text_content);

	if (len > 0)
	{
		written = write(fd, text_content, len);
		if (written != len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
