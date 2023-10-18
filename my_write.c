#include "s_shell.h"

/**
 * writeCharacter - This function prints a character to the standard output
 *
 * @xer: the character
 *
 * Return: 1 (success)
 *
 **/
int writeCharacter(char xer)
{
	return (write(1, &xer, 1));
}
