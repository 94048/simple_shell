#include "shell.h"

/**
 * _strcpy - Copy a string from source to destination.
 * @dest: The destination buffer where the string will be copied.
 * @src: The source string to be copied.
 *
 * This function copies the null-terminated string 'src' into the buffer
 * pointed to by 'dest'. It overwrites any existing content in 'dest' and
 * ensures that the resulting string is null-terminated.
 *
 * @dest: The destination buffer to hold the copied string.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination buffer 'dest'.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - Duplicate a string in memory.
 * @str: The source string to duplicate.
 *
 * This function allocates memory for a new string and copies the content of
 * the source string 'str' into the newly allocated memory. The returned
 * pointer points to the duplicated string.
 *
 * @str: The source string to be duplicated.
 *
 * Return: If successful, a pointer to the duplicated string; otherwise, NULL.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - Print a string to the standard output.
 * @str: The string to be printed.
 *
 * This function writes the characters of the string 'str' to the standard
 * output, followed by a newline character. It continues to write characters
 * until the terminating null character is encountered.
 *
 * @str: The string to be printed.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - Write a character to the standard output.
 * @c: The character to be written.
 *
 * This function writes a single character 'c' to the standard output.
 *
 * @c: The character to be written.
 * Return: On success, returns the character written. On error, returns -1.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
