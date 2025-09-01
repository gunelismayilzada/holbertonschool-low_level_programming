#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated duplicate of the string str
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string,
 *         or NULL if str is NULL or memory allocation fails
 */
char *_strdup(char *str)
{
	char *copy;
	unsigned int i, len;

	if (str == NULL)
		return (NULL);

	/* Calculate length of str */
	len = 0;
	while (str[len] != '\0')
		len++;

	/* Allocate memory for copy + null terminator */
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);

	/* Copy characters */
	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[len] = '\0'; /* Null terminate */

	return (copy);
}
