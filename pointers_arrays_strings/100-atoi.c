#include "main.h"

/**
 * _atoi - convert a string to an integer.
 * @s: pointer to the string.
 *
 * Return: integer representation of the string.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;
	int started = 0;

	while (*s)
	{
		if (*s == '-')
			sign = -sign;
		else if (*s == '+')
			;
		else if (*s >= '0' && *s <= '9')
		{
			started = 1;
			num = num * 10 + (*s - '0');
		}
		else if (started)
			break;
		s++;
	}

	if (!started)
		return (0);

	if (sign < 0 && num > 2147483648U)
		return (0); /* overflow safe-guard, optional */

	if (sign < 0 && num == 2147483648U)
		return (-2147483648);

	return ((int)(sign * (int)num));
}
