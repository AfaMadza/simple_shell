#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("PATH : %s\n", _getenv("PATH", env));
	printf("HOME : %s\n", _getenv("HOME", env));
	printf("ROOT : %s\n", _getenv("ROOT", env));

	return(0);
}
/**
 * _getenv - searches environment list for name.
 *@name: pointer to name.
 * Return: pointer to corresponding value provided for name.
 */
char *_getenv(const char *name, char **env)
{
	int offset;
	char *result;

	result = env_find(name, &offset, env);

	return (result);
}
/**
 * env_find - searches environment list for name.
 *@name: pointer to name.
 *@offset: offset of name/value combination in environmental array.
 * Return: pointer to corresponding value provided for name.
 */
char *env_find(const char *name, int *offset, char **env)
{
	size_t len;
	const char *np;
	char **p, *c;

	if (name == NULL || env == NULL)
		return NULL;
	for (np = name; *np && *np != '='; ++np)
		continue;
	len = np - name;
	for (p = env; (c = *p) != NULL; ++p)
		if (strncmp(c, name, len) == 0 && c[len] == '=') {
			*offset = p - env;
			return c + len + 1;
		}
	*offset = p - env;
	return NULL;
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
			return *(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1);
		}
	return (0);
}
