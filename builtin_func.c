#include "simple_shell.h"
/**
 * ss_exit - exits the shell.
 * @args: array of arguments passed in.
 * @env: environment
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
 * @args: array of arguments passed in.
 * @env: environment
 * Return: always 1.
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

/**
 * ss_ctrlc - handles ctrl-c to prevent program escape
 * @signum: signal number
 * Return: void
 */
void ss_ctrlc(int signum)
{
	char *new_line = "\n($)";

	(void)signum;

	write(STDOUT_FILENO, new_line, 5);
}
