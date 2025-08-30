#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints a struct dog
 * @d: The struct dog to print
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	/* Check and print the name */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	/* Print the age */
	printf("Age: %.6f\n", d->age);

	/* Check and print the owner */
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
