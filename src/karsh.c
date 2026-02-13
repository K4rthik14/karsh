#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

void explain_command(char *topic);

int main() {
    char input[MAX_LINE];
    char *args[MAX_ARGS];

    while (1) {
        // Print prompt
        printf("karsh> ");
        fflush(stdout);

        // Read input
        if (fgets(input, MAX_LINE, stdin) == NULL) {
            break;
        }

        // Remove newline
        input[strcspn(input, "\n")] = 0;

        // Exit builtin
        if (strcmp(input, "exit") == 0) {
            printf("Exiting karsh...\n");
            break;
        }

	//Explain mode builtin
	if (strncmp(input, "explain ", 8) == 0)
	{	
		explain_command(input + 8);
 		continue;
	}

        // Parse input into arguments
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL) {
            i++;
            args[i] = strtok(NULL, " ");
        }

        // Fork process
        pid_t pid = fork();

        if (pid == 0) {
            // Child process
            execvp(args[0], args);
            perror("exec failed");
            exit(1);
        } else if (pid > 0) {
            // Parent process
            wait(NULL);
        } else {
            perror("fork failed");
        }
    }

    return 0;
}

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
