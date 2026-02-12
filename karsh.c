#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

int main()
{
	char inputs[MAX_LINE];
	char *args[MAX_ARGS];

	while(1)
	{
		//print prompt
		printf("karsh>");
		fflush(stdout);
		
	}
}
