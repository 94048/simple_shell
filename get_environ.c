#include "shell.h"

/**
 * get_environ - Retrieve the environment as an array of strings.
 * @info: A pointer to the info_t  containing environment information.
 *
 * This function extracts the environment from the provided info_t
 * structure and returns them as an array of strings.
 *
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - Unset (remove) an environment variable.
 * @info: A pointer to the info_t structure containing information.
 * @var: The name of the environment variable to unset.
 *
 * This function removes the specified environment from the environment.
 *
 * Return: 0 on success, -1 on failure.
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Set (add or modify) an environment variable.
 * @info: A pointer to the info_t structure containing environment information.
 * @var: The name of the environment variable to set or modify.
 * @value: The value to assign to the environment variable.
 *
 * This function sets or modifies the specified environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
