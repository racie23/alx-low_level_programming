#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void error_file(int file_from, int file_to, char *argv[]);
void copy_files(int file_from, int file_to, char *argv[]);
void close_files(int file_from, int file_to);

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * Return: Always 0 (success)
 */

int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	error_file(file_from, file_to, argv);

	copy_files(file_from, file_to, argv);
	close_files(file_from, file_to);

	return (0);
}

/**
 * error_file- Check whether files can be opened
 * @file_from: File descriptor for the source file
 * @file_to: File descriptor for the destination file
 * @argv: The argument vector
 * Return: Does not return
 */

void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * copy_files - Copy data from source file to destination file
 * @file_from: File descriptor for the source file
 * @file_to: File descriptor for the destination file
 * @argv: The argument vector
 * Return: Does not return
 */

void copy_files(int file_from, int file_to, char *argv[])

{
	ssize_t nchars, nwr;
	char buf[1024];

	while ((nchars = read(file_from, buf, sizeof(buf))) > 0)
	{
		nwr = write(file_to, buf, nchars);
		if (nwr == -1)
		{
			error_file(0, -1, argv);
		}
	}
	if (nchars == -1)
	{
		error_file(-1, 0, argv);
	}
}

/**
 * close_files - Close file descriptors
 * @file_from: File descriptor for the source file
 * @file_to: File descriptor for the destination file
 * Return: Does not return
 */

void close_files(int file_from, int file_to)
{
	int err_close;

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not close fd %d\n", file_from);
		exit(100);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not close fd %d\n", file_to);
		exit(100);
	}
}

