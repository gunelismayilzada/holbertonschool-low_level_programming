#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

int main(int argc, char *argv[])
{
    int a, b, result;
    int (*op_func)(int, int);

    if (argc != 4) /* Check number of arguments */
    {
        printf("Error\n");
        return 98;
    }

    a = atoi(argv[1]);
    b = atoi(argv[3]);
    op_func = get_op_func(argv[2]); /* Get function pointer based on operator */

    if (!op_func) /* Check for invalid operator */
    {
        printf("Error\n");
        return 99;
    }

    if (((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)) /* Check divide/modulo by zero */
    {
        printf("Error\n");
        return 100;
    }

    result = op_func(a, b);
    printf("%d\n", result);

    return 0;
}
