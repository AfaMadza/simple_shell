#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 *_realloc - changes the size of memory block.
 *@ptr: memory block whose size needs to be changed.
 *@size: new size of memory block.
 *Return: pointer to new memory block.
 */
void *_realloc(void *ptr, size_t size)
{
	char *p;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	p = malloc(size);
	if (p == NULL)
		return (NULL);
	_memcpy(p, ptr, size);
	free(ptr);
	return (p);
}
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
