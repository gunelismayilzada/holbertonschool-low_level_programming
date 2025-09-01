#include <stdlib.h>

/**
 * str_concat - concatenates two strings into a newly allocated space
 * @s1: first string (can be NULL, treated as empty string)
 * @s2: second string (can be NULL, treated as empty string)
 *
 * Return: pointer to newly allocated string containing s1 followed by s2,
 *         or NULL if memory allocation fails
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int i, j, len1, len2;

	/* Treat NULL as empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Find lengths of s1 and s2 */
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;

	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	/* Allocate memory for concatenated string + null terminator */
	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
		return (NULL);

	/* Copy s1 into concat */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];

	/* Append s2 to concat */
	for (j = 0; j < len2; j++)
		concat[i + j] = s2[j];

	/* Null terminate */
	concat[len1 + len2] = '\0';

	return (concat);
}
