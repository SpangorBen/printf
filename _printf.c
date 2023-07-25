#include "main.h"
#include <stdlib.h>
#include <ctype.h>

/**
 * is_alpha - checks if a character is alphabetic
 * @c: the character to check
 * Return: 1 if the character is alphabetic, 0 otherwise
 */
int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

static format_specifier format_specifiers[] = {
	{"c", print_char},
	{"s", print_string},
	{"%", print_percent},
	{"d", print_integer},
	{"i", print_integer},
	{"b", print_binary},
	{"o", print_octal},
	{"x", print_hex},
	{"X", print_hex},
	{"u", print_unsigned},
	{"p", print_address},
	{"r", print_reverse},
	{"R", print_rot13},
	{"S", print_string_non_printable},
	{NULL, NULL}
};

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0, i;
	format_t f = {0, -1, -1, -1, -1};
	va_list args;

	/* Note: printf segfaults if format is NULL */
	if (!format)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			f = get_format(&format);
			if (f.flags == NULL)
				return (-1);

			for (i = 0; format_specifiers[i].specifier; ++i)
				if (f.specifier == *format_specifiers[i].specifier)
				{
					format_specifiers[i].function(args, f, &count);
					format++;
					break;
				}
			free(f.flags);
		}
		else
			_putchar(*format++, &count);
	}
	va_end(args);
	return (count);
}
