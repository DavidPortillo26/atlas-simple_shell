#include "main.h"

/* includes functions to clear/reset variables, generate a custom prompt, and manipulate paths for a custom shell prompt in a C program. */

/* Function to clear/reset variables related to command processing */
void clear_variables1()
{
    /* Reset the input buffer, number of commands, and current working directory */
    input_buffer[0] = '\0';
    no_cmds = 0;
    cwd[0] = '\0';
}

/* Function to clear/reset variables related to command execution */
void clear_variables2()
{
    /* Reset the number of arguments, execution flag, and background process flag */
    no_args = 0;
    execFlag = 0;
    is_bg = 0;
}

/* Function to generate a relative path from the current directory */
void cust_pwd()
{
    char *token1[512];
    char *token2[512];
    char temp[1024];
    char pth[1024];
    int cnt;
    int no_toks1 = 0;
    int no_toks2 = 0;
    int i;

    cnt = 1;
    strcpy(temp, current_directory);
    /* Tokenize the current directory path */
    token1[0] = strtok(temp, "/");
    no_toks1++;
    while ((token1[cnt] = strtok(NULL, "/")) != NULL)
    {
        cnt++;
        no_toks1++;
    }
    token1[cnt] = NULL;

    cnt = 1;
    getcwd(pth, sizeof(pth));
    strcpy(temp, pth);
    /* Tokenize the current working directory path */
    token2[0] = strtok(temp, "/");
    no_toks2++;
    while ((token2[cnt] = strtok(NULL, "/")) != NULL)
    {
        cnt++;
        no_toks2++;
    }
    token2[cnt] = NULL;

    /* Generate relative path based on differences between the two paths */
    if (no_toks1 == no_toks2)
    {
        strcpy(cwd, "~"); /* Both paths have the same number of tokens */
    }
    else
    {
        strcat(cwd, "~"); /* Add tilde to indicate the home directory */
        /* Append remaining directory names to form the relative path */
        for (i = no_toks1; i < no_toks2; i++)
        {
            strcat(cwd, "/");
            strcat(cwd, token2[i]);
        }
    }
}

/* Function to print the shell prompt */
void prompt()
{
    char shell[1000];
    char *buff;
    char hostname[1000];

    buff = (char *)malloc(10 * sizeof(char));
    buff = getlogin(); /* Get the login name of the user */

    gethostname(hostname, 1000); /* Get the hostname of the system */

    /* Generate the shell prompt string */
    strcpy(shell, "<");
    strcat(shell, buff); /* Append the login name */
    strcat(shell, "@");
    strcat(shell, hostname); /* Append the hostname */
    strcat(shell, ":");
    strcat(shell, cwd); /* Append the current working directory */
    strcat(shell, ">");

    /* Print the shell prompt */
    printf("%s", shell);
}
