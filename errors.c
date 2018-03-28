#include "simple_shell.h"
/**
 * no_args - error when req'd arg(s) are not given
 * @argv: argument array passed from main.
 * Return: -1
 */
int no_args(char **argv)
{
	char *no_args = "No arguments given.";

	perror(argv[0]);
	write(STDERR_FILENO, no_args, 20);
	return (-1);
}

/**
 * fork_error - error when fork fails
 * @argv: argument array passed from main.
 * Return: void
 */
void fork_error(char **argv)
{
	perror(argv[0]);
	exit(EXIT_FAILURE);
}

/**
 * execve_error - error when execve fails
 * @argv: argument array passed from main.
 * Return: void
 */
void execve_error(char **argv)
{
	perror(argv[0]);
	exit(EXIT_FAILURE);
}

/**
 * null_arg_w_free - error when malloc in arg_to_path fails
 * @converted_arg: path + arg ret'd by arg_to_path
 * @argv: argument array passed from main.
 * @s: pointer to argument string within shell.
 * @err_cnt: count of error from launch_prog.c
 * Return: 0
 */
int null_arg_w_free(char *converted_arg, char **argv, char *s, int err_cnt)
{
	char *cmd_not_found = ": command not found\n";
	int i = 0;
	char *delim = ": ", *nf = ": not found\n";
	char *j, *nsfd = ": No such file or directory\n";

	if (isatty(STDIN_FILENO) == 1)
	{
		if (s[i] == ' ')
		{
			while (s[i] == ' ')
				i++;
		}
		i = 0;
		if (s[0] == '.' && s[1] == '/')
		{
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, delim, 2);
			write(STDERR_FILENO, s, _strlen(s));
			write(STDERR_FILENO, nsfd, 28);
		}
		else
		{
			write(STDERR_FILENO, s, _strlen(s));
			write(STDERR_FILENO, cmd_not_found, 20);
		}
	}
	else if (isatty(STDIN_FILENO) == 0)
	{
		j = _itoa(err_cnt);
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, delim, 2);
		write(STDERR_FILENO, j, _strlen(j));
		write(STDERR_FILENO, delim, 2);
		write(STDERR_FILENO, s, _strlen(s));
		write(STDERR_FILENO, nf, 12);
		free(j);
	}
	free(converted_arg);
	return (0);
}

/**
 * execve_error_w_free - error when execve fails that frees memory
 * @converted_arg: path + arg ret'd by arg_to_path
 * @argv: argument list from main.
 */
void execve_error_w_free(char *converted_arg, char **argv)
{
	perror(argv[0]);
	free(converted_arg);
	exit(EXIT_FAILURE);
}
