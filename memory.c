#include "s_shell.h"

/**
 * _realloc - This function reallocates memory size
 * @ptr: the pointer
 * @size1: the original memory size
 * @size2: the new size
 * Return: void
 *
 */
void *_realloc(void *ptr, unsigned int size1, unsigned int size2)
{
	char *p, *orgin = ptr;
	unsigned int i, nw = size2;

	if (ptr == NULL)
	{
		p = malloc(size2);
		return (p);
	}
	else if (size2 == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (size2 == size1)
		return (ptr);

	p = malloc(size2);
	if (p == NULL)
		return (NULL);
	if (size2 > size1)
		nw = size1;
	for (i = 0; i < nw; i++)
		p[i] = orgin[i];
	free(ptr);
	return (p);
}

/**
 * releasemem - This function frees a pointer
 * @pointer: the pointer
 * Return: void
 *
 **/
void releasemem(void *pointer)
{
	if (pointer != NULL)
	{
		free(pointer);
		pointer = NULL;
	}
	pointer = NULL;
}

/**
 * releasememptr - This function frees a double pointer
 *
 * Description: frees a pointer to pointer
 * @pointer: the pointer
 * Return: void
 *
 **/
void releasememptr(void **pointer)
{
	void **temp;

	for (temp = pointer; *temp != NULL; temp++)
	{
		releasemem(*temp);
	}

	releasemem(pointer);
}
