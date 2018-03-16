#include <stdio.h>
#include <unistd.h>

/**
 * main - prints arguments.
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int i = 0;

	for (; av[i] != '\0'; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
