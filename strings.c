#include "s_shell.h"
/**
 * _strlen - This function returns the length of a string
 * @s: Input string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int s_len = 0;

	while (s[s_len] != '\0')
	{
		s_len++;
	}

	return (s_len);
}

/**
 * *_strcpy - This function copies a string
 *
 * @dest: the destination
 * @src: the source string
 * Return: the pointer (dest)
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - This function compares two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: 0 if the strings are the same, non-zero if not
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int comp = 0;

	for (i = 0; s1[i] != '\0' && comp == 0; i++)
	{
		comp = s1[i] - s2[i];
	}

	return (comp);
}

/**
 * _strcat - This function concertenates two strings
 *
 * @dest: the destination string
 * @src: the source string
 *
 * Return: the destination string
 */
char *_strcat(char *dest, char *src)
{
	int i, lend = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		lend++;
	}

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[lend + i] = src[i];
	}
	return (dest);
}
