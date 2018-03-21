#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * _getenv - searches environment list for name.
 * @name: pointer to name.
 * @env: pointer to array of strings called environment.
 * Return: pointer to corresponding value provided for name.
 */
char *_getenv(const char *name, char **env)
{
	int offset;
	char *path;

	path = env_find(name, &offset, env);

	return (path);
}
/**
 * env_find - searches environment list for name.
 *@name: pointer to name.
 *@offset: offset of name/value combination in environmental array.
 *@env: pointer to array of strings called environment.
 * Return: pointer to corresponding value provided for name.
 */
char *env_find(const char *name, int *offset, char **env)
{
	size_t len;
	const char *name_p;
	char **env_p, *path_p;

	if (name == NULL || env == NULL)
		return (NULL);
	for (name_p = name; *name_p && *name_p != '='; ++name_p)
		continue;
	len = name_p - name;
	for (env_p = env; (path_p = *env_p) != NULL; ++env_p)
	{
		if (_strncmp(path_p, name, len) == 0 && path_p[len] == '=')
		{
			*offset = env_p - env;
			return (path_p + len + 1);
		}
	}
	*offset = env_p - env;
	return (NULL);
}
/**
 * _strncmp - compares two strings
 *
 * @s1: pointer to first string
 * @s2: pointer to pointer to second string
 * @n: first n letters to compare.
 * Return: 0 or 1 for success or failure.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
		if (*s1++ != *s2++)
		{
			return (*(unsigned char *)(s1 - 1) -
				*(unsigned char *)(s2 - 1));
		}
	return (0);
}
