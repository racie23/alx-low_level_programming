#include "main.h"

/**
 * set_bit - set a bit at a given index
 * @a: the address to the number to change 
 * @index: the index of the bit to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *a, unsigned int index)
{
	if (index > 63)
		return (-1);

	{
		if (index > 63)
			return (-1);

		*a = ((1UL << index) | *a);
	}

	return (1);
}
