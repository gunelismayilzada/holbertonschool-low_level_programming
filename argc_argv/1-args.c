#include <stdio.h>

/**
 * main - prints the number of arguments passed into it
 * @argc: argument count
 * @argv: argument vector (not used)
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	(void)argv; /* Silence unused parameter warning */
	printf("%d\n", argc - 1);
	return (0);
}
