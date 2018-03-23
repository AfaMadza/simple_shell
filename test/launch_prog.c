#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"
/**
 * launch_prog - takes parsed input and launches a process.
 * @args: double pointer to array of arguments.
 * @env: environment
 * Return: 1 for success. Error otherwise.
 */
int launch_prog(char **args, char **env)
{
	pid_t pids[1];
	int i, status;
	int n = 1;
	char *no_args = "No arguments given.";
	char *converted_arg = NULL;
	int j = 0;

	if (args == NULL)
	{
		write(STDERR_FILENO, no_args, 20);
		return (0);
	}
	for (i = 0; i < n; ++i)
	{
		pids[i] = fork();
		if (pids[i] < 0)
		{
			perror("Fork Error");
			exit(EXIT_FAILURE);
		}
		else if (pids[i] == 0)
		{
			if (access(args[0], F_OK) == 0)
			{
				if (execve(args[0], args, NULL) == -1)
				{
					perror("Exec Error");
					exit(EXIT_FAILURE);
				}
				exit(EXIT_SUCCESS);
			}
			else
			{
				converted_arg = arg_to_path(args, env);
				if (execve(converted_arg, args, env) == -1)
				{
					perror("Exec Error");
					while(args[j])
					{
						free(args[j]);
						j++;
					}
					free(args);
					free(converted_arg);
					return (-1);
				}
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			do {
				waitpid(pids[i], &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	free(converted_arg);
	return (1);
}
