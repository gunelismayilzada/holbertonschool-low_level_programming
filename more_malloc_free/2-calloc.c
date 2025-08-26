#include <stdlib.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size: size of each element
 *
 * Return: pointer to allocated memory, or NULL if it fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned int i;
    char *ptr;

    /* Check for zero input */
    if (nmemb == 0 || size == 0)
        return (NULL);

    /* Allocate memory */
    ptr = malloc(nmemb * size);
    if (ptr == NULL)
        return (NULL);

    /* Set allocated memory to 0 */
    for (i = 0; i < nmemb * size; i++)
        ptr[i] = 0;

    return (ptr);
}
