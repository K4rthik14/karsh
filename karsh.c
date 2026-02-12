#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

int main()
{
	char input[MAX_LINE];
	char *args[MAX_ARGS];

	while(1)
	{
		//print prompt
		printf("karsh>");
		fflush(stdout);
		
		//To read input
		if(fgets(input,MAX_LINE, stdin)==NULL)
		{
			break;
		}
		
		//To Remove newline
		input[strcspn(input,"\n")]==0;

		//Exit Builtin
		if(strcmp(input,"exit")==0)
			printf("Exiting karsh ....\n");
			break;
	}
	//parse input into arguments
	int i = 0;
	args[i] = strtok(input, " ");
	while(args[i] != NULL)
	{
		i++;
		args[i]= strtok(NULL, " ");

	}
	//Fork Process
	pid_t pid = fork();

	if(pid == 0 )
	{
		//child process
		execvp(args[0],args);
		perror("exec failed");
		exit(1);

	}
	else if (pid > 0)
	{	
		//for parent process
		wait(NULL);
	}else
	{
		perror("fork failed");

	}
	return 0;
}
