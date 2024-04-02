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

