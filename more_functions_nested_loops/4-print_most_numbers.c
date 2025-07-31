#include "main.h"

/**
 * Prototype: void print_most_numbers(void);
 * Do not print 2 and 4
 * You can only use _putchar twice in your code

 */
void print_most_numbers(void)
{   int i;
   for(i=0;i<=9 ; i++)
   {
    if (i==2 && i==4)
        continue;
        _putchar(i+'0');
   }
   _putchar('\n');
}

