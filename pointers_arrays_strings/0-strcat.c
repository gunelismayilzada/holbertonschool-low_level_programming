#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    /* Find the end of the dest string */
    while (dest[i] != '\0')
    {
        i++;
    }

    /* Append src to dest */
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* Null-terminate the resulting string */
    dest[i] = '\0';

    return dest;
}
