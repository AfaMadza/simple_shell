#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "simple_shell.h"

/**
 * struct line - struct of buffer and its charcount
 * @buf: character buffer
 * @char_count: count of chars in buf
 */
typedef struct line
{
	char *buf;
	int char_count;
} line_t;


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
int args_execute(char **m_argv, char **args, char **env);
int launch_prog(char **m_argv, char **args, char **env);
char **parse_argv(char *line);
struct line read_line(void);
void shell_loop(char **argv, char **env);

/* Built-ins*/
int ss_env(char *args, char **env);
int ss_exit(char *args, char **env);
void ss_ctrlc(int signum);

/*Utility Functions*/
char *arg_to_path(char **argv, char **env);
char *env_find(const char *name, int *offset, char **env);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, size_t size);
char *_getenv(const char *name, char **env);

/*String Utilities*/
int _strlen(char *s);
char *_strdup(char *s);
char *_strncpy(char *destn, const char *src, size_t n);
char *_strncat(char *destn, const char *src, size_t n);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* Errors */
int no_args(char **argv);
void fork_error(char **argv);
void execve_error(char **argv);
int null_arg_w_free(char *converted_arg, char **argv, char *s, int i);
void execve_error_w_free(char *converted_arg, char **argv);

/*Additional Utils*/
char *_itoa(int n);
int count_digit(int n);

#endif
