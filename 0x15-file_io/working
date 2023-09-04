#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void error_file(int file_from, int file_to);
void copy_files(int file_from, int file_to);
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
		dprintf(STDERR_FILENO, "Usage:%s file_from file_to\n", argv[0]);
		exit(1);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	error_file(file_from, file_to);

	copy_files(file_from, file_to);
	close_files(file_from, file_to);

	return (0);
}

/**
 * error_file- Check whether files can be opened
 * @file_from: File descriptor for the source file
 * @file_to: File descriptor for the destination file
 * Return: Does not return
 */

void error_file(int file_from, int file_to)
{
	if (file_from == -1)
	{
	perror("Error reading from file");
		exit(2);
	}
	if (file_to == -1)
	{
		perror("Error writing to file");
		exit(3);
	}
}

/**
 * copy_files - Copy data from source file to destination file
 * @file_from: File descriptor for the source file
 * @file_to: File descriptor for the destination file
 * Return: Does not return
 */

void copy_files(int file_from, int file_to)

{
	ssize_t nchars, nwr;
	char buf[1024];

	while ((nchars = read(file_from, buf, sizeof(buf))) > 0)
	{
		nwr = write(file_to, buf, nchars);
		if (nwr == -1)
		{
			perror("Error writing to file");
			exit(4);
		}
	}
	if (nchars == -1)
	{
		perror("Error reading from file");
		exit(5);
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
		perror("Error closing source file");
		exit(6);
	}

	err_close = close(file_to);
	if (err_close == -1)
	{
		perror("Error closing destination file");
		exit(7);
	}
}

