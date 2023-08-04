#include "main.h"

/**
 * get_endianness - check whether a machine is big endian or little
 * Return:0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int a = 1;
	char *n = (char *) &a;

	return (*n);

}
