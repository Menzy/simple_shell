#include "menzysh.h"

/**
 * _handle - handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return:
 */

void _handle(int signals)
{
	(void)signals;
	write(1, "MENZY_SHELL $ ", 14);
}

/**
 * m_prompt - prints the prompt
 *
 * Return: Nothing.
 */

void m_prompt(void)
{
	if (isatty(0))
		write(1, "MENZY_SHELL $ ", 14);
}

/**
 * check_spaces - checks if the user input only spaces.
 * @linepointer: The pointer to input string.
 * Return: 1 on success, 0 on failure
 */
int check_spaces(char *linepointer)
{
	int i;

	linepointer[m_strlen(linepointer) - 1] = '\0';
	for (i = 0; linepointer[i] != '\0'; i++)
	{
		if (linepointer[i] != ' ')
			return (0);

	}
	return (1);
}
