#include <stdio.h>

/**
 * main - Prints all numbers of base 16 in lowercase,
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char ch;

	/* Print digits 0 to 9 */
	for (ch = '0'; ch <= '9'; ch++)
		putchar(ch);

	/* Print letters a to f */
	for (ch = 'a'; ch <= 'f'; ch++)
		putchar(ch);

	putchar('\n');

	return (0);
}
