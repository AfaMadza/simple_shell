# simple_shell
### Description
Holberton School's simple_shell ensures students grasp core concepts such including memory allocation and management, argc/argv, parent/child processes, and file i/o. Other basic concepts such as loops, arrays, structs, and pointers were employed in the making of this function.

### Environment
This function was developed and tested on `Ubuntu 14.04 LTS` via Vagrant in VirtualBox.

### File Contents
The repository contains the following files:

   **File**   |   **Description**
-------------- | ---------------------
args_execute.c | launches processes
arg_to_path.c | searches for an argument in PATH env variable
builtin_func.c | functions to handle built-in commands
launch_prog.c | forks current process passes parsed input to execve
parse_argv.c | splits string into an array of single word tokens
read_line.c | uses getline to read input from STDIN
README.md | readme file
shell_loop.c | controls flow of the shell
simple_shell.c | entry point that imports env and invokes shell_loop
simple_shell.h | header file
strutil.c | five replica standard library utility string functions
util.c | misc utility functions; mostly standard library replicas

### Function Descriptions

 **Function** | **Description**
-------------- | -----------------
int args_execute(char **args, char **env) | 
int launch_prog(char **args, char **env) | 
char **parse_argv(char *line) | 
struct line read_line(void) | 
void shell_loop(char **env) | 
int ss_env(char *args, char **env) | 
int ss_exit(char *args, char **env) | 
void ss_ctrlc(int signum) | 
char *arg_to_path(char **argv, char **env) | 
char *env_find(const char *name, int *offset, char **env) | 
char *_memcpy(char *dest, char *src, unsigned int n) | 
void *_realloc(void *ptr, size_t size) | 
int _strncmp(const char *s1, const char *s2, size_t n) | 
int _strlen(char *s) | 
char *_strdup(char *s) | 
char *_strncpy(char *destn, const char *src, size_t n) | 
char *_strncat(char *destn, const char *src, size_t n) | 
char *_getenv(const char *name, char **env) | 
int _strcmp(char *s1, char *s2) | 

### Usage and Installation
Clone the repository and then compile using gcc.
```
$ git clone https://github.com/AfaMadza/simple_shell
```
### Compilation

This code was compiled with the following flags:
` gcc -Wall -Werror -Wextra -pedantic *.c -o hsh `

###### Example code

```

```

###  Roadmap

---

### Authors

* [**Afa Madza**](https://github.com/AfaMadza)
* [**Alex Allen**](https://github.com/sanjurosaves)

<p align="center">
<a href="https://www.holbertonschool.com"><img src="https://intranet.hbtn.io/assets/holberton-logo-simplified-d4e8a1e8bf5ad93c8c3ce32895b4b53749b477b7ba7342d7f064e6883bcd3be2.png"></a>
</p>