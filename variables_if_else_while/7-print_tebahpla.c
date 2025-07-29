#include <stdio.h>

/**
 * main - Prints the lowercase alphabet in reverse,
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = 'z';

	while (ch >= 'a')
	{
		putchar(ch);
		ch--;
	}

	putchar('\n');

	return (0);
}
