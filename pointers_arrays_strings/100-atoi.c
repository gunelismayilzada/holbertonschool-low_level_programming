#include "main.h"
#include <limits.h> /* for INT_MAX, INT_MIN */

/**
 * _atoi - converts a string to an integer safely handling overflow.
 * @s: input string.
 *
 * Return: converted integer or INT_MAX/INT_MIN on overflow.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0, started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] == '+')
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;

			/* Check overflow for positive sign */
			if (sign == 1)
			{
				if (num > (INT_MAX - (s[i] - '0')) / 10)
					return (INT_MAX);
			}
			else
			{
				/* Check overflow for negative sign */
				if (num > ((unsigned)INT_MAX + 1 - (s[i] - '0')) / 10)
					return (INT_MIN);
			}

			num = num * 10 + (s[i] - '0');
		}
		else if (started)
			break;
		i++;
	}

	if (!started)
		return (0);

	return (sign * num);
}
