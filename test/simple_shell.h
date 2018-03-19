#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

void *_realloc(void *ptr, size_t size);
char **parse_argv(char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
char *read_line(void);
void shell_loop(void);
int args_execute(char **args);
int launch_prog(char **args);
char *env_find(const char *name, int *offset, char **env);
char *_getenv(const char *name, char **env);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif
