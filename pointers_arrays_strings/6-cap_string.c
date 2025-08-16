#include "main.h"

/**
 * cap_string - Capitalizes all words of a string
 * @str: The string to modify
 *
 * Return: A pointer to the modified string
 */
char *cap_string(char *str)
{
	int i = 0, j;

	/* Characters that separate words */
	char separators[] = " \t\n,;.!?\"(){}";

	/* Capitalize first character if it's a lowercase letter */
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] = str[0] - ('a' - 'A');
	}

	/* Loop through the string */
	while (str[i] != '\0')
	{
		/* Check if current character is a separator */
		for (j = 0; separators[j] != '\0'; j++)
		{
			if (str[i] == separators[j])
			{
				/* Capitalize next character if it's a lowercase letter */
				if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				{
					str[i + 1] = str[i + 1] - ('a' - 'A');
				}
				break;
			}
		}
		i++;
	}

	return (str);
}
