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
	int status;
	char *converted_arg = NULL;

	if (args == NULL ||  *args == NULL)
		return (no_args());

	pids[0] = fork();
	if (pids[0] < 0)
		fork_error();
	else if (pids[0] == 0)
	{
		if (access(args[0], F_OK) == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				execve_error();
			exit(EXIT_SUCCESS);
		}
		else
		{
			converted_arg = arg_to_path(args, env);
			if (converted_arg == NULL)
				return (null_arg_w_free(converted_arg));
			if (execve(converted_arg, args, NULL) == -1)
				execve_error_w_free(converted_arg);
		}
		exit(EXIT_SUCCESS);
	}
	else
	{
		do {
			waitpid(pids[0], &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	free(converted_arg);
	return (1);
}
