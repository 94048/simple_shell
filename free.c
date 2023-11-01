#include "shell.h"

/**
 * _eputs - Print a string to the standard error stream.
 * @str: The string to be printed to stderr.
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - Writes a character to the standard error (stderr) stream.
 * @c: The character to be written.
 *
 * This function writes the specified character to the standard error (stderr)
 * stream, which is commonly used for error output and diagnostics.
 *
 * Return: On success, returns the character written. On failure, returns -1.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - Writes a character to the specified file descriptor.
 * @c: The character to be written.
 * @fd: The file descriptor to which the character is written.
 *
 * This function writes the specified character to the file descriptor @fd.
 * It allows writing characters to a custom file descriptor, which can be
 * standard output (stdout), standard error (stderr), or other custom
 * file descriptors.
 *
 * Return: On success, returns the character written. On failure, returns -1.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - Writes a string to the specified file descriptor.
 * @str: The string to be written.
 * @fd: The file descriptor to which the string is written.
 *
 * This function writes the specified string to the file descriptor @fd.
 * It allows writing strings to a custom file descriptor, which can be
 * standard output (stdout), standard error (stderr), or other custom
 * file descriptors.
 *
 * Return: The number of characters written on success, or -1 on failure.
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
