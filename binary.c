#include "main.h"

/**
 * _binary - convert to binary
 * @nbr: number
 * Return: the binary result
*/

int _binary(int nbr)
{
	if (nbr == 0)
		return (0);
	else
		return (nbr % 2 + 10 * _binary(nbr / 2));
}
