#include <stdio.h>    /* For dprintf - though it's technically a system-level function */
#include <stdlib.h>   /* For exit */
#include <unistd.h>   /* For read, write, close */
#include <fcntl.h>    /* For open and file control options */
#include "main.h"     /* Your custom header file */

/*
 * Note: You can use dprintf, which is available via <stdio.h>
 * or directly as a system call in some environments. Since the
 * requirements allow it, we will use it for error output.
 * The constants STDIN_FILENO, STDOUT_FILENO, and STDERR_FILENO
 * are defined in <unistd.h>
 */

#define BUF_SIZE 1024

/**
 * error_exit - Helper function to print an error message and exit.
 * @code: The exit code.
 * @format: The format string for dprintf.
 * @arg: The argument for the format string (usually a filename or fd).
 */
void error_exit(int code, const char *format, const char *arg)
{
    /* Use dprintf to print the error message to POSIX standard error (fd 2) */
    dprintf(STDERR_FILENO, format, arg);
    exit(code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t r_count, w_count;
    char buffer[BUF_SIZE];
    char *file_from, *file_to;

    /* 1. Check argument count */
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    file_from = argv[1];
    file_to = argv[2];

    /* 2. Open file_from for reading (O_RDONLY) */
    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
    {
        /* Error: Can't read from file */
        error_exit(98, "Error: Can't read from file %s\n", file_from);
    }

    /*
     * 3. Open/Create file_to for writing.
     * O_CREAT: Create the file if it does not exist.
     * O_WRONLY: Open for writing only.
     * O_TRUNC: Truncate to length 0 if the file already exists.
     * The permissions are set to rw-rw-r-- (0664).
     */
    fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_to == -1)
    {
        /* Error: Can't write to file_to (creation failed) */
        error_exit(99, "Error: Can't write to %s\n", file_to);
    }

    /* 4. Copy loop: read 1024 bytes, then write */
    while ((r_count = read(fd_from, buffer, BUF_SIZE)) > 0)
    {
        w_count = write(fd_to, buffer, r_count);

        if (w_count == -1 || w_count != r_count)
        {
            /* Check for write error or if not all bytes were written */
            error_exit(99, "Error: Can't write to %s\n", file_to);
        }
    }

    /* Check if the loop terminated due to a read error */
    if (r_count == -1)
    {
        error_exit(98, "Error: Can't read from file %s\n", file_from);
    }

    /* 5. Close file descriptors, handling errors */
    if (close(fd_from) == -1)
    {
        /* Must convert fd_from to a string for dprintf */
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    if (close(fd_to) == -1)
    {
        /* Must convert fd_to to a string for dprintf */
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}