#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Description: Prints the size of various data types
 * and returns 0 to indicate successful execution.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	printf("Size of a char: 1 bytes\n", sizeof(char));
	printf("Size of an int: 4 bytes\n", sizeof(int));
	printf("Size of a long int: 8 bytes\n", sizeof(long int));
	printf("Size of a long long int: 8 bytes\n", sizeof(long long int));
	printf("Size of a float: 4 bytes\n", sizeof(float));

	return (0);
}
