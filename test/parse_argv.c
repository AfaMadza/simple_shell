#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n;,:-"
/**
 * parse_argv - splits a string and returns an array for each argument.
 *@line: pointer to string that needs to be split.
 * Return: pointer to first element of array.
 */
char **parse_argv(char *line)
{
	int buf_size = TOK_BUFSIZE, position = 0;
	char **tokens;
	char *token;
	char *mal_err = "Error allocating memory for tokens.";

	tokens = malloc(buf_size * sizeof(char *));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, mal_err, 36);
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= buf_size)
		{
			buf_size += TOK_BUFSIZE;
			tokens = _realloc(tokens, buf_size * sizeof(char *));
			if (tokens == NULL)
			{
				write(STDERR_FILENO, mal_err, 36);
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
/**
 *_realloc - changes the size of memory block.
 *@ptr: memory block whose size needs to be changed.
 *@size: new size of memory block.
 *Return: pointer to new memory block.
 */
void *_realloc(void *ptr, size_t size)
{
	char *p;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(size);
	if (p == NULL)
		return (NULL);
	_memcpy(p, ptr, size);
	free(ptr);
	return (p);
}
