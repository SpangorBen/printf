#include "main.h"

/**
 * _check_format - check format of printf
 * @args: va_list arg
 * @c: character
 * Return: length of the printed format
*/

int	_check_format(va_list args, char c)
{
	int l = 0;

	switch (c)
	{
	case 'c':
		l += _putchar(va_arg(args, int));
		break;
	case 's':
		l += _putstr(va_arg(args, char *));
		break;
	case '%':
		l += _putchar('%');
		break;
	case 'd':
		l += _putnbr(va_arg(args, int));
		break;
	case 'i':
		l += _putnbr(va_arg(args, int));
		break;
	default:
		break;
	}
	return (l);
}

/**
 * _printf - Build out the printf function
 * @format: string passed with possible format specifiers
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int		i = 0;
	int		len = 0;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			len += _putchar(format[i]);
		else if (format[i] == '%' && format[i + 1] != '\0')
		{
			len += _check_format(args, format[i + 1]);
			i++;
		}
		i++;
	}
	return (len);
}
