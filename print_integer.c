#include "main.h"
#include <stdlib.h>

/**
 * print_integer_helper - prints an integer
 * @number: number to print
 * @count: pointer to count of characters printed
 */
void print_integer_helper(int number, void *count)
{
	unsigned int n = number;

	if (number < 0)
	{
		_putchar('-', count);
		n = -number;
	}
	if (n < 10)
		_putchar(n + '0', count);
	else
	{
		print_integer_helper(n / 10, count);
		print_integer_helper(n % 10, count);
	}
}

/**
 * print_integer - prints an integer
 * @args: va_list of arguments
 * @format: format struct
 * @count: pointer to count of characters printed
 */
void print_integer(va_list args, format_t format, void *count)
{
	int n = va_arg(args, int);

	UNUSED(format);

	print_integer_helper(n, count);
}
