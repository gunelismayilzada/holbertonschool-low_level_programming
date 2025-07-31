#include "main.h"

/**
 * more_numbers - prints numbers 0 to 14, 10 times, followed by a new line
 */
void more_numbers(void)
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j <= 14; j++)
		{
			if (j >= 10)
				_putchar((j / 10) + '0');  // tens digit
			_putchar((j % 10) + '0');       // ones digit
		}
		_putchar('\n');  // newline at the end of each line
	}
}
