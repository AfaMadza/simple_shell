#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * print_path_dirs - prints directories in PATH.
 *@env: pointer to array of strings called environment.
 * Return: 0 or -1 for success or failure.
 */
int print_path_dirs(char **env)
{
	char *path, **tokens;
	int i = 0, len;
	char *new_line = "\n";

	if (env == NULL)
		return (-1);
	path = _getenv("PATH", env);
	tokens = parse_argv(path);

	while (tokens[i])
	{
		len = _strlen(tokens[i]);
		write(STDOUT_FILENO, tokens[i], len);
		write(STDOUT_FILENO, new_line, 1);
		i++;
	}
	free(tokens);
	return (0);
}
/**
 * _strlen - returns length of a string
 *
 * @s: pointer to string whose length will be returned
 * Return: None
 */
int _strlen(char *s)
{
	int length = 0;

	for (; *s != '\0'; s++)
	{
		length++;
	}
	return (length);
}
