// round_robin.c
// Kelvin Ngeno | AIT 542 – Fundamentals of Computing Platforms
// CPU Scheduling: Round Robin (Preemptive)

#include <stdio.h>

int main() {
    int n, quantum, i;
    float avg_wait = 0, avg_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], remaining[n], waiting[n], turnaround[n];
    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int time = 0;
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    waiting[i] = time - burst[i];
                    remaining[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }

    for (i = 0; i < n; i++)
        turnaround[i] = burst[i] + waiting[i];

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
        avg_wait += waiting[i];
        avg_turnaround += turnaround[i];
    }

    printf("\nAverage Waiting Time: %.2f", avg_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround / n);

    return 0;
}