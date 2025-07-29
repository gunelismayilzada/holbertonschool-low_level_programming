#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: number to process
 *
 * Return: last digit of n
 */
int print_last_digit(int n)
{
    int last_digit;

    if (n < 0)
        n = -n;

    last_digit = n % 10;

    _putchar(last_digit + '0');  // convert digit to character

    return (last_digit);
}
