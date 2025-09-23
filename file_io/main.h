#ifndef MAIN_H
#define MAIN_H
#include <fcntl.h>   /* open */
#include <unistd.h>  /* read, write, close */
#include <stdlib.h>  /* malloc, free */
#include "main.h"


#include <unistd.h>  /* For ssize_t */

ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c);

#endif /* MAIN_H */
