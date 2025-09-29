#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h> /* dprintf is allowed */
/* #include "main.h" - Sizin header faylınız burada olmalıdır */

/* Define the permissions mode */
#define FILE_PERMS (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH) /* 0664 */

/**
 * close_file - closes a file descriptor and handles error 100.
 * @fd: file descriptor to close.
 *
 * This function handles error 100 and exits immediately if close fails.
 */
void close_file(int fd)
{
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
        exit(100);
    }
}

/**
 * main - copy one file to another, new file with perms 664
 * usage - cp file_from file_to
 *
 * @ac: number of arg
 * @av: list of args
 *
 * Return: 0 on success. Exits with 97, 98, 99, or 100 on error.
 */
int main(int ac, char *av[])
{
    char buf[1024];
    int lenr, lenw;
    int fd_from, fd_to;
    char *file_from;
    char *file_to;

    if (ac != 3)
    {
        dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
        exit(97);
    }
    
    file_from = av[1];
    file_to = av[2];

    /* 1. Open file_from (Read Error Check 98) */
    fd_from = open(file_from, O_RDONLY);
    if (fd_from == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
        exit(98);
    }

    /* 2. Open file_to (Write Error Check 99) */
    fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMS);
    if (fd_to == -1)
    {
        close_file(fd_from);
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
        exit(99);
    }

    /* 3. Copy Loop (Prioritizing Read Error Check 98) */
    while (1)
    {
        lenr = read(fd_from, buf, 1024);

        /* CHECK 1: Read Error (-1) -> Exit 98 */
        if (lenr == -1)
        {
            close_file(fd_from);
            close_file(fd_to);
            dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
            exit(98);
        }
        
        /* CHECK 2: End Of File (0) -> Break Loop */
        if (lenr == 0)
        {
            break;
        }

        /* CHECK 3: Attempt Write */
        lenw = write(fd_to, buf, lenr);
        
        /* CHECK 4: Write Error (-1 or partial write) -> Exit 99 */
        if (lenw == -1 || lenw != lenr)
        {
            close_file(fd_from);
            close_file(fd_to);
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
            exit(99);
        }
    }

    /* 4. Close Files (Handles Error 100 internally) */
    close_file(fd_from);
    close_file(fd_to);

    return (0);
}