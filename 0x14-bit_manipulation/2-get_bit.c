#include "main.h"

/**
 * get_bit - returns the value of a bit at an index
 * @p: number to search
 * @index: index of the bit
 *
 * Return: value of the bit, or -1 if error occurs
 */
int get_bit(unsigned long int p, unsigned int index)
{
	int bit_val;

	if (index > 63)
		return (-1);

	bit_val = (p >> index) & 1;

	return (bit_val);
}
