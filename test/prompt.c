#include <stdio.h>
#include <unistd.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * main - prints $ and takes user input to print on newline.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buf;
	size_t buf_size;
	int char_count;
	char *dollar_prompt = "$ ";

	buf = NULL;
	char_count = 0;

	write(STDOUT_FILENO, dollar_prompt, 2);
	while((char_count = getline(&buf, &buf_size, stdin)) != EOF)
	{
		write(STDOUT_FILENO, buf, char_count);
		write(STDOUT_FILENO, dollar_prompt, 2);
	}
	if (char_count == -1)
		exit(EXIT_FAILURE);

	free(buf);
	exit(EXIT_SUCCESS);

}
