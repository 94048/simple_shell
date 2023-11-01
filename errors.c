#include "shell.h"

/**
 * _erratoi - Convert a string to an integer and handle errors.
 * @s: The string to convert.
 *
 * Return: The converted integer value. If an error occurs, it returns -1.
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - Print an error message along with program name and line
 * @info: A pointer to the info_t structure containing program information.
 * @estr: The error message to print.
 *
 * This function prints an error message to the standard error stream (stderr),
 * including the program name and line number. It is used for reporting errors.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - Print an integer to a given file descriptor.
 * @input: The integer to be printed.
 * @fd: The file descriptor to which the integer will be printed.
 *
 * This function prints an integer to the specified file descriptor.
 * It is used for displaying numeric values in a given output stream.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - Convert a long integer to a string with optional
 * @num: The long integer to be converted.
 * @base: The numerical base for conversion (e.g., 10 for decimal).
 * @flags: Flags for custom formatting (e.g., CONVERT_LOWERCASE for lowercase
 *
 * This function converts a long integer to a string representation, allowing
 * for custom formatting based on the specified flags. The converted string
 * can be used for various purposes, including displaying numeric values.
 *
 * Return: A dynamically allocated string containing the converted number.
 *         The caller is responsible for freeing the allocated memory.
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - Remove comments from a string buffer.
 * @buf: The string buffer that may contain comments.
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
