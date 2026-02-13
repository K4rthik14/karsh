#include <stdio.h>
#include <string.h>
#include "scheduler.h"

void schedule_simulator(char *type) {

    Process p[] = {
        {"P1", 4},
        {"P2", 3},
        {"P3", 5}
    };

    int n = 3;

    if (strcmp(type, "fcfs") == 0) {
        int time = 0;
        int total_wait = 0;

        printf("FCFS Scheduling:\n");

        for (int i = 0; i < n; i++) {
            printf("%s runs from %d to %d\n",
                   p[i].name, time, time + p[i].burst);

            total_wait += time;
            time += p[i].burst;
        }

        printf("Average waiting time: %d\n", total_wait / n);
    }
    else {
        printf("Unknown scheduler type: %s\n", type);
    }
}
