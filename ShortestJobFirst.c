// sjf.c
// Kelvin Ngeno | AIT 542 – Fundamentals of Computing Platforms
// CPU Scheduling: Shortest Job First (Non-preemptive)

#include <stdio.h>

int main() {
    int n, i, j, pos, temp;
    float avg_wait = 0, avg_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], waiting[n], turnaround[n], process[n];

    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst[i]);
        process[i] = i + 1;
    }

    // Sort processes by burst time
    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (burst[j] < burst[pos])
                pos = j;
        }

        temp = burst[i];
        burst[i] = burst[pos];
        burst[pos] = temp;

        temp = process[i];
        process[i] = process[pos];
        process[pos] = temp;
    }

    waiting[0] = 0; // First process waiting time = 0

    // Calculate waiting time
    for (i = 1; i < n; i++) {
        waiting[i] = 0;
        for (j = 0; j < i; j++)
            waiting[i] += burst[j];
    }

    // Calculate turnaround time
    for (i = 0; i < n; i++)
        turnaround[i] = burst[i] + waiting[i];

    printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", process[i], burst[i], waiting[i], turnaround[i]);
        avg_wait += waiting[i];
        avg_turnaround += turnaround[i];
    }

    printf("\nAverage Waiting Time: %.2f", avg_wait / n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround / n);

    return 0;
}