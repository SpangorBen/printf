#include <stdlib.h>
#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * @str: string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = _strlen(str);

	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';
	return (dup);
}

/**
 * reverse_string - reverses a string
 * @str: string to reverse
 * Return: pointer to the reversed string
 */
char *reverse_string(char *str)
{
	int start = 0, end = _strlen(str) - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}

	return (str);
}

/**
 * _itoa - converts an integer to a string
 * @value: integer to convert
 * @base: base to convert to
 * Return: pointer to the converted string
 */
char *_itoa(ssize_t value, char *base)
{
	ssize_t quotient = ABS(value), i = 0;
	int base_len = _strlen(base);
	char *result = malloc(get_number_length(value) + 1);

	if (base_len < 2 || base_len > 16 || result == NULL)
		return (NULL);

	do {
		result[i++] = base[quotient % base_len];
		quotient /= base_len;
	} while (quotient);

	if (value < 0 && base_len == 10)
		result[i++] = '-';

	result[i] = '\0';
	return (reverse_string(result));
}

/**
 * _utoa - converts an unsigned integer to a string
 * @value: integer to convert
 * @base: base to convert to
 * Return: pointer to the converted string
 */
char *_utoa(size_t value, char *base)
{
	ssize_t quotient = ABS(value), i = 0;
	int base_len = _strlen(base);
	char *result = malloc(get_number_length(value) + 1);

	if (result == NULL)
		return (NULL);

	if (base_len < 2 || base_len > 16)
		return (NULL);

	do {
		result[i++] = base[quotient % base_len];
		quotient /= base_len;
	} while (quotient);

	result[i] = '\0';
	return (reverse_string(result));
}
