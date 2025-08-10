#include <stdio.h>

/**
 * print_array - N element array çap edir
 * @a: array-in göstəricisi
 * @n: çap olunacaq element sayı
 */
void print_array(int *a, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d", a[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf("\n");
}
