#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUF_SIZE 1024
#define STDERR_FILENO 2 // Defined in unistd.h, but explicit for clarity

void error_exit(int code, const char *format, const char *arg)
{
    dprintf(STDERR_FILENO, format, arg);
    exit(code);
}

int main(int argc, char *argv[])
{
    int fd_from, fd_to;
    ssize_t r_count, w_count;
    char buffer[BUF_SIZE];
    char *file_from, *file_to;

    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }

    file_from = argv[1];
    file_to = argv[2];

    /* Open file_from for reading */
    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file %s\n", file_from);

    /* Open/Create file_to for writing (O_CREAT | O_WRONLY | O_TRUNC, 0664) */
    fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
    if (fd_to == -1)
        error_exit(99, "Error: Can't write to %s\n", file_to);

    /* --- Core Copy Loop --- */
    while (1)
    {
        r_count = read(fd_from, buffer, BUF_SIZE);

        /* 1. Check for read error immediately */
        if (r_count == -1)
        {
            error_exit(98, "Error: Can't read from file %s\n", file_from);
        }
        
        /* 2. Check for end-of-file (read returns 0) and break the loop */
        if (r_count == 0)
        {
            break;
        }

        /* 3. If r_count > 0, attempt to write */
        w_count = write(fd_to, buffer, r_count);

        if (w_count == -1 || w_count != r_count)
        {
            /* Check for write error or if not all bytes were written */
            error_exit(99, "Error: Can't write to %s\n", file_to);
        }
    }
    /* --- End Core Copy Loop --- */


    /* Close file_from */
    if (close(fd_from) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
        exit(100);
    }

    /* Close file_to */
    if (close(fd_to) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
        exit(100);
    }

    return (0);
}