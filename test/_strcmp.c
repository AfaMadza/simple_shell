/**
 * _strcmp - compares two strings
 *
 * Return: dest
 * @s1: pointer to first string
 * @s2: pointer to pointer to second string
 */
int _strcmp(char *s1, char *s2)
{
	char *x = s1;
	char *y = s2;
	char cast1, cast2;

	do {
		cast1 = *x++;
		cast2 = *y++;
		if (cast1 == '\0')
		{
			return (cast1 - cast2);
		}
	} while (cast1 == cast2);

	return (cast1 - cast2);
}
