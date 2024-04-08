#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void sjf(Process processes[], int n) {
    int time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("Shortest Job First (SJF) Scheduling:\n");
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");

    while (1) {
        int shortest_burst_time = INT_MAX;
        int shortest_burst_time_index = -1;

        for (int i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].arrival_time <= time &&
                processes[i].burst_time < shortest_burst_time) {
                shortest_burst_time = processes[i].burst_time;
                shortest_burst_time_index = i;
            }
        }

        if (shortest_burst_time_index == -1)
            break;

        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[shortest_burst_time_index].id,
               processes[shortest_burst_time_index].arrival_time,
               processes[shortest_burst_time_index].burst_time,
               time + processes[shortest_burst_time_index].burst_time,
               time - processes[shortest_burst_time_index].arrival_time,
               time + processes[shortest_burst_time_index].burst_time - processes[shortest_burst_time_index].arrival_time);

        total_waiting_time += time - processes[shortest_burst_time_index].arrival_time;
        total_turnaround_time += time + processes[shortest_burst_time_index].burst_time - processes[shortest_burst_time_index].arrival_time;

        time += processes[shortest_burst_time_index].burst_time;
        processes[shortest_burst_time_index].burst_time = 0;
    }

    double avg_waiting_time = (double)total_waiting_time / n;
    double avg_turnaround_time = (double)total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2lf\n", avg_turnaround_time);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Number of processes exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process %d (Arrival Time): ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Process %d (Burst Time): ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    sjf(processes, n);

    return 0;
}
