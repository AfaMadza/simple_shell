#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n;,:"
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

	if (line == NULL)
		return (NULL);
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
				free(token);
				free(tokens);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	free(token);
	tokens[position] = NULL;
	return (tokens);
}
