#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure that stores info about a dog
 * @name: Dog's name (string)
 * @age: Dog's age (float)
 * @owner: Owner's name (string)
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};
void init_dog(struct dog *d, char *name, float age, char *owner)

#endif /* DOG_H */
