#include "main.h"

/**
* print_char - prints a character
* @args: the character to print
* @format: format struct
* @count: pointer to count of characters printed
*/
void print_char(va_list args, format_t format, void *count)
{
	char c = va_arg(args, int);

	UNUSED(format);

	_putchar(c, count);
}
