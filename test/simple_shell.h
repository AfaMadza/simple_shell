#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

typedef struct path_linkedlist
{
	char *path_dirs;
	struct path_linkedlist *next;
} path_ll;

void *_realloc(void *ptr, size_t size);
char **parse_argv(char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
char *read_line(void);
void shell_loop(char **env);
int args_execute(char **args, char **env);
int launch_prog(char **args, char **env);
char *env_find(const char *name, int *offset, char **env);
char *_getenv(const char *name, char **env);
int _strncmp(const char *s1, const char *s2, size_t n);
int print_path_dirs(char **env);
int _strlen(char *s);
path_ll *path_llist(char **env);
void build_path_ll(path_ll *head);
char *_strdup(char *s);
char *arg_to_path(char **argv, char **env);
char *_strncpy(char *destn, const char *src, size_t n);
char *_strncat(char *destn, const char *src, size_t n);

#endif
