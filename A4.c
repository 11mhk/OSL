#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], st[n], ct[n], tat[n], wt[n], started[n];
    float awt = 0.0, avgtat = 0.0;

    // Gantt chart arrays
    int gantt_proc[200], gantt_time[200], gantt_count = 0;
    int prev_proc = -1;

    // Input
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];       // Remaining time = burst initially
        started[i] = 0;      // Not started yet
    }

    int completed = 0;
    int current_time = 0;

    // Main loop: run until all processes complete
    while (completed != n) {
        int idx = -1;        // index of the shortest remaining process
        int min_rt = INT_MAX;

        // Find the process with the shortest remaining time among arrived ones
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                idx = i;
            }
        }

        // If no process is ready, CPU is idle
        if (idx == -1) {
            if (prev_proc != 0) { // mark IDLE only once
                gantt_proc[gantt_count] = 0;
                gantt_time[gantt_count] = current_time;
                gantt_count++;
                prev_proc = 0;
            }
            current_time++;
            continue;
        }

        // Record the start time the first time the process gets CPU
        if (started[idx] == 0) {
            st[idx] = current_time;
            started[idx] = 1;
        }

        // If CPU switches to another process, record it in Gantt chart
        if (prev_proc != (idx + 1)) {
            gantt_proc[gantt_count] = idx + 1;
            gantt_time[gantt_count] = current_time;
            gantt_count++;
            prev_proc = idx + 1;
        }

        // Execute process for 1 unit of time
        rt[idx]--;
        current_time++;

        // If the process finishes
        if (rt[idx] == 0) {
            completed++;
            ct[idx] = current_time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            awt += wt[idx];
            avgtat += tat[idx];
        }
    }

    gantt_time[gantt_count] = current_time;

    // Calculate averages
    awt /= n;
    avgtat /= n;

    // Output results in table
    printf("\n\n--- Preemptive SJF (Shortest Remaining Time First) ---\n");
    printf("-------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tST\tCT\tWT\tTAT\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], st[i], ct[i], wt[i], tat[i]);
    }
    printf("-------------------------------------------------------------\n");
    printf("Average Waiting Time     = %.2f\n", awt);
    printf("Average Turnaround Time  = %.2f\n", avgtat);

    // Display Gantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < gantt_count; i++) {
        printf("|");
        if (gantt_proc[i] == 0)
            printf(" IDLE ");
        else
            printf(" P%d ", gantt_proc[i]);
    }
    printf("|\n");

    for (int i = 0; i <= gantt_count; i++) {
        printf("%-5d", gantt_time[i]);
    }
    printf("\n");

    return 0;
}

