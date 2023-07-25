#include "main.h"

/**
 * print_percent - prints a percent sign
 * @args: va_list of arguments (unused)
 * @format: format struct
 * @count: pointer to count of characters printed
*/
void print_percent(va_list args,
				   format_t format, void *count)
{
	/* char *percent = "%"; */

	UNUSED(args);
	UNUSED(format);

	_putchar('%', count);
}
