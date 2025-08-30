#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns length of string
 * @s: the string
 * 
 * Return: length
 */
int _strlen(char *s)
{
    int i = 0;

    while (s[i])
        i++;

    return (i);
}

/**
 * _strcpy - copies string from src to dest
 * @dest: destination
 * @src: source
 * 
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return (dest);
}

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 * 
 * Return: pointer to new dog, or NULL if failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *d;
    char *n, *o;

    d = malloc(sizeof(dog_t));
    if (d == NULL)
        return (NULL);

    n = malloc(_strlen(name) + 1);
    if (n == NULL)
    {
        free(d);
        return (NULL);
    }

    _strcpy(n, name);

    o = malloc(_strlen(owner) + 1);
    if (o == NULL)
    {
        free(n);
        free(d);
        return (NULL);
    }

    _strcpy(o, owner);

    d->name = n;
    d->age = age;
    d->owner = o;

    return (d);
}
