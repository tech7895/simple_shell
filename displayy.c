#include "s_shell.h"

/**
 * display - This function prints a message to the standard output
 *
 * @message: the message
 *
 * Return: no of byte
 *
 **/
int display(char *message)
{
	return (outputToFD(message, 1));
}
