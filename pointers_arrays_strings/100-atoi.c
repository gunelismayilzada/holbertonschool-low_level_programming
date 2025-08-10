#include "main.h"

/**
 * _atoi - convert a string to an integer.
 * @s: pointer to the string to convert.
 *
 * Return: converted integer, or 0 if none found.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num = 0, started = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign = -sign;
		}
		else if (s[i] == '+')
		{
			/* sign unchanged */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			num = num * 10 + (s[i] - '0');
		}
		else if (started)
		{
			break;
		}
		i++;
	}

	if (!started)
		return (0);

	return (sign * num);
}
