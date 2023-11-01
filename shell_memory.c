#include "shell.h"

/**
 * bfree - Free a pointer and set it to NULL.
 * @ptr: A pointer to a pointer to be freed.
 *
 * This function frees the memory pointed to by the given pointer and sets the
 * pointer to NULL to prevent any further access to the freed memory. It helps
 * avoid double freeing and dangling pointers.
 *
 * @ptr: A pointer to a pointer that needs to be freed and set to NULL.
 *
 * Return: 1 if the pointer was successfully freed and set to NULL, 0 otherwise
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

