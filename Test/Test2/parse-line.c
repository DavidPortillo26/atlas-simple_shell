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

/**
 * splitstring - splits a string based on a specific delimiter
 * @mem: string to split
 * @delimiter: specific delimiter
 * Return: token array
*/
char **splitstring(char *mem, char *delimiter)
{
	char **arroftok; /*holds an array of tokens*/
	char *tok; /*holds a token*/
	int i = 0; /*iterator*/
	int size = 1024; /*size of memory*/

	arroftok = malloc(sizeof(char *) * size); /*allocates mem for token array*/
	if (arroftok == NULL) /*if mem allocation fails return NULL*/
		return (NULL);
	tok = strtok(mem, delimiter); /*splitting the string*/

	while (tok) /*loop through the string until the null terminator*/
	{
		arroftok[i] = tok;
		tok = strtok(NULL, delimiter);
		i++;
	}
	arroftok[i] = NULL; /*set the null terminator*/

	return (arroftok); /*return the split string*/
}
