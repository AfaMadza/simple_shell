#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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
