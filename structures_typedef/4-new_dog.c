#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Dog's name
 * @age: Dog's age
 * @owner: Dog's owner
 * 
 * Return: Pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    
    /* Allocate memory for a new dog */
    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    /* Allocate memory and copy the name */
    dog->name = strdup(name);
    if (dog->name == NULL)
    {
        free(dog);  /* Free previously allocated memory */
        return (NULL);
    }

    /* Allocate memory and copy the owner */
    dog->owner = strdup(owner);
    if (dog->owner == NULL)
    {
        free(dog->name);  /* Free the name if owner allocation fails */
        free(dog);  /* Free the dog itself */
        return (NULL);
    }

    /* Set the dog's age */
    dog->age = age;

    return (dog);
}
