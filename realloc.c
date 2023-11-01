#include "shell.h"

/**
 * _memset - Fill memory with a constant byte.
 * @s: A pointer to the memory area to be filled.
 * @b: The byte value to be set.
 * @n: The number of bytes to be set to the value.
 *
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - Frees a double pointer and sets it to NULL.
 * @pp: A pointer to a pointer to be freed.
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Reallocates a memory block with a new size.
 * @ptr: A pointer to the previously allocated memory block.
 * @old_size: The size of the previously allocated memory block.
 * @new_size: The size of the new memory block.
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
