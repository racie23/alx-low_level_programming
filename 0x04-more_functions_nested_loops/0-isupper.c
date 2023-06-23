#include "main.h"

/**
 * _isupper - Check if a letter is uppercase
 * @x: The character to be checked
 *
 * Return: 1 if @x is uppercase, 0 otherwise
 */
int _isupper(int x)
{
	if (x >= 65 && x <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
