#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: the number to process
 *
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
    int last_digit;

    last_digit = n % 10;      // get last digit (could be negative)
    if (last_digit < 0)
        last_digit = -last_digit;  // convert to positive if negative

    _putchar('0' + last_digit);  // print the digit character
    return (last_digit);
}
