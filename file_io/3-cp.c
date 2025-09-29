#define _GNU_SOURCE
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h> /* dprintf üçün icazə verilib */
/* #include "main.h" - Sizin header faylınız burada olmalıdır */

/**
 * exit_with_error - Prints an error message to stderr and exits.
 * @code: The exit code (97, 98, 99, 100).
 * @msg: The base error message string.
 * @file: The file name or FD value string/integer for formatting.
 */
void exit_with_error(int code, const char *msg, char *file)
{
    /* * Bu funksiya 97, 98 və 99 xətaları üçün istifadə olunur.
     * 100 xətası xüsusi format tələb edir, onu ayrı idarə edəcəyik.
     */
    if (code == 97)
        dprintf(STDERR_FILENO, "%s\n", msg);
    else if (code == 98)
        dprintf(STDERR_FILENO, "%s %s\n", msg, file);
    else if (code == 99)
        dprintf(STDERR_FILENO, "%s %s\n", msg, file);
    
    exit(code);
}

/**
 * close_file - closes a file descriptor and handles error 100.
 * @fd: file descriptor to close.
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
 * Return: 0 on success.
 */
int main(int ac, char *av[])
{
    char buf[1024];
    int lenr, lenw, file_from, file_to;

    if (ac != 3)
        exit_with_error(97, "Usage: cp file_from file_to", NULL);

    /* 1. Open file_from (Read Error Check) */
    file_from = open(av[1], O_RDONLY);
    if (file_from == -1)
        exit_with_error(98, "Error: Can't read from file", av[1]);

    /* 2. Open file_to (Write Error Check) */
    file_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (file_to == -1)
    {
        close_file(file_from); /* Fail fast on close 100 */
        exit_with_error(99, "Error: Can't write to", av[2]);
    }

    /* 3. Copy Loop */
    while ((lenr = read(file_from, buf, 1024)) > 0)
    {
        lenw = write(file_to, buf, lenr);
        
        if (lenw == -1 || lenw != lenr)
        {
            close_file(file_from); /* Fail fast on close 100 */
            close_file(file_to);   /* Fail fast on close 100 */
            exit_with_error(99, "Error: Can't write to", av[2]);
        }
    }
    
    /* 4. Final Read Error Check (lenr == -1) */
    if (lenr == -1)
    {
        close_file(file_from); /* Fail fast on close 100 */
        close_file(file_to);   /* Fail fast on close 100 */
        exit_with_error(98, "Error: Can't read from file", av[1]);
    }

    /* 5. Close Files (Handles Error 100 internally) */
    close_file(file_from);
    close_file(file_to);

    return (0);
}