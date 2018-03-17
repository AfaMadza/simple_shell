#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * parse_argv - splits a string and returns an array for each argument.
 *@line: pointer to string that needs to be split.
 * Return: pointer to first element of array.
 */
int main(int argc, char **argv)
{
	shell_loop();

	return (EXIT_SUCCESS);
}
