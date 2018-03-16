#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void *_realloc(void *ptr, size_t size);
char **parse_argv(char *line);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif
