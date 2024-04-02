#include "main.h"

/* Function to convert integer to string */
char* int_to_string(int pid)
{
    char* buf = (char*)malloc(10); /* Allocate memory for the string buffer */
    sprintf(buf, "%d", pid); /* Convert integer to string */
    return buf; /* Return the string buffer */
}

/* Function to execute pinfo command */
void pinfo_command()
{
    char s_file[2048]; /* Buffer for storing the path to the stat file */
    char ex_file[2048]; /* Buffer for storing the path to the exe file */
    char line[1024]; /* Buffer for reading lines from the stat file */
    char* s_param[100]; /* Array to store parsed parameters from the stat file */
    char ex_path[2048]; /* Buffer for storing the executable path */
    int ret; /* Return value for readlink */

    strcpy(s_file, "/proc/"); /* Initialize s_file with the path to /proc/ */

    /* If no process ID is provided as argument, use the current process ID */
    if(!args[1])
    {
        strcat(s_file, int_to_string(getpid())); /* Append current process ID to s_file */
    }
    else
    {
        strcat(s_file, args[1]); /* Append specified process ID to s_file */
    }
    
    strcpy(ex_file, s_file); /* Copy s_file to ex_file */
    strcat(s_file, "/stat"); /* Append /stat to s_file */

    FILE* fd = fopen(s_file, "r"); /* Open the stat file for reading */
    if(fd == NULL)
    {
        printf("Process doesn't exist\n"); /* Print error message if stat file cannot be opened */
    }
    else
    {
        fgets(line, sizeof(line), fd); /* Read a line from the stat file */

        /* Tokenize the line to extract process parameters */
        s_param[0] = strtok(line, " ");
        for(int i = 0; s_param[i] != NULL;)
        {
            s_param[i + 1] = strtok(NULL, " ");
            i++;
        }

        /* Print process information */
        printf("pid -- %s\n", s_param[0]); /* Print process ID */
        printf("Process Status -- %s\n", s_param[2]); /* Print process status */
        printf("Virtual Memory -- %s\n", s_param[22]); /* Print virtual memory size */
    
        strcat(ex_file, "/exe"); /* Append /exe to ex_file */

        /* Get the executable path of the process */
        ret = readlink(ex_file, ex_path, sizeof(ex_path));
        if(ret < 0)
        {
            printf("Unable to find the executable path\n"); /* Print error message if executable path cannot be retrieved */
        }
        else
        {
            ex_path[ret] = '\0'; /* Null-terminate the executable path string */

            /* Print the executable path */
            if(ex_path[1] == 'h' && ex_path[2] == 'o' && ex_path[3] == 'm' && ex_path[4] == 'e')
            {
                printf("Executable Path: ~%s\n", &ex_path[strlen(current_directory)]); /* Print home directory relative path */
            }
            else
            {
                printf("Executable Path: %s\n", ex_path); /* Print absolute path */
            }
        }
    }
}
