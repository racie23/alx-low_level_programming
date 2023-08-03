#include "main.h"

/**
 * clear_bit - set value of given bit to 0
 * @a: address to the number to change
 * @index: index of bit to clear
 *
 * Return: 1 if it worked,  -1 if an error occurred
 */
int clear_bit(unsigned long int *a, unsigned int index)
{
	if (index > 63)
		return (-1);

	*a = (~(1UL << index) & *a);
	return (1);
}
