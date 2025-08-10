#include "main.h"

/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string to print
 *
 * Description: This function takes a string 's' and prints its characters
 * starting from the last character to the first, effectively printing the
 * string in reverse order. After printing, it outputs a newline character.
 */
void print_rev(char *s)
{
	int length = 0;

	/* Calculate the length of the string */
	while (s[length] != '\0')
	{
		length++;
	}

	/* Print the string in reverse */
	while (length > 0)
	{
		length--;
		_putchar(s[length]);
	}

	/* Print a newline at the end */
	_putchar('\n');
}
Salam 

