#include <unistd.h>
#include <stdio.h>
/**
 * _strlen - returns length of a string
 *
 * @s: pointer to string whose length will be returned
 * Return: None
 */
int _strlen(char *s)
{
	int length = 0;

	for (; *s != '\0'; s++)
	{
		length++;
	}
	return (length);
}
/**
 * main - prints out the environment.
 * @argc: number of arguments.
 * @argv: array of arguments.
 * @environ: array of pointers to strings called the environment.
 * Return: 0.
 */
int main(int argc, char **argv, char **environ)
{
	(void)argc;
	(void)argv;

	printf("%p\n", &environ);
	return (0);
}
