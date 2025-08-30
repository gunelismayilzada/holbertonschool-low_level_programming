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
    
    /* Allocate memory for the new dog */
    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    /* Allocate memory for the name and copy it */
    dog->name = malloc(strlen(name) + 1);  /* +1 for the null terminator */
    if (dog->name == NULL)
    {
        free(dog);  /* Free previously allocated memory */
        return (NULL);
    }
    strcpy(dog->name, name);  /* Copy the name */

    /* Allocate memory for the owner and copy it */
    dog->owner = malloc(strlen(owner) + 1);  /* +1 for the null terminator */
    if (dog->owner == NULL)
    {
        free(dog->name);  /* Free the name if owner allocation fails */
        free(dog);  /* Free the dog itself */
        return (NULL);
    }
    strcpy(dog->owner, owner);  /* Copy the owner */

    /* Set the dog's age */
    dog->age = age;

    return (dog);
}
