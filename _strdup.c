#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
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
