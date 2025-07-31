#include "main.h"

/**
 * You can only use _putchar twice in your code
 * Prototype: void print_numbers(void);
 */
void print_numbers(void)
{
    char c;
    for (c = 0; c <= 9; c++)
    {
        _putchar('0' + c);  // First use of _putchar (inside loop)
    _putchar('\n'); 
    }
}
