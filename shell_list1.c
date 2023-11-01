#include "shell.h"

/**
 * list_len - Get the number of nodes in a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - Convert a linked list of strings to a string array.
 * @head: A pointer to the head of the linked list.
 *
 * Return: A dynamically allocated array of strings, or NULL on failure.
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - Print the elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - Find the first node that starts with a specific prefix.
 * @node: A pointer to the head of a linked list.
 * @prefix: The prefix to search for in node strings.
 * @c: The character to match following the prefix (use '\0' to match any).
 *
 * This function traverses a linked list and looks for the first node whose
 * string content begins with the specified prefix and, optionally, is followed
 * by the specified character. If such a node is found, a pointer to that node
 * is returned; otherwise, NULL is returned.
 *
 * @node: The head of the linked list to search.
 * @prefix: The string prefix to match.
 * @c: The character to match following the prefix ('\0' to match character)
 *
 * Return: A pointer to the matching node, or NULL if no match is found.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - Get the index of a specific node in a linked list.
 * @head: A pointer to the head of the linked list.
 * @node: A pointer to the node whose index is to be found.
 *
 * This function calculates the index (position) of a specific node within a
 * linked list, starting from the head as the first node (index 0). If the node
 * is not found in the list, it returns -1.
 *
 * @head: The head of the linked list.
 * @node: The node whose index is to be determined.
 *
 * Return: The index of the node in the list, or -1 if the node is not found.
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
