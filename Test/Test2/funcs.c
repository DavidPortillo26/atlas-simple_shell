#include "lists.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - handles command line arguments
 * @argc: number of arguments
 * @argv: argument vector
 * Return: command line argument 0 (success)
*/

int main(int argc, char *argv[])
	{
		if (isatty(STDIN_FILENO)) /* checks if the shell is in interactive mode*/
		{
			char cwd[1024]; /*creates space for the path of the cwd*/

			getcwd(cwd, sizeof(cwd)); /*returns the absolute path of the cwd*/

		}
		else
		{
			/*if running in non-interactive mode execute script or batch file commands*/
		}
	}
/**
 * shell_path - handles the path
 * @path: path of the shell
 * Return: Success
*/
struct node *shell_path(char *path)
{
	struct node *head = NULL;
	struct node *tail = NULL;

	char *dir = strtok(path, ":");

	while (dir != NULL)
	{

	}
}
