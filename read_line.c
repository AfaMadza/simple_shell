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
struct line read_line(void)
{
	struct line my_line;
	size_t buf_size = 0;

	my_line.buf = NULL;

	my_line.char_count = getline(&my_line.buf, &buf_size, stdin);

	if (my_line.char_count == -1)
	{
		free(my_line.buf);
		exit(EXIT_FAILURE);
	}
	return (my_line);
}
