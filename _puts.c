#include "main.h"

/**
 * _puts - prints a string
 * @str: string to print
 * @count: pointer to count of characters printed
 */
void _puts(char *str, void *count)
{
	if (str == NULL)
		str = "(null)";
	while (*str)
		_putchar(*str++, count);
}
