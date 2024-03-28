#include "main.h"
#include <unistd.h>

// Function to execute the built-in commands(cd, pwd, echo)
void builtin(char *s)
{
	// Initialize variables
	int i = 1;  // Index variable for loops
	int j;      // Another index variable for loops
	int c;      // Counter variable
	int flag = 0; // Flag to track special cases

	// Check if the command is 'cd'
	if(strcmp(args[0], "cd") == 0)
	{
		// Check various cases for changing directories
		if(args[1] == NULL)
		{
			// No directory specified, go back to the current directory
			chdir(current_directory);
			execFlag = 1;
		}
		else if(strcmp(args[1], "~") == 0)
        {
			// Tilde specified, go back to the current directory
			chdir(current_directory);
			execFlag = 1;
		}
		else if(strcmp(args[1], "..") == 0)
		{
			// Move up one directory level
			chdir("..");
			execFlag = 1;
		}
		else if(strcmp(args[1], ".") == 0)
		{
			// Stay in the current directory
			execFlag = 1;
		}
		else if(chdir(args[1]) < 0)
		{
			// Attempt to change to the specified directory and print error if fails
			printf("bash: cd: %s: No such file or directory\n", args[1]);
			execFlag = 1;
		}
		else
		{
			// Strip trailing '/' from directory path if present
			if(args[1][strlen(args[1]) - 1] == '/')
			{
				args[1][strlen(args[1]) - 1] = '\0';
			}
			execFlag = 1;
		}
	}

	// Check if the command is 'pwd'
	else if(strcmp(args[0], "pwd") == 0)
	{
		// Get and print the absolute path
		getcwd(temp, sizeof(temp));
		printf("%s\n", temp);
		execFlag = 1;
	}

	// Add functionality for 'echo' command
	else if(strcmp(args[0], "echo") == 0)
	{
		c = 0; // Reset counter

		// Loop through the string
		for(i = 0; i < strlen(s); i++)
		{	
			// Check for double quotes
			if(s[i] == '\"')
			{
				// Check if double quotes are properly used
				if(s[strlen(s) - 1] == '\"')
				{
					// Extract and print content within double quotes
					for(j = i + 1; j < strlen(s) - 1; j++)
					{
						cmd_exec[c++] = s[j];
					}
					cmd_exec[c] = '\0';
					flag = 1;
					printf("%s\n", cmd_exec);
					execFlag = 1;
					break;
				}
				else
				{
					// Double quotes not properly used, print usage message
					printf("Usage: echo \"<text to be printed>\"\n");
					flag = 1;
				}
			}
			// Check for single quotes
			else if(s[i] == '\'')
			{
				// Check if single quotes are properly used
				if(s[strlen(s) - 1] == '\'')
				{
					// Extract and print content within single quotes
					for(j = i + 1; j < strlen(s) - 1; j++)
					{
						cmd_exec[c++] = s[j];
					}
					cmd_exec[c] = '\0';
					flag = 1;
					printf("%s\n", cmd_exec);
					execFlag = 1;
					break;
				}
				else
				{
					// Single quotes not properly used, print usage message
					printf("Usage: echo \"<text to be printed>\"\n");
					flag = 1;
				}
			}
		}

		// If no special cases detected, print arguments as-is
		if(flag == 0)
		{
			i = 1;
			while(args[i] != NULL)
			{
				printf("%s ", args[i]);
				i++;
			}
			printf("\n");
			execFlag = 1;
		}
	}
}
