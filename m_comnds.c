#include "menzysh.h"


/**
 * m_invok_child - makes child process
 * @linepointer_copy: The pointer to tokenized linepointer_copy.
 * @name: The shell's name.
 * @env: Array of enviromental variables.
 * @mprm: Prompt count.
 * Return: Nothing.
 */

void m_invok_child(char **linepointer_copy, char *name, char **env, size_t mprm)
{
	pid_t pid = 0;
	int status = 0, wait_err = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		m_free_before_exit(linepointer_copy);
	}
	else if (pid == 0)
	{
		m_execmd(linepointer_copy, name, env, mprm);
		/*m_free_argv(linepointer_copy);*/

	}
	else
	{
		wait_err = waitpid(pid, &status, 0);
		if (wait_err < 0)
		{
			m_free_before_exit(linepointer_copy);
		}
		m_free_argv(linepointer_copy);
	}
}

/**
 * m_execmd - A function that executes a linepointer_copy.
 * @linepointer_copy: The pointer to tokenized linepointer_copy.
 * @name: The name of the shell.
 * @env: The pointer to the enviromental variables.
 * @mprm: Number of executed mprm.
 * Return: Nothing.
 */
void m_execmd(char **linepointer_copy, char *name, char **env, size_t mprm)
{
	char **mpathvar = NULL, *fullcommanddpath = NULL;
	struct stat buf;
	unsigned int i = 0;

	if (stat(linepointer_copy[0], &buf) == 0)
	{
		if (execve(linepointer_copy[0], linepointer_copy, env) < 0)
		{
			/*perror(name);*/
			m_free_before_exit(linepointer_copy);
		}
	}
	else
	{
		mpathvar = m_get_pathtok(env);
		while (mpathvar[i])
		{
			fullcommanddpath = m_strcat(mpathvar[i], linepointer_copy[0]);
			i++;
			if (stat(fullcommanddpath, &buf) == 0)
			{
				if (execve(fullcommanddpath, linepointer_copy, env) < 0)
				{
					/*perror(name);*/
					m_free_argv(mpathvar);
					m_free_before_exit(linepointer_copy);
				}
				return;
			}
		}
		m_error_msg(name, mprm, linepointer_copy);
		/*(void)name; (void)mprm;*/
		m_free_argv(mpathvar);
		m_free_argv(linepointer_copy);
		linepointer_copy = NULL;
	}
}


/**
 * m_error_msg - prints error messahe
 * @name: The name of the shell.
 * @mprm: Number of mprm.
 * @linepointer_copy: The pointer to tokenized linepointer_copy.
 * Return: Nothing.
 */

void m_error_msg(char *name, size_t mprm, char **linepointer_copy)
{
	char c;

	/*perror(name);*/
	c = mprm + '0';
	write(2, name, m_strlen(name));
	write(2, ": ", 2);
	write(2, &c, 1);
	write(2, ": ", 2);
	write(2, linepointer_copy[0], m_strlen(linepointer_copy[0]));
	write(2, ": not found\n", 12);
}


/**
 * m_get_pathtok - Gets the full value from the
 * PATH enviromental variable.
 * @env: Array of enviromental variables.
 * Return: the directories listed in the
 * PATH environment variable.
 */

char **m_get_pathtok(char **env)
{
	char *mpathvalue = NULL, **mpathvar = NULL;
	size_t k = 0;

	mpathvalue = strtok(env[k], "=");
	for (; env[k]; k++)
	{
		if (m_strcmp(mpathvalue, "PATH") == 0)
		{
			mpathvalue = strtok(NULL, "\n");
			mpathvar = m_parse_token(mpathvalue, ":");
			return (mpathvar);
		}
		mpathvalue = strtok(env[k], "=");
	}
	return (NULL);
}


/**
 * m_parse_token - A function that split and create a full string command.
 * @delimit: The delimiter for str.
 * @linepointer: The pointer to input string.
 * Return: A string with full command.
 */

char **m_parse_token(char *linepointer, const char *delimit)
{
	char *mtoken = NULL, **linepointer_copy = NULL;
	size_t mbuffersize = 0;
	int i = 0;

	if (linepointer == NULL)
		return (NULL);

	mbuffersize = m_strlen(linepointer);
	linepointer_copy = malloc(sizeof(char *) * (mbuffersize + 1));
	if (linepointer_copy == NULL)
	{
		perror("Unable to allocate linepointer");
		free(linepointer);
		m_free_argv(linepointer_copy);
		exit(EXIT_FAILURE);
	}
	mtoken = strtok(linepointer, delimit);
	for (; mtoken != NULL; i++)
	{
		linepointer_copy[i] = malloc(m_strlen(mtoken) + 1);
		if (linepointer_copy[i] == NULL)
		{
			perror("Unable to allocate linepointer");
			m_free_argv(linepointer_copy);
			free(linepointer);
			return (NULL);
		}
		m_strcpy(linepointer_copy[i], mtoken);
		mtoken = strtok(NULL, delimit);
	}
	linepointer_copy[i] = NULL;
	return (linepointer_copy);
}
