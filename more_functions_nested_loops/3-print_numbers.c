#include "main.h"

/**
 * You can only use _putchar twice in your code
 * Prototype: void print_numbers(void);
 */
void print_numbers(void)
{
    char i;
    for (int i = 0; i <= 9; i++)
    {
        _putchar('0' + i);  // First use of _putchar (inside loop)
        _putchar('\n'); 
    }
}
