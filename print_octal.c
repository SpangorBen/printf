#include "main.h"
#include <stdlib.h>

/**
 * print_octal_helper - prints the octal representation of a number
 * @number: the number to print
 * @count: pointer to count of characters printed
 */
void print_octal_helper(unsigned int number, void *count)
{
	if (number > 7)
		print_octal_helper(number / 8, count);
	_putchar((number % 8) + '0', count);
}

/**
* print_octal - prints the octal representation of a number
* @args: va_list of arguments
* @format: format struct
* @count: pointer to count of characters printed
*/
void print_octal(va_list args, format_t format, void *count)
{
	unsigned int number = va_arg(args, unsigned int);

	UNUSED(format);

	print_octal_helper(number, count);
}
