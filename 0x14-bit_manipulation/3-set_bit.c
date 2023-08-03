#include "main.h"

/**
 * set_bit - set a bit at a given index
 * @n: the address to the number to change
 * @index: the index of the bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	{
		if (index > 63)
			return (-1);

		*n = ((1UL << index) | *n);
	}

	return (1);
}
