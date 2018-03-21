#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
#include "simple_shell.h"
/**
 * read_line - uses getline read input from STDIN
 *
 * Return: pointer to buffer.
 */
char *read_line(void)
{
	char *buf = NULL;
	size_t buf_size = 0;
	int char_count;
	char *get_err = "Could not getline.";
	char *new_line = "\n";

	char_count = getline(&buf, &buf_size, stdin);

	if (char_count == -1)
	{
		free(buf);
		write(STDERR_FILENO, get_err, 18);
		write(STDERR_FILENO, new_line, 1);
		exit(EXIT_FAILURE);
	}
	return (buf);
}
