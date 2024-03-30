#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
 * main - reads the user input
 * Return: success
*/
int main(void)
{
	char *cmd, /*command*/ *token = NULL; /*token*/
	char *delimiter = " \n";
	char **array;
	int k = 0; /*index*/
	int size_limit = 1024; /*size limit for array*/
	size_t n = 0; /*size of command*/

	while (1) /*infinite loop*/
	{
		write(1, "SimpleShell$ ", 13);
		getline(&cmd, &n, stdin); /*reads the input*/
		token = strtok(cmd, delimiter);
		array = malloc(sizeof(char *) * size_limit) /*array space allocation*/

		while (token != NULL) /*creates an array of tokens*/
		{
			array[k] = token;
			token = strtok(cmd, delimiter)
		}

		if (token != NULL) /*if token doesnt = NULL send into the func cmdline*/
		{
			cmdline(token);
		}
	}
}
