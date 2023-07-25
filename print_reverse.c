#include "main.h"
#include <stdio.h>

/**
 * print_reverse - prints a string in reverse
 * @args: the string to print
 * @format: format struct
 * @count: pointer to count of characters printed
 * Return: void
*/
void print_reverse(va_list args, format_t format, void *count)
{
	char *str = va_arg(args, char *);
	int i = 0;

	UNUSED(format);

	if (str == NULL)
		return;

	while (str[i])
		i++;
	while (i--)
		_putchar(str[i], count);
}
