#include "main.h"

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @n : the string containing the binary number
 *
 * Return: the number converted
 */
unsigned int binary_to_uint(const char *n)
{
	int a;
	unsigned int dec_val = 0;

	if (!n)
		return (0);

	for (a = 0; n[a]; a++)
	{
		if (n[a] < '0' || n[a] > '1')
			return (0);
		dec_val = 2 * dec_val + (n[a] - '0');
	}

	return (dec_val); }
