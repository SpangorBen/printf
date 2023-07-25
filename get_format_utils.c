#include "main.h"
#include <stdlib.h>

/**
 * get_flags - gets the flag from the string
 * @s: the string to get the flag from
 * Return: a flag
 */
char *get_flags(const char **s)
{
	char flags[] = {'-', '+', ' ', '#', '0'};
	int i, j = 0;
	char *flag = malloc(sizeof(*flag) * 6);

	if (flag == NULL)
		return (NULL);

	for (i = 0; i < 5; i++)
		if (in_flags(*(*s), flags))
		{
			flag[j++] = *(*s);
			(*s)++;
		}
	flag[j] = '\0';
	return (flag);
}

/**
 * get_width - gets the width from the string
 * @s: the string to get the width from
 * Return: a width
 */
int get_width(const char **s)
{
	char p[1024];
	int i = 0;

	for (; *(*s) >= '0' && *(*s) <= '9'; (*s)++, i++)
		p[i] = *(*s);
	p[i] = '\0';

	if (i == 0)
		return (-1);

	return (_atoi(p));
}

/**
 * get_precision - gets the precision from the string
 * @s: the string to get the precision from
 * Return: a precision
 */
int get_precision(const char **s)
{
	char p[1024] = "-1";
	int i = 0;
	*(*s) == '.' ? (*s)++ : 0;
	for (; *(*s) >= '0' && *(*s) <= '9'; (*s)++, i++)
		p[i] = *(*s);
	if (i != 0)
		p[i] = '\0';
	return (_atoi(p));
}

/**
 * get_length - gets the length format of the string
 * @s: the string to get the length from
 * Return: a length
 */
int get_length(const char **s)
{
	char length[] = {'h', 'l', 'L'};
	int i;
	char l = -1;

	for (i = 0; i < 3; i++)
		if (*(*s) == length[i])
		{
			l = length[i];
			(*s)++;
			break;
		}
	return (l);
}

/**
 * get_specifier - gets the specifier of the string
 * @s: the string to get the specifier from
 * Return: a specifier
 */
char get_specifier(const char **s)
{
	char *specifiers = "cs%diboxXurRpS";
	int i;
	char specifier = -1;

	for (i = 0; i < 14; i++)
		if (*(*s) == specifiers[i])
		{
			specifier = specifiers[i];
			break;
		}
	return (specifier);
}
