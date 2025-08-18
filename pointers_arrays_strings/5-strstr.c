#include "main.h"
#include <stddef.h> /* For NULL */

/**
 * _strstr - Locates a substring.
 * @haystack: The string to search in.
 * @needle: The substring to find.
 *
 * Return: Pointer to the beginning of the located substring,
 *         or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	char *h;
	char *n;

	if (*needle == '\0')
		return (haystack);

	while (*haystack)
	{
		if (*haystack == *needle)
		{
			h = haystack;
			n = needle;

			while (*h && *n && (*h == *n))
			{
				h++;
				n++;
			}

			if (*n == '\0')
				return (haystack);
		}
		haystack++;
	}

	return (NULL);
}
