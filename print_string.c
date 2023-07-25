#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to get length of
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i]; i++)
		;

	return (i);
}

/**
 * print_string - prints a string
 * @args: va_list of arguments
 * @format: format struct
 * @count: pointer to count of characters printed
 * Return: void
 */
void print_string(va_list args, format_t format, void *count)
{
	char *str = va_arg(args, char *);

	UNUSED(format);

	if (str == NULL)
		str = "(null)";

	*(int *)count += (int) write(STDOUT_FILENO, str, _strlen(str));
}
