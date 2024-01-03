#include "menzysh.h"

/**
 * m_free_argv - frees all memory allocated for linepointer_copy.
 * @linepointer_copy: copy of input string
 * Return: Nothing.
 */

void m_free_argv(char **linepointer_copy)
{
	size_t count = 0;

	if (linepointer_copy == NULL)
		return;

	for (count = 0; linepointer_copy[count]; count++)
	{
		free(linepointer_copy[count]);
	}

	if (linepointer_copy[count] == NULL)
	{
		free(linepointer_copy[count]);
	}

	free(linepointer_copy);
}



/**
 * m_free_before_exit - frees all memory allocated and exit.
 * @linepointer_copy: copy of input string
 * Return: Nothing.
 */

void m_free_before_exit(char **linepointer_copy)
{
	size_t count;

	if (linepointer_copy == NULL)
		return;

	for (count = 0; linepointer_copy[count]; count++)
	{
		free(linepointer_copy[count]);
	}

	if (linepointer_copy[count] == NULL)
	{
		free(linepointer_copy[count]);
	}

	free(linepointer_copy);
	exit(1);
}
