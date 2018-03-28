#include "simple_shell.h"
/**
 * launch_prog - takes parsed input and launches a process.
 * @args: double pointer to array of arguments.
 * @env: environment
 * @m_argv: argument array from main.
 * Return: 1 for success. Error otherwise.
 */
int launch_prog(char **m_argv, char **args, char **env)
{
	pid_t pids[1];
	int status, err_count = 0;
	char *converted_arg = NULL;

	if (args == NULL ||  *args == NULL)
		return (no_args(m_argv));

	pids[0] = fork();
	if (pids[0] < 0)
		fork_error(m_argv);
	else if (pids[0] == 0)
	{
		if (access(args[0], F_OK) == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				execve_error(m_argv);
			exit(EXIT_SUCCESS);
		}
		else
		{
			converted_arg = arg_to_path(args, env);
			if (converted_arg == NULL)
			{
				err_count++;
				return (null_arg_w_free(converted_arg, m_argv,
							args[0], err_count));
			}
			if (execve(converted_arg, args, NULL) == -1)
				execve_error_w_free(converted_arg, m_argv);
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
	return (0);
}
