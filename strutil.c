#include "simple_shell.h"

/**
 * _strncat - copies at most n bytes of a string.
 * @destn: destination buffer.
 * @src: src buffer.
 * @n: number of bytes from source that will be concatenated
 * Return: pointer to destn.
 */
char *_strncat(char *destn, const char *src, size_t n)
{
	size_t destn_len = _strlen(destn);
	size_t i;

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		destn[destn_len + i] = src[i];
	destn[destn_len + i] = '\0';

	return (destn);
}

/**
 * _strdup - duplicates a string using malloc to assign memory.
 * @s: pointer to string that needs to be duplicated.
 * Return: pointer to duplicate string.
 */
char *_strdup(char *s)
{
	size_t length;
	void *new_mem;

	length = _strlen(s) + 1;
	new_mem = malloc(length);
	if (new_mem == NULL)
		return (NULL);
	return ((char *)_memcpy(new_mem, s, length));
}

/**
 * _strlen - returns length of a string
 *
 * @s: pointer to string whose length will be returned
 * Return: None
 */
int _strlen(char *s)
{
	int length = 0;

	for (; *s != '\0'; s++)
	{
		length++;
	}
	return (length);
}

/**
 * _strncpy - copies at most n bytes of a string.
 * @destn: destination buffer.
 * @src: src buffer.
 * @n: number of bytes to copy
 * Return: pointer to destn.
 */
char *_strncpy(char *destn, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
		destn[i] = src[i];
	for ( ; i == n; i++)
		destn[i] = '\0';

	return (destn);
}
/**
 * _strcmp - compares two strings
 *
 * Return: dest
 * @s1: pointer to first string
 * @s2: pointer to pointer to second string
 */
int _strcmp(char *s1, char *s2)
{
	char *x = s1;
	char *y = s2;
	char cast1, cast2;
	if (s1 == NULL)
		return (0);
	do {
		cast1 = *x++;
		cast2 = *y++;
		if (cast1 == '\0')
		{
			return (cast1 - cast2);
		}
	} while (cast1 == cast2);

	return (cast1 - cast2);
}
