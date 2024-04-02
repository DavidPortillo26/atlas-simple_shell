#include "main.h"

/* Function to convert integer PID to string */
char* int_to_string(int pid)
{
    char* buf = (char*)malloc(10); /* Allocate memory for the string buffer */
    sprintf(buf, "%d", pid); /* Convert integer PID to string */
    return buf; /* Return the string buffer */
}

/* Function to execute the pinfo command */
void pinfo_command()
{
    char s_file[2048]; /* Buffer to store the path to the stat file */
    char ex_file[2048]; /* Buffer to store the path to the exe file */
    char line[1024]; /* Buffer to store lines read from the stat file */
    char* s_param[100]; /* Array to store parsed parameters from the stat file */
    char ex_path[2048]; /* Buffer to store the path to the executable */
    int ret; /* Variable to store return values from functions */

    strcpy(s_file, "/proc/"); /* Initialize s_file with the path to the proc directory */

    /* Construct the path to the stat file based on the given PID or current process PID */
    if (!args[1])
    {
        strcat(s_file, int_to_string(getpid())); /* If no PID provided, use current process PID */
    }
    else
    {
        strcat(s_file, args[1]); /* Use the provided PID */
    }

    strcpy(ex_file, s_file); /* Copy the path to the exe file */

    strcat(s_file, "/stat"); /* Append "/stat" to the path to get the full path to the stat file */

    FILE* fd = fopen(s_file, "r"); /* Open the stat file for reading */
    if (fd == NULL) /* Check if the file could be opened */
    {
        printf("Process doesn't exist\n"); /* Print error message if the file couldn't be opened */
    }
    else
    {
        fgets(line, sizeof(line), fd); /* Read the first line of the stat file */

        /* Tokenize the line and store parameters in s_param array */
        s_param[0] = strtok(line, " ");
        for (int i = 0; s_param[i] != NULL;)
        {
            s_param[i + 1] = strtok(NULL, " ");
            i++;
        }

        /* Print process information */
        printf("pid -- %s\n", s_param[0]); /* Print PID */
        printf("Process Status -- %s\n", s_param[2]); /* Print process status */
        printf("Virtual Memory -- %s\n", s_param[22]); /* Print virtual memory */

        strcat(ex_file, "/exe"); /* Append "/exe" to the path to get the full path to the exe file */

        /* Read the symbolic link pointing to the executable file */
        ret = readlink(ex_file, ex_path, sizeof(ex_path));
        if (ret < 0) /* Check if readlink failed */
        {
            printf("Unable to find the executable path\n"); /* Print error message */
        }
        else
        {
            ex_path[ret] = '\0'; /* Null terminate the string */
            if (ex_path[1] == 'h' && ex_path[2] == 'o' && ex_path[3] == 'm' && ex_path[4] == 'e') /* Check if executable path starts with "/home" */
            {
                printf("Executable Path: ~%s\n", &ex_path[strlen(current_directory)]); /* Print executable path relative to current directory */
            }
            else
            {
                printf("Executable Path: %s\n", ex_path); /* Print full executable path */
            }
        }
    }
}
