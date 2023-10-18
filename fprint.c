#include "s_shell.h"

/**
 * outputToFD - This function prints a string
 * @message: the message
 * @fil_d: a file descriptor
 *
 * Return: the output
 *
 **/
int outputToFD(char *message, int fil_d)
{
	int siz;

	siz = _strlen(message);

	return (write(fil_d, message, siz));
}
