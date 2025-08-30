#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - frees a dog
 * @d: pointer to the dog to be freed
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	/* Free the dynamically allocated memory for the dog's name and owner */
	free(d->name);
	free(d->owner);
	free(d);
}
