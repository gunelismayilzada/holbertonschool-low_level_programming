#include "main.h"
#include <stddef.h>  /* for NULL */

/**
 * _strchr - Locates the first occurrence of a character in a string.
 * @s: The string to search in.
 * @c: The character to find.
 *
 * Return: A pointer to the first occurrence of the character c in the string s,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (s);
        s++;
    }

    /* Check if c is the null terminator */
    if (c == '\0')
        return (s);

    return (NULL);
}
