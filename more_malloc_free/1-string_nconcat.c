#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to newly allocated space containing s1 followed by
 *         first n bytes of s2, null-terminated, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i;
	char *new_str;

	/* Treat NULL as empty string */
	if (s1)
	{
		while (s1[len1])
			len1++;
	}

	if (s2)
	{
		while (s2[len2])
			len2++;
	}

	/* If n is greater or equal to length of s2, use entire s2 */
	if (n >= len2)
		n = len2;

	/* Allocate memory for new string */
	new_str = malloc(len1 + n + 1);
	if (!new_str)
		return (NULL);

	/* Copy s1 */
	for (i = 0; i < len1; i++)
		new_str[i] = s1[i];

	/* Copy first n bytes of s2 */
	for (i = 0; i < n; i++)
		new_str[len1 + i] = s2[i];

	/* Null terminate */
	new_str[len1 + n] = '\0';

	return (new_str);
}
