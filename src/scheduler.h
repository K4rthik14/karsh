#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct {
	char name[5];
	int burst;

}Process;

void scheduler_simulator(char *type);

#endif

