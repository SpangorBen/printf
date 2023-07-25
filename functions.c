#include "main.h"

/**
 * _putchar - print one char
 * @c: the character
 * Return: always 1
*/

int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * _putstr - print string
 * @str: the string
 * Return: length of the string printed
*/

int	_putstr(char *str)
{
	int	i = 0;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * _count - count number
 * @nbr: number
 * Return: length of number
*/

static	size_t	_count(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

/**
 * _putnbr - print number
 * @n: number
 * Return: length of the number printed
*/

int	_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		_putnbr(nbr / 10);
		_putnbr(nbr % 10);
	}
	else
	{
		_putchar(nbr + '0');
	}
	return (_count(n));
}
