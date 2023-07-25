#include "main.h"
#include <stdlib.h>

/**
 * in_flags - checks if a character is in a string
 * @c: the character to check
 * @flags: the string to check in
 * Return: 1 if the character is in the string, 0 otherwise
 */
int in_flags(char c, const char *flags)
{
	int i;

	for (i = 0; i < 5; i++)
		if (c == flags[i])
			return (1);
	return (0);
}


/**
 * get_format - gets the format of the string
 * @s: the string to get the format from
 * Return: a format_t struct
 */
format_t get_format(const char **s)
{
	format_t f = {0, -1, -1, -1, -1};

	f.flags = get_flags(s);
	f.width = get_width(s);
	f.precision = get_precision(s);
	f.length = get_length(s);
	f.specifier = get_specifier(s);

	return (f);
}
