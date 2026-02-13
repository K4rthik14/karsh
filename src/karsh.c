#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#include "explain.h"
#include "scheduler.h"
#define MAX_LINE 1024
#define MAX_ARGS 64


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


