#include "main.h"

char **environment;

/**
 * _getenv - Get environment variables.
 * @env: nvironment variable.
 * Return: Contents of environment variable.
 */
char *_getenv(char *env)
{
	int i = 0, j;
	int status;

	while (environment[i])
	{
		status = 1;

		for (j = 0; environment[i][j] != '='; j++)
		{
			if (environment[i][j] != env[j])
				status = 0;
		}
		if (status == 1)
			break;
		i++;
	}
	return (&environment[i][j + 1]);
}

/**
 * _env - It's a function that prints the environment.
 *
 * Return: Void.
 */
void _env(void)
{
	int i = 0;

	while (environment[i])
	{
		printf("%s\n", environment[i]);
		i++;
	}
}
