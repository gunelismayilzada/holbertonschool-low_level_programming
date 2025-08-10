#include "main.h"
#include <limits.h>

/**
 * _atoi - convert a string to an integer.
 * @s: pointer to the string.
 *
 * Return: integer representation of the string.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0, started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] == '+')
			; /* sign unchanged */
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;

			/* Check for overflow before multiplying and adding */
			if (sign == 1)
			{
				if (num > (INT_MAX - (s[i] - '0')) / 10)
					return (INT_MAX);
			}
			else
			{
				/* INT_MIN = -2147483648, max magnitude is 2147483648 */
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
