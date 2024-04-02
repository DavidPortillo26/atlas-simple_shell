#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/dir.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <wait.h>
#include <ctype.h>

int execFlag;
int no_args;
int is_bg;
int no_cmds;
char *args[512];
char current_directory[1000];
char temp[1024];
char *cmd_exec;
char input_buffer[1024];
char *cmds[512];
char path[1024];
char cwd[1024];
char his_var[2000];
int flag, len;

void check_ls();

void remindme_command();

void clock_command(char *s);

void execCommand();

char* int_to_string(int pid);

void split_cmds();

void split_args(char *s);

void builtin(char *s);

void clear_variables1();

void clear_variables2();

void cust_pwd();

void prompt();

void ls_command();

void lsa_command();

void lsl_command();

void lsal_command();

void pinfo_command();

void sigintHandler(int sig_num);

void alarmHandler(int sig_num);