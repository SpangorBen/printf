#include "main.h"
#include <stdlib.h>

/**
 * print_binary_helper - prints the binary representation of a number
 * @number: the number to print
 * @count: pointer to count of characters printed
 */
void print_binary_helper(unsigned int number, void *count)
{
	if (number > 1)
		print_binary_helper(number / 2, count);
	_putchar((number % 2) + '0', count);
}

/**
* print_binary - prints the binary representation of a number
* @args: the number to print
* @format: format struct
* @count: pointer to count of characters printed
*/
void print_binary(va_list args, format_t format, void *count)
{
	unsigned int number = va_arg(args, unsigned int);

	UNUSED(format);

	print_binary_helper(number, count);
}
