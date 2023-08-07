#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read text file, print to stdout
 * @filename: the text file that is read
 * @letters: the number of numbers, should read and print
 * Return: actual number of letters that could be read and printed
 * 0 if filename is NULL or does not fail
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fe;
	ssize_t n;
	ssize_t t;

	fe = open(filename, O_RDONLY);
	if (fe == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fe, buf, letters);
	n = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fe);
	return (n);
}
