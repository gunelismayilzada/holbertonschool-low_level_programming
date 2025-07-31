#include "main.h"

/**
 * print_numbers - prints the numbers 0 to 9 followed by a new line
 */
void print_numbers(void)
{
	char c;

	for (c = 0; c <= 9; c++)
		_putchar(c + '0'); /* convert number to ASCII digit */

	_putchar('\n');
}
