#include "shell.h"

/**
 * is_cmd - Check if a command is executable.
 * @info: A pointer to the info_t structure containing environment variables.
 * @path: The path to the command to be checked.
 *
 * This function checks if the given command at the specified path
 * meaning it exists and has execution permissions.
 *
 * @info: A pointer to the info_t structure.
 * @path: The path to the command to be checked.
 *
 * Return: 1 if the command is executable, 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - Duplicate a portion of a string.
 * @pathstr: The input string.
 * @start: The starting index of the portion to duplicate.
 * @stop: The stopping index of the portion to duplicate.
 *
 * This function duplicates a specific portion of the input string,
 * from the 'start' index to the 'stop' index (inclusive).
 *
 * @pathstr: The input string to extract from.
 * @start: The starting index of the portion.
 * @stop: The stopping index of the portion.
 *
 * Return: A newly allocated string containing the duplicated portion,
 * or NULL on failure.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - Search for a command in a given path string.
 * @info: A pointer to the info_t structure containing environment variables.
 * @pathstr: The path string to search within.
 * @cmd: The command to find in the path.
 *
 * This function searches for the specified command within the given path
 * string, which consists of directories separated by colons. It checks each
 * directory for the existence of the command and returns the full path
 *
 * @info: A pointer to the info_t structure.
 * @pathstr: The path string to search within.
 * @cmd: The command to find.
 *
 * Return: If the command is found, a dynamically allocated string containing
 * the full path to the command; otherwise, NULL.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
