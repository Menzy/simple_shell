#include "menzysh.h"

/**
 * main - Entry point
 * Description: A function that creates a simple shell
 * @ac: argument count
 * @av: Array of strings
 * @env: Array of environment variables
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	char *linepointer = NULL, **linepointer_copy = NULL;
	ssize_t m_nchars_read = 0;
	size_t line_len = 0, prm_i = 0;

	while (1)
	{
		prm_i = prm_i + 1;
		m_prompt();
		m_nchars_read = getline(&linepointer, &line_len, stdin);
		if (m_nchars_read == -1)
			m_EOF(linepointer);
		else if (*linepointer == '\n' || check_spaces(linepointer))
			free(linepointer);
		else
		{
			linepointer_copy = m_parse_token(linepointer, " \t\n\0");
			free(linepointer);
			if (m_strcmp(linepointer_copy[0], "exit") == 0)
				m_exit_shell(linepointer_copy);
			else if (m_strcmp(linepointer_copy[0], "env") == 0)
				m_environ_print(linepointer_copy, env);
			else if (m_strcmp(linepointer_copy[0], "cd") == 0)
				m_change_dirs(linepointer_copy[1], env);
			else
				m_invok_child(linepointer_copy, av[0], env, prm_i);
		}
		fflush(stdin);
		linepointer = NULL, line_len = 0;
	}
	(void)ac;
	return (EXIT_SUCCESS);
}
