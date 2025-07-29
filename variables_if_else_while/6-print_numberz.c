#include <stdio.h>

/**
 * main - Prints all single digit numbers of base 10 starting from 0,
 * followed by a new line, without using char variables.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int digit = 0;

	while (digit < 10)
	{
		putchar(digit + '0');
		digit++;
	}

	putchar('\n');

	return (0);
}
