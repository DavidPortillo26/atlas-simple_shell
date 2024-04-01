#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int execFlag;
int no_args;
int is_bg;
char *args[512];
char current_directory[1000];
char temp[1024];
char *cmd_exec;