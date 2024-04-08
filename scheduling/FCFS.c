#include <stdio.h>

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} Process;

int main() {
    int num_processes;
    printf("How many processes do you have? ");
    scanf("%d", &num_processes);

    if (num_processes <= 0) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    Process processes[num_processes];

    for (int i = 0; i < num_processes; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].id = i + 1;
    }

    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        current_time = processes[i].completion_time;
    }

    printf("\nProcess ID  Burst Time  Arrival Time  Completion Time  Turnaround Time  Waiting Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%-11d%-12d%-13d%-17d%-16d%-13d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, 
               processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    float average_waiting_time = total_waiting_time / num_processes;
    float average_turnaround_time = total_turnaround_time / num_processes;

    printf("\nAverage Waiting Time: %.2f", average_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", average_turnaround_time);

    return 0;
}
