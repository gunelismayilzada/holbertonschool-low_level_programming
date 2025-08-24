#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of command line arguments (unused)
 * @argv: array of command line arguments
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
    (void)argc; // argc not used, silence compiler warning
    printf("%s\n", argv[0]);
    return 0;
}
