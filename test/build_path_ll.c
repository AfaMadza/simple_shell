#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "simple_shell.h"
/**
 * build_path_ll - prints linked list made from PATH dirs.
 * @head: pointer to first node of linked list.
 * Return: None.
 */
void build_path_ll(path_ll *head)
{
	int len;
	char *new_line = "\n";

	while (head)
	{
		len = _strlen(head->path_dirs);
		write(STDOUT_FILENO, head->path_dirs, len);
		write(STDOUT_FILENO, new_line, 1);
		head = head->next;
	}
}
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
 * path_llist - builds a linked list from PATH directories.
 * @env: array of pointers to strings callend environment.
 * Return: pointer to first element in linked list.
 */
path_ll *path_llist(char **env)
{
	char *path;
	char **tokens;
	int i = 0, path_count = 0;
	path_ll *head_pt, *head = NULL;
	path_ll *new_node;

	path = _getenv("PATH", env);
	tokens = parse_argv(path);

	while (tokens[i])
	{
		path_count++;
		i++;
	}
	for (i = 0; i < path_count; i++)
	{
		if (i == 0)
		{
			head = malloc(sizeof(path_ll));
			if (head == NULL)
				exit(-1);
			head_pt = head;
		}
		head->path_dirs = _strdup(tokens[i]);
		if (i < path_count - 1)
		{
			new_node = malloc(sizeof(path_ll));
			if (new_node == NULL)
				exit(-1);
		}
		else
			new_node = NULL;
		head->next = new_node;
		head = new_node;

	}
	return (head_pt);
}
/**
 * main - calls build_path_ll and path_llist to print PATH dirs.
 * @argc: void.
 * @argv: void.
 * @env: environmental variable.
 * Return: 0.
 */
int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;

	build_path_ll(path_llist(env));
	return (0);
}
