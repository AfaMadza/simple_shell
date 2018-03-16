#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
int main(void)
{
	char **s;
	int i;
	char str[] = "This, is; a - test:.";

	s = parse_argv(str);

	for (i = 0; s[i] != NULL; i++)
	{
		printf("%s\n", s[i]);
	}
	free(s);
	return (0);
}
