#include "menzysh.h"
/**
 * m_atoi - Converts a string to integer.
 * @s: Input string.
 * Return: Integer
 */

int m_atoi(char *s)
{
	int i, d, n, lengthh, f, number;

	i = d = n = 0;
	lengthh = 0;
	f = 0;
	number = 0;

	while (s[lengthh] != '\0')
		lengthh++;

	while (i < lengthh && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			number = s[i] - '0';
			if (d % 2)
				number = -number;
			n = n * 10 + number;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);
	else
		return (n);
}

/**
 * m_EOF - checks if EOF character was encountered
 * @linepointer: The pointer to the input string.
 * Return: Nothing
 */

void m_EOF(char *linepointer)
{
	if (linepointer)
	{
		free(linepointer);
		linepointer = NULL;
	}

	if (isatty(0))
		write(1, "\n", 1);

	free(linepointer);
	exit(EXIT_SUCCESS);
}

/**
 * _puts - prints a string to stdout
 * @s: pointer
 * Return: nothing
 */
void _puts(char *s)
{
	while (*s != 0)
	{
		write(1, &(*s), 1);
		s++;
	}
}
