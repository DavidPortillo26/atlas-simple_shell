#include "main.h"

extern char **environ;

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

/**
 * getPATH - function to handle the path
 * @cmd: command passed in
 * Return: path
*/
char *getPATH(char *cmd) /*exec is short for executable*/
{
	char *path = envir("PATH"); /*gets the env variables of PATH*/
	char *token, *command;
	struct stat status; /*stat is used to find an exec file*/

	token = strtok(path, ":"); /*splits the path using the : as a separator*/

	while (token) /*searches for an exec file*/
	{
		command = malloc(strlen(token) + strlen(cmd) + 2);
		strcpy(command, token);
		strcat(command. "/");
		strcat(command, cmd);

		if (stat(command, &status) == 0) /*if the path is exec return it*/
			return (command);
		free(command); /*free the path when finished*/
		token = strtok(NULL, ":");
	}

	return (NULL); /*return NULL if no executable file is found*/
}
