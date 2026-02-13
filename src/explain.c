#include <stdio.h>
#include <string.h>
#include "explain.h"

void explain_command(char *topic) {

    if (strcmp(topic, "fork") == 0) {
        printf("fork(): creates a child process by duplicating the parent.\n");
        printf("KARSH uses fork() to create a new process for commands.\n");
    }
    else if (strcmp(topic, "exec") == 0) {
        printf("exec(): replaces the current process with a new program.\n");
        printf("KARSH uses execvp() to run Linux commands.\n");
    }
    else if (strcmp(topic, "cd") == 0) {
        printf("cd: changes the current working directory.\n");
        printf("It must run in the parent process, not a child.\n");
    }
    else if (strcmp(topic, "scheduler") == 0) {
        printf("CPU Scheduler decides which process runs next.\n");
        printf("Examples: FCFS, SJF, Round Robin.\n");
    }
    else {
        printf("No explanation available for '%s'\n", topic);
    }
}
