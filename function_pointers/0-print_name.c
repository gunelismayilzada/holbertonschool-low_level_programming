#include <stdio.h>
#include "function_pointers.h"

/**
 * print_upper - Prints name in uppercase
 * @name: The name to print
 */
void print_upper(char *name)
{
	while (*name)
	{
		putchar(toupper(*name));
		name++;
	}
	putchar('\n');
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	print_name("Alice", print_upper);
	return (0);
}
