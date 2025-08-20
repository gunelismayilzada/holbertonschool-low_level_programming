#include "main.h"

/**
 * _puts_recursion - Rekursiya ilə stringi çap edir
 * @s: Çap ediləcək stringin göstəricisi (pointer)
 */
void _puts_recursion(char *s)
{
    if (*s == '\0')  // 1. Əgər sətrin sonuna çatmışıqsa
    {
        _putchar('\n');  // Yeni sətrə keçirik
        return;          // Daha davam etmirik, dayandırırıq
    }

    _putchar(*s);        // 2. Hazırkı simvolu çap edirik
    _puts_recursion(s + 1); // 3. Növbəti simvol üçün funksiyanı yenidən çağırırıq
}
