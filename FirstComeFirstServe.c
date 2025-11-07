// fcfs.c
// Kelvin Ngeno | AIT 542 – Fundamentals of Computing Platforms
// CPU Scheduling: First Come, First Served (Non-preemptive)

#include <stdio.h>

int main() {
    int n, i;
    float avg_wait = 0, avg_turnaround = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst[n], waiting[n], turnaround[n];

    printf("Enter Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    // Waiting time for first process is always 0
    waiting[0] = 0;

    // Calculate waiting times
    for (i = 1; i < n; i++) {
        waiting[i] = 0;
        for (int j = 0; j < i; j++)
            waiting[i] += burst[j];
    }

    // Calculate turnaround times
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