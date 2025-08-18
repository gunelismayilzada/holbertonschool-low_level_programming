#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to scan.
 * @accept: The string containing accepted characters.
 *
 * Return: The number of bytes in the initial segment of s
 *         consisting only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *a;

	while (*s)
	{
		a = accept;
		while (*a)
		{
			if (*s == *a)
				break;
			a++;
		}
		if (*a == '\0') /* Not found in accept */
			return (count);
		count++;
		s++;
	}
	return (count);
}
