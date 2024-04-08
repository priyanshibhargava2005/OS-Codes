#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Dynamic memory allocation for arrays
    int *burst = (int *)malloc(n * sizeof(int));
    int *priority = (int *)malloc(n * sizeof(int));
    int *index = (int *)malloc(n * sizeof(int));

    // Input burst times and priorities
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &burst[i], &priority[i]);
        index[i] = i + 1;
    }

    // Sort processes based on priority
    for (int i = 0; i < n; i++)
    {
        int temp = priority[i], m = i;
        for (int j = i; j < n; j++)
        {
            if (priority[j] > temp)
            {
                temp = priority[j];
                m = j;
            }
        }
        swap(&priority[i], &priority[m]);
        swap(&burst[i], &burst[m]);
        swap(&index[i], &index[m]);
    }

    // Calculate waiting time and display process execution order
    printf("\nOrder of process execution is:\n");
    int wait_time = 0;
    int total_wait_time = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d is executed from %d to %d\n", index[i], wait_time, wait_time + burst[i]);
        total_wait_time += wait_time;
        wait_time += burst[i];
    }

    printf("\nProcess Id\tBurst Time\tWait Time\n");
    int total_turn_around = 0;
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\n", index[i], burst[i], total_wait_time);
        total_turn_around += burst[i];
        total_wait_time -= burst[i];
    }

    float avg_wait_time = n > 0 ? (float)total_wait_time / n : 0; // Handling division by zero
    printf("\nAverage waiting time is %.2f\n", avg_wait_time);

    float avg_turn_around = n > 0 ? (float)total_turn_around / n : 0; // Handling division by zero
    printf("Average Turnaround Time is %.2f\n", avg_turn_around);

    // Free dynamically allocated memory
    free(burst);
    free(priority);
    free(index);

    return 0;
}
