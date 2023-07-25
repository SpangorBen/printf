#include "main.h"

/**
 * get_number_length - gets the length of a number
 * @n: the number to get the length of
 * Return: the length of the number
 */
int get_number_length(int n)
{
	int i = 0;

	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/**
 * justifier - justifies a number
 * @n: the number to justify
 * @format: the format of the number
 * @count: pointer to count of characters printed
 */
void justifier(char *n, format_t format, void *count)
{
	int number_length = _strlen(n);
	char c = in_flags('0', format.flags) &&
		!in_flags('-', format.flags) ? '0' : ' ';

	for (; format.width - number_length > 0; format.width--)
		_putchar(c, count);
}
