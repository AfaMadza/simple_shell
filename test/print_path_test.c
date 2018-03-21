#include <stdio.h>
#include "simple_shell.h"
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	print_path_dirs(env);
	return (0);
}
