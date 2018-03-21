#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"
/**
 * shell_loop - reads, parses and executes arguments.
 * @env: environment
 * Return: void
 */
void shell_loop(char **env)
{
	char *buf;
	char **argv;
	int status;
	char *dollar_prompt = "$ ";

	do {
		write(STDOUT_FILENO, dollar_prompt, 2);
		buf = read_line();
		argv = parse_argv(buf);
		status = args_execute(argv, env);

		free(buf);
		free(argv);
	} while (status);
}
