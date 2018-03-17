#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"
/**
 * parse_argv - splits a string and returns an array for each argument.
 *@line: pointer to string that needs to be split.
 * Return: pointer to first element of array.
 */
int launch_prog(char **args)
{
	pid_t pids[1];
	int i, status;
	int n = 1;
	char *no_args = "No arguments given.";

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
			if (execvp(args[0], args) == -1)
			{
				perror("Exec Error");
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			do
			{
				waitpid(pids[i], &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	return (1);
}

/**
 * main - tests launch_prog.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	printf("Before launch_prog\n");
	launch_prog(argv);
	return (0);
}
