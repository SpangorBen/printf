#include "main.h"
#include <stdlib.h>

/**
 * print_unsigned_helper - prints an unsigned integer
 * @number: the unsigned integer to print
 * @count: pointer to count of characters printed
 */
void print_unsigned_helper(unsigned int number, void *count)
{
	if (number > 9)
		print_unsigned_helper(number / 10, count);
	_putchar((number % 10) + '0', count);
}

/**
 * print_unsigned - prints an unsigned integer
 * @args: va_list of arguments
 * @format: format struct
 * @count: pointer to count of characters printed
*/
void print_unsigned(va_list args, format_t format, void *count)
{
	unsigned int number = va_arg(args, unsigned int);

	UNUSED(format);

	print_unsigned_helper(number, count);
}
