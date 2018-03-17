#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * args_execute - launches processes.
 *@args: double pointer to argv.
 * Return: completed process.
 */
int args_execute(char **args)
{
	return (launch_prog(args));
}
