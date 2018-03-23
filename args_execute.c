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
	int i = 0;
	b_in func_array[] = {
		{"exit", ss_exit},
		{"env", ss_env},
		{NULL, NULL}
	};
	if (args == NULL || *args == NULL)
	{
		perror("No such file or directory");
		return (0);
	}
	else if (args != NULL)
	{
		while (func_array[i].op != NULL)
		{
			if (_strcmp(args[0],func_array[i].op) == 0)
			{
				if (func_array[i].f(*args, env) == 0)
					return(0);
			}
			i++;
		}
		i = 0;
	}
	return(launch_prog(args, env));
}
