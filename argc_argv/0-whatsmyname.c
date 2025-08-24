#include <stdio.h>

/**
 * main - prints the program's name (argv[0])
 * @argc: argument count (not used)
 * @argv: argument vector (array of strings)
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    (void)argc;          // Silence unused parameter warning
    printf("%s\n", argv[0]);
    return 0;
}
