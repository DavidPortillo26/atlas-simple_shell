#include "main.h"
/**
 * tokenize - tokenize the user input
 * @input: user input
 * @tok: stores the tokens
 * Return: number of tokens
*/

int tokenize(char *input, char *tok[])
{
	char *delimiter = " "; /*separates text to allow parsing*/
	char *token = strtok(input, delimiter); /*creates the token*/
	int i = 0;

	while (token) /*loop to store the amount of tokens*/
	{
		tok[i++] = token;
		token = strtok(NULL, delimiter);
	}

	return (i); /*returning the number of tokens*/
}

/**
 * envir - function to handle the environment
 * @env: environment
 * Return: PATH
*/

char *envir(const char *env)
{
	char **environ;
	int i = 0; /*iterator*/
	char *token; /*token to hold the environment*/

	while (environ[i]) /*loop to get the env variable*/
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, env) == 0) /*return the env variable upon success*/
		{
			return (strtok(NULL, "="));
		}
		i++;

		return (NULL); /*returns null if the env variable is non-existant*/
	}
}
