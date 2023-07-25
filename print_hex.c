#include "main.h"
#include <stdlib.h>

/**
 * print_hex_helper - prints the hex representation of a number
 * @number: the number to print
 * @base: the base to use
 * @count: pointer to count of characters printed
 */
void print_hex_helper(unsigned long int number, char *base, void *count)
{
	if (number > 15)
		print_hex_helper(number / 16, base, count);
	_putchar(base[number % 16], count);
}

/**
 * print_hex - prints the hex representation of a number
 * @args: va_list of arguments
 * @format: format struct
 * @count: pointer to count of characters printed
 */
void print_hex(va_list args, format_t format, void *count)
{
	unsigned int number = va_arg(args, unsigned int);
	int upper = in_flags('X', format.flags) ? 1 : 0;
	char *base = upper ? HEXADECIMAL_BASE_UPPER : HEXADECIMAL_BASE_LOWER;
	char symbol = in_flags('#', format.flags) && number != 0 ? '#' : 0;

	if (symbol)
		_puts(upper ? "0X" : "0x", count);
	print_hex_helper(number, base, count);
}
