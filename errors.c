#include "simple_shell.h"
/**
 * no_args - error when req'd arg(s) are not given
 * Return: -1
 */
int no_args(void)
{
	char *no_args = "No arguments given.";

	perror("./hsh");
	write(STDERR_FILENO, no_args, 20);
	return (-1);
}

/**
 * fork_error - error when fork fails
 * Return: void
 */
void fork_error(void)
{
	perror("./hsh");
	exit(EXIT_FAILURE);
}

/**
 * execve_error - error when execve fails
 * Return: void
 */
void execve_error(void)
{
	perror("./hsh");
	exit(EXIT_FAILURE);
}

/**
 * null_arg_w_free - error when malloc in arg_to_path fails
 * @converted_arg: path + arg ret'd by arg_to_path
 * Return: 0
 */
int null_arg_w_free(char *converted_arg)
{
	perror("./hsh");
	free(converted_arg);
	return (0);
}

/**
 * execve_error_w_free - error when execve fails that frees memory
 * @converted_arg: path + arg ret'd by arg_to_path
 */
void execve_error_w_free(char *converted_arg)
{
	perror("./hsh");
	free(converted_arg);
	exit(EXIT_FAILURE);
}
