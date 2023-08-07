#include "main.h"

/**
 * append_text_to_file - append a text at the end of file
 * @filename : pointer to the name of file
 * @text_content : NULL terminated string to add at the end of file
 *
 * Return: If filename is NULL or function fails - -1.
 *  If the file does not exist or user lacks permissions to
 *  write file - -1.
 * Else - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, n, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	n = write(p, text_content, len);

	if (p == -1 || n == -1)
		return (-1);
	close(p);

	return (1);
}
