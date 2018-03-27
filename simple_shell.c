#include "simple_shell.h"

/**
 * main - main function that starts shell loop
 * @argc: number of arguments.
 * @argv: null terminated string of arguments.
 * @env: environmental variable.
 * Return: pointer to first element of array.
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;

	shell_loop(argv, env);

	return (EXIT_SUCCESS);
}
