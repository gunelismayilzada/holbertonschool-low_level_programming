#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase except 'q' and 'e',
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch = 'a';

	while (ch <= 'z')
	{
		if (ch != 'q' && ch != 'e')
			putchar(ch);
		ch++;
	}

	putchar('\n');

	return (0);
}
