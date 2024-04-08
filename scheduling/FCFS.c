#include <stdio.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void calculateCompletionTime(struct Process processes[], int num_processes) {
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}

void calculateWaitingTime(struct Process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = processes[i].completion_time - processes[i].arrival_time - processes[i].burst_time;
    }
}

void calculateTurnaroundTime(struct Process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

void displayProcessDetails(struct Process processes[], int num_processes) {
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[num_processes];
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
    }

    calculateCompletionTime(processes, num_processes);
    calculateWaitingTime(processes, num_processes);
    calculateTurnaroundTime(processes, num_processes);
    
    printf("Process details:\n");
    displayProcessDetails(processes, num_processes);

    for (int i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average waiting time: %.2f\n", total_waiting_time / num_processes);
    printf("Average turnaround time: %.2f\n", total_turnaround_time / num_processes);

    return 0;
}
