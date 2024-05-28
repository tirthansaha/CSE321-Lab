#include <stdio.h>

typedef struct {
    int arrival, burst, prio, CT, TAT, WT, id;
} Process;

void sort_by_priority(Process *procs, int count) { //takes an array of Process and sorts them based on their priority in ascending order using the bubble sort algorithm
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (procs[j].prio > procs[j + 1].prio) {
                Process temp = procs[j];
                procs[j] = procs[j + 1];
                procs[j + 1] = temp;
            }
        }
    }
}

void sort_by_id(Process *procs, int count) { //sorts the array of Process structures based on their process ID in ascending order
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (procs[j].id > procs[j + 1].id) {
                Process temp = procs[j];
                procs[j] = procs[j + 1];
                procs[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numProcs, currentTime = 0, completed = 0;
    float totalTAT = 0, totalWT = 0;

    printf("no. of process: ");
    scanf("%d", &numProcs);

    Process processes[numProcs]; //store information about each process and their remaining burst times
    int remainingBurst[numProcs];

    for (int i = 0; i < numProcs; i++) {
        printf("arrival time for P%d: ", i + 1);
        scanf("%d", &processes[i].arrival);
        printf("burst time for P%d: ", i + 1);
        scanf("%d", &processes[i].burst);
        printf("priority for P%d: ", i + 1);
        scanf("%d", &processes[i].prio);
        processes[i].id = i + 1;
        remainingBurst[i] = processes[i].burst; //remaining burst time are updated
    }

    while (completed != numProcs) {  // loop implements priority-based scheduling
        sort_by_priority(processes, numProcs);
        int executed = 0;
        for (int i = 0; i < numProcs; i++) {
            if (processes[i].arrival <= currentTime && processes[i].burst > 0) {
                processes[i].burst--;
                currentTime++;
                executed = 1;
                if (processes[i].burst == 0) {
                    processes[i].CT = currentTime;
                    completed++;
                }
                break;
            }
        }
        if (!executed) {
            currentTime++;
        }
    }

    sort_by_id(processes, numProcs);

    for (int i = 0; i < numProcs; i++) { //loop calculates and prints turnaround time (TAT) and waiting time (WT) for each process
        processes[i].TAT = processes[i].CT - processes[i].arrival;
        processes[i].WT = processes[i].TAT - remainingBurst[i];
        totalTAT += processes[i].TAT;
        totalWT += processes[i].WT;

        printf("Process %d: || Burst Time = %d || Completion Time (CT) = %d || Turnaround Time (TAT) = %d || Waiting Time (WT) = %d\n",
               processes[i].id, remainingBurst[i], processes[i].CT, processes[i].TAT, processes[i].WT);
    }
    return 0;
}