#include "menzysh.h"

/**
 * m_strcat - Concatenates two strings.
 * @destination: An input string.
 * @source: An input string.
 * Return: A pointer to the resulting string.
 */

char *m_strcat(char *destination, char *source)
{
	char *temp = destination;
	int a = 0, b = 0;

	while (destination[a])
	{
		a++;
	}

	destination[a] = '/';
	a++;

	while (source[b])
	{
		destination[a] = source[b];
		a++;
		b++;
	}
	return (temp);
}

/**
 * m_strcmp - A funtion that compares two strings.
 * @string1: first string
 * @string2: second string
 * Return: 1 if strings are the same, 0 if not.
 */

int m_strcmp(char *string1, char *string2)
{
	unsigned int j;

	for (j = 0; string1[j] != '\0'; j++)
	{
		if (string1[j] != string2[j])
			return (1);
	}
	return (0);
}

/**
 * m_strcpy - Copies a string and paste to another string.
 * @destination: string destinationation
 * @source: string source
 * Return: A pointer to copied string.
 */

char *m_strcpy(char *destination, char *source)
{
	char *temp = destination;
	int i = 0;

	for (i = 0; source[i]; i++)
	{
		destination[i] = source[i];
	}
	destination[i] = '\0';

	return (temp);
}

/**
 * m_strlen - Finds the length of a string
 * @s: The input string.
 * Return: The length of the string
 */

unsigned int m_strlen(char *s)
{
	unsigned int mlen = 0;

	while (s[mlen] != '\0')
	{
		mlen++;
	}

	return (mlen);
}

/**
 * m_strncmp - compates n characters in 2 strings
 * @string1: first string
 * @string2: 2nd string
 * @n: number of bytes to compare
 * Return: 0 if it's a match and -1 or 1 if not
 */

int m_strncmp(const char *string1, const char *string2, size_t n)
{
	size_t k;

	for (k = 0; k < n; k++)
	{
		if (string1[k] != string2[k])
		{
			return ((string1[k] < string2[k]) ? -1 : 1);
		}
		else if (string1[k] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
