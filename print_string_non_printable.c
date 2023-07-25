#include "main.h"

/**
 * print_string_non_printable - prints a string
 * @args: the string to print
 * @format: format struct
 * @count: pointer to count of characters printed
 * Return: void
 */
void print_string_non_printable(va_list args, format_t format, void *count)
{
	char *str = va_arg(args, char *);
	int i;

	UNUSED(format);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_puts("\\x0", count);
			print_hex_helper(str[i], HEXADECIMAL_BASE_UPPER, count);
		}
		else
			_putchar(str[i], count);
	}
}
