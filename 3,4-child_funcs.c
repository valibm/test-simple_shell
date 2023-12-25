#include "main.h"

/**
 * find_path - It searches among the path
 * @command: cmd
 * Return: Returns path if succesfull, NULL otherwise.
 */
char *find_path(char *command)
{
	char *path = _getenv("PATH"), *concatanated = NULL,*copied;
	char **splitted;
	int i = 0, path_len = 0;
	struct stat info;

	if (stat(command, &info) == 0)
		return (command);

	copied = malloc(strlen(path) + 1);

	copied = strcpy(copied, path);
	splitted = split(copied, ":");

	while (splitted[i])
	{
		path_len = strlen(splitted[i]);

		if (splitted[i][path_len - 1] != '/')
			concatanated = strcat(splitted[i], "/");

		concatanated = strcat(splitted[i], command);

		if (stat(concatanated, &info) == 0)
			break;

		i++;
	}

	free(copied);

	if (!splitted[i])
	{
		free(splitted);
		return (NULL);
	}

	free(splitted);
	return (concatanated);
}

/**
 * check_buff - Checks if the buffer is empty.
 * @buff: cmd arguments.
 * Return: 0 if empty, 1 if not.
 */

int check_buff(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] != ' ')
			return (0);
	}
	return (1);
}

/**
 * _split - It tokenizes the input string based on the specified delimiter.
 * @str: Input string.
 * @sep: Separator.
 * Return: Tokenized string.
 */
char **split(char *str, char *sep)
{
	char *aux, **split_str;
	int i = 0;

	aux = strtok(str, sep);
	split_str = calloc(100, sizeof(char *));

	if (!split_str)
	{
		free(split_str);
		return (NULL);
	}

	while (aux)
	{
		split_str[i] = aux;
		aux = strtok(NULL, sep);
		i++;
	}
	return (split_str);
}
