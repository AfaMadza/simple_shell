#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * args_execute - launches processes.
 * @args: double pointer to argv.
 * @env: environmental variable.
 * Return: completed process.
 */
int args_execute(char **args, char **env)
{
	if (args[0] == NULL)
		return (1);
	return (launch_prog(args, env));
}
