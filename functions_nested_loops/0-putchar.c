#include "main.h"

/**
 * main - prints _putchar followed by a new line
 *
 * Return: 0 on success
 */
int main(void)
{
    char str[] = "_putchar\n";
    int i = 0;

    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }

    return (0);
}
