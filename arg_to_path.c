#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "simple_shell.h"
/**
 * arg_to_path - searches for a passed argument in PATH.
 * @argv: array of arguments.
 * @env: environmental variable.
 * Return: 0 or -1 for success or failure.
 */
char *arg_to_path(char **argv, char **env)
{
	char *path, **parsed_path, *new_buf;
	int len_path, len_arg, len_buf, i = 0;
	struct stat st;

	if (env == NULL)
		return (NULL);
	path = _getenv("PATH", env);
	parsed_path = parse_argv(path);

	while (parsed_path[i])
	{
		len_path = _strlen(parsed_path[i]);
		len_arg = _strlen(argv[0]);
		len_buf = len_path + len_arg + 2;
		new_buf = malloc(sizeof(char) * len_buf);
		if (new_buf == NULL)
			return (NULL);
		_strncpy(new_buf, parsed_path[i], len_path);
		new_buf[len_path] = '/';
		_strncpy((new_buf + len_path + 1), argv[0], len_arg);
		if (stat(new_buf, &st) == 0)
		{
			break;
		}
		i++;
	}
	return (new_buf);
}
