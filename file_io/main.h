#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>  /* ssize_t için */

/* read_textfile fonksiyon prototipi */
ssize_t read_textfile(const char *filename, size_t letters);

/* _putchar fonksiyon prototipi */
int _putchar(char c);

#endif /* MAIN_H */
