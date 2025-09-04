#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: string to print
 * @f: pointer to function that takes a char * as parameter
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}