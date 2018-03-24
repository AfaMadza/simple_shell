#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
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
	int i = 0, len;
	char *new_line = "\n";

	(void)args;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, new_line, 1);
		i++;
	}
	return (1);
}
int ss_ctrlc(char *args, char **env)
{
	(void)args, (void)env;
	char *new_line = "\n($)";

	write(STDOUT_FILENO, new_line, 5);
	return (1);
}
