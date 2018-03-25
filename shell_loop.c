#include "simple_shell.h"
/**
 * shell_loop - reads, parses and executes arguments.
 * @env: environment
 * Return: void
 */
void shell_loop(char **env)
{
	struct line myline;
	char **argv;
	int status;
	char *dollar_prompt = "($) ";

	do {
		signal(SIGINT, ss_ctrlc);

		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, dollar_prompt, 4);

		myline = read_line();
		if (myline.char_count == 1)
		{
			free(myline.buf);
			status = 1;
			continue;
		}
		argv = parse_argv(myline.buf);
		if (argv == NULL)
		{
			free(myline.buf);
			status = 1;
			continue;
		}
		status = args_execute(argv, env);
		free(myline.buf);
		free(argv);
	} while (status);
}
