#include "function_pointers.h"
#include <stddef.h>  /* Required for NULL */

/**
 * print_name - Calls a function to print a name.
 * @name: The name to be printed.
 * @f: A pointer to a function that takes a char * and returns void.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
