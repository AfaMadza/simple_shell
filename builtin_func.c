#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * exit - exits the shell.
 * @argv: array of arguments passed in.
 * Return: always 0.
 */
int ss_exit(char *args, char **env)
{
	(void)env;
	if (args == NULL)
		return (0);
	return (0);
}
/**
 * ss_env - prints the environment.
 * @argv: array of arguments passed in.
 * Return: always 0.
 */
int ss_env(char *args, char **env)
{
	(void)args;
	int i = 0, len;
	char *new_line = "\n";

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, new_line, 1);
		i++;
	}
	return (1);
}
