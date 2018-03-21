#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * _strncpy - copies at most n bytes of a string.
 *@destn: destination buffer.
 *@src: src buffer.
 * Return: pointer to destn.
 */
char *_strncpy(char *destn, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		destn[i] = src[i];
	for ( ; i < n; i++)
		destn[i] = '\0';

	return (destn);
}
