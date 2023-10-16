#include "s_shell.h"

/**
 * _strlen - This function  returns the length of string
 * @s: the string
 *
 * Return: the length
 *
 */
int _strlen(char *s)
{
	int s_len;

	s_len = 0;

	while (s[s_len] != '\0')
	{
	s_len++;
	}

	return (s_len);
}

/**
 * _strcat - This function concertenates two strings
 * @dest: the destination
 * @src: the source
 *
 * Return: the concatinated string
 */
char *_strcat(char *dest, char *src)
{
	int l1, l2, i;

	for (l1 = 0; dest[l1] != '\0'; l1++)
	{

	}

	for (l2 = 0; src[l2] != '\0'; l2++)
	{

	}
	for (i = 0; i <= l2; i++)
	{
		dest[l1 + i] = src[i];
	}

	return (dest);
}

/**
 * *_strcpy - This function copies a string
 *
 * @dest: the destination
 * @src: the source
 *
 * Return: dest
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
 *
 * @s1: the first string
 * @s2: the second string
 *
 * Return: the difference
 *
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int d = 0;

	for (i = 0; s1[i] != '\0' && d == 0; i++)
	{
		d = s1[i] - s2[i];
	}

	return (d);
}

/**
 * stringify - This function converts a given number to a string
 * @numbe: the number
 *
 * Return: nmb
 *
 **/
char *stringify(int numbe)
{
	char *num;
	int td, iter;

	td = number(numbe);
	num = malloc(td * sizeof(char) + 1);
	if (num == NULL)
		return (NULL);
	if (numbe == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}

	num[td] = '\0';

	for (iter = td - 1; numbe != 0; numbe /= 10, iter--)
	{
		num[iter] = (numbe % 10) + '0';
	}

	return (num);
}
