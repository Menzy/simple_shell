#include "menzysh.h"

/**
 * m_environ_print - prints all enviromental variables.
 * @linepointer_copy: tokens from user
 * @env: The pointer to enviromental variables.
 * Return:
 */

void m_environ_print(char **linepointer_copy, char **env)
{
	size_t count, len = 0;

	for (count = 0; env[count] != NULL; count++)
	{
		len = m_strlen(env[count]);

		write(1, env[count], len);
		write(1, "\n", 1);
	}
	m_free_argv(linepointer_copy);
}

/**
 * m_exit_shell - if "exit" is encountered, exits the shell
 * @linepointer_copy: tokenized linepointer_copy ptr
 * Return: Nothing.
 */

void m_exit_shell(char **linepointer_copy)
{
	int stat = 0;

	if (linepointer_copy[1] == NULL)
	{
		if (stat == 2)
		{
			m_free_argv(linepointer_copy);
			exit(2);
		}
		else
		{
			m_free_argv(linepointer_copy);
			exit(0);
		}
	}
	else
	{
		stat = m_atoi(linepointer_copy[1]);
		m_free_argv(linepointer_copy);
		exit(stat);
	}
}

/**
 * m_change_dirs - changes working directory.
 * @path: The new current working directory.
 * @env: Array of environment variables
 * Return: 0 on success, -1 on failure.
 */

int m_change_dirs(char *path, char **env)
{
	char *new_directory, *current_directory/* *buffer = NULL */;

	if (path == NULL || m_strcmp(path, "~") == 0)
		new_directory = m_gethome_dir(env);
	else if (m_strcmp(path, "-") == 0)
		new_directory = m_getOldPwd(env);
	else
		new_directory = path;

	if (chdir(new_directory) != 0)
		perror("Error");
	else
	{
		current_directory = getcwd(NULL, 0);
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", current_directory, 1);
		if (current_directory != NULL)
			free(current_directory);
	}
	free(path);
	return (0);
}


/**
 * m_gethome_dir - Gets the 
 * HOME enviromental variable.
 * @env: Array of enviromental variables.
 * Return: the path of the home dir
 */

char *m_gethome_dir(char **env)
{
	char *home = NULL;
	size_t idx = 0;

	while (env[idx])
	{
		if (strncmp(env[idx], "HOME=", 5) == 0)
		{
			home = &env[idx][5];
			break;
		}
		idx++;
	}

	return (home);
}


/**
 * m_getOldPwd - Gets the value of the
 * OLDPWD enviromental variable.
 * @env: Array of enviromental variables.
 * Return: OLDPWD path
 */

char *m_getOldPwd(char **env)
{
	char *hme = NULL;
	size_t idx = 0;

	while (env[idx])
	{
		if (strncmp(env[idx], "OLDPWD=", 7) == 0)
		{
			hme = &env[idx][7];
			break;
		}
		idx++;
	}

	return (hme);
}
