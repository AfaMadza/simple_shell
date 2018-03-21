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
/**
 * struct built_in - struct of type and associated function.
 * @op: function name.
 * @f: function pointer to function to be executed.
 */
typedef struct built_in
{
	char *op;
	int (*f)(char *args, char **env);
} b_in;

/* Shell Functions*/
int args_execute(char **args, char **env);
int launch_prog(char **args, char **env);
char **parse_argv(char *line);
char *read_line(void);
void shell_loop(char **env);

/* Built-ins*/
int ss_env(char *args, char **env);
int ss_exit(char *args, char **env);

/*Utility Functions*/
char *arg_to_path(char **argv, char **env);
char *env_find(const char *name, int *offset, char **env);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t size);
int _strncmp(const char *s1, const char *s2, size_t n);

/*String Utilities*/
int _strlen(char *s);
char *_strdup(char *s);
char *_strncpy(char *destn, const char *src, size_t n);
char *_strncat(char *destn, const char *src, size_t n);
char *_getenv(const char *name, char **env);

/* Misc */
int print_path_dirs(char **env);
path_ll *path_llist(char **env);
void build_path_ll(path_ll *head);
int _strcmp(char *s1, char *s2);

#endif