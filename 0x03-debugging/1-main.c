#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: 0 (Success)
 */
int main(void)
{
    int i = 0;  /* Variable declaration and initialization */

    printf("Infinite loop incoming :(\n");  /* Print message indicating the start of the loop */

    while (i < 10)  /* Loop condition: continue while i is less than 10 */
    {
        putchar(i++);  /* Print the current value of i as a character and increment i by 1 */
    }

    printf("Infinite loop avoided! \\o/\n");  /* Print message indicating the loop has finished */

    return (0);  /* Return 0 to indicate successful execution */
}
