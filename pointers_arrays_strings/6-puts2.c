#include "main.h"

/**
 * puts2 - yazının hər ikinci simvolunu çap edir (0-dan başlayaraq)
 * @str: çap ediləcək yazı
 */
void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0') /* yazının sonuna qədər get */
	{
		_putchar(str[i]); /* hər ikinci simvolu çap et */
		i = i + 2; /* 2 addım irəli get */
	}
	_putchar('\n'); /* sonda yeni sətrə keç */
}
