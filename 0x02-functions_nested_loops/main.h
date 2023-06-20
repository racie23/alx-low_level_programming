#include "stdio.h"

/**
 * main - Entry point of the program
 *
 * Description: This function prints the string "_putchar"
 *              followed by a new line using putchar.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	char str[] = "_putchar\n";

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}

	return (0);
}
