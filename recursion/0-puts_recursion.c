#include "main.h"

/**
 * _puts_recursion - Rekursiya ilə stringi çap edir
 * @s: Çap ediləcək sətrə işarə edən göstərici
 */
void _puts_recursion(char *s)
{
    if (*s == '\0')  /* Sətrin sonuna çatmışıqsa */
    {
        _putchar('\n');  /* Yeni sətrə keç */
        return;
    }
    _putchar(*s);  /* Hazırkı simvolu çap et */
    _puts_recursion(s + 1);  /* Növbəti simvol üçün funksiyanı yenidən çağır */
}
