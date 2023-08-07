#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * error_file - check whether files can be opened
 * @file_from : ...
 * @file_to : ...
 * @argv: the argument vector
 * Return: does not return
 */
void error_file(int file_from, int file_to, char *agrv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not read from file %s\n", agrv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not write to %s\n", agrv[2]);
		exit(99);
	}
}

/**
 * main - Check the code 
 * @argc: no. of arguments
 * @agrv: the argument vector
 * Return: Always 0 (success)
 */
int main(int argc, char *agrv[])
{
	int file_from, file_to, err_close;
	ssize_t nchars, nwr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(agrv[1], O_RDONLY);
	file_to = open(agrv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, agrv);

	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(file_from, buf, 1024);
		if (nchars == -1)
			error_file(-1, 0, agrv);
		nwr = write(file_to, buf, nchars);
		if (nwr == -1)
			error_file(0, -1, agrv);
	}

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not close fd %d\n", file_from);
		exit(100);
	}

	return (0);
}
