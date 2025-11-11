#include <stdio.h>
#include <stdlib.h>

// Function to sort processes based on Arrival Time (AT)
void sort(int at[], int bt[], int process[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp;

                // Swap arrival times
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process numbers
                temp = process[j];
                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], st[n], process[n];
    float avgwt = 0.0, avgtat = 0.0;

    // Input section
        for (int i = 0; i < n; i++) {
            process[i] = i + 1;
        printf("Enter arrival time for P%d: ", process[i]);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", process[i]);
        scanf("%d", &bt[i]);
    }

    // Sort processes by arrival time
    sort(at, bt, process, n);

    // First process
    st[0] = at[0];
    ct[0] = st[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    avgwt += wt[0];
    avgtat += tat[0];

    // Remaining processes
    for (int i = 1; i < n; i++) {
        if (at[i] > ct[i - 1]) {
            st[i] = at[i]; // CPU idle until this process arrives
        } else {
            st[i] = ct[i - 1]; // starts immediately after previous one
        }
        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgwt += wt[i];
        avgtat += tat[i];
    }

    // Calculate averages
    avgwt /= n;
    avgtat /= n;

    // Print results in a clean table format
    printf("\n\n-------------------------------------------------------------\n");
    printf("Process\tAT\tBT\tST\tCT\tWT\tTAT\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               process[i], at[i], bt[i], st[i], ct[i], wt[i], tat[i]);
    }
    printf("-------------------------------------------------------------\n");

    // Display averages
    printf("Average Waiting Time     = %.2f\n", avgwt);
    printf("Average Turnaround Time  = %.2f\n", avgtat);

    // Gantt chart
    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf("  P%d  |", process[i]);
    }

    printf("\n%d", at[0]);
    for (int i = 0; i < n; i++) {
        printf("     %d", ct[i]);
    }
    printf("\n");

    return 0;
}


