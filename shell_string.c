#include "shell.h"

/**
 * _strlen - Calculate the length of a string.
 * @s: A pointer to the null-terminated string.
 *
 * This function calculates the length of the provided null-terminated string
 * by counting the number of characters in the string until the null terminator
 * is encountered.
 *
 * @s: A pointer to the string.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - Compare two strings character by character.
 * @s1: A pointer to the first null-terminated string.
 * @s2: A pointer to the second null-terminated string.
 *
 * This function compares two strings character by character and returns an
 * integer representing their relative order. It returns a value less than 0 if
 * s1 is less than s2, 0 if they are equal, and a value greater than 0 if s1 is
 * greater than s2, based on their ASCII values.
 *
 * @s1: A pointer to the first string.
 * @s2: A pointer to the second string.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found
 * to be less than, equal to, or greater than s2, respectively.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Check if a string starts with a given prefix.
 * @haystack: The string to be checked.
 * @needle: The prefix to check for.
 *
 * This function checks whether the string 'haystack' starts with the prefix
 * 'needle'. It returns a pointer to the first occurrence of 'needle' in
 * 'haystack' if found, or NULL if 'haystack' does not start with 'needle'.
 *
 * @haystack: The string to be checked.
 * @needle: The prefix to check for.
 *
 * Return: A pointer to the first occurrence of 'needle' in 'haystack', or NULL
 * if not found.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination string where the concatenation will occur.
 * @src: The source string to be appended to the destination.
 *
 * This function concatenates the string 'src' to the end of the string 'dest'.
 * It overwrites the null-terminator at the end of 'dest' with the first
 * character of 'src' and then continues copying the rest of 'src'. The final
 * string is null-terminated.
 *
 * @dest: The destination string where concatenation will occur.
 * @src: The source string to be appended.
 *
 * Return: A pointer to the destination string 'dest'.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
