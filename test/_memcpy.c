#include "simple_shell.h"
/**
 * _memcpy - copies memory area.
 *
 * Return: dest
 * @dest: pointer to memory area that src content will be copied to.
 * @src: pointer to memory area to be copied.
 * @n: number of bytes to be copied.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0 ; i < n; i++)
		dest[i] = src[i];
	return (dest);
}
