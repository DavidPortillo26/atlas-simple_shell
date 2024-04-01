#include "main.h"

// Function to handle termination of child processes
void sigchildHandler(int signal) {
    // Handle termination of child process here
}

// Function to execute system commands
void execCommand() {
    int status;
    pid_t pid, wpid;

    // Check if the command is to be executed in the background
    if (strcmp(args[no_args - 1], "&") == 0) {
        is_bg = 1;
        args[no_args - 1] = NULL;
    }
