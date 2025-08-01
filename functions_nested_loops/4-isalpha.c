/**
 * _isalpha - checks for alphabetic character
 * @c: The character to check
 *
 * Return: 1 if letter (lowercase or uppercase), 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
