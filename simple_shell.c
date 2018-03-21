#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
#define UNUSED(x) (void)(x)

/**
 * parse_argv - splits a string and returns an array for each argument.
 * @argc: number of arguments.
 * @argv: null terminated string of arguments.
 * @env: environmental variable.
 * Return: pointer to first element of array.
 */
int main(int argc, char **argv, char **env)
{
  UNUSED(argc); UNUSED(argv);

	shell_loop(env);

	return (EXIT_SUCCESS);
}