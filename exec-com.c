#include "main.h"

/* Function to handle termination of child processes */
void sigchildHandler(int signal) {
    /* Handle termination of child process here */
}

/* Function to execute system commands */
void execCommand() 
{
    int status;
    pid_t pid, wpid;

    /* Check if the command is to be executed in the background */
    if (strcmp(no_args[args - 1], "&") == 0) {
        is_bg = 1;
        args[no_args - 1] = NULL;
    }
 /* Fork a new process */
    pid = fork();
    if (pid == -1) { /* Error handling for fork failure */
        fprintf(stderr, "Fork command has failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) 
    {  
        /* Child process */
        /* Reset signal handler to default behavior */
        signal(SIGCHLD, SIG_DFL);

        /* Execute the command in the child process */
        if (execvp(args[0], args) < 0) {
            fprintf(stderr, "Command could not be executed: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
         } else {  // Parent process
        // Foreground process
        if (is_bg == 0) {
            wpid = waitpid(pid, &status, WUNTRACED);
            while (!WIFEXITED(status) && !WIFSIGNALED(status) && !WIFSTOPPED(status)) {
                wpid = waitpid(pid, &status, WUNTRACED);
            }
        }
        // Background process
        else {
            // Register signal handler for child termination
            signal(SIGCHLD, sigchildHandler);
            printf("%d\n", pid); // Print the PID of the background process
        }
    }
}