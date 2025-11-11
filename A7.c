#include <stdio.h>

int main() {
    int n, m; // n = processes, m = resource types
    int i, j, k;

    // Input number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];
    int finish[n], safeSeq[n], work[m];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++) scanf("%d", &alloc[i][j]);
    }

    // Input Max Matrix
    printf("\nEnter Max Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++) scanf("%d", &max[i][j]);
    }

    // Input Available resources
    printf("\nEnter Available Resources (size %d): ", m);
    for (i = 0; i < m; i++) scanf("%d", &avail[i]);

    // Calculate Need matrix = Max - Allocation
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Print Need matrix
    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    // Safety Algorithm
    for (i = 0; i < m; i++)
        work[i] = avail[i];
    for (i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;
    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int can_run = 1;
                for (j = 0; j < m; j++)
                    if (need[i][j] > work[j]) {
                        can_run = 0;
                        break;
                    }
                if (can_run) {
                    for (k = 0; k < m; k++)
                        work[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) break;
    }

    if (count == n) {
        printf("\nSystem is in a SAFE state.\nSafe Sequence: ");
        for (i = 0; i < n; i++) {
            printf("P%d", safeSeq[i]);
            if (i != n - 1) printf(" -> ");
        }
        printf("\n");
    } else {
        printf("\nSystem is NOT in a safe state.\n");
        return 0;
    }

    // Resource Request Algorithm
    while (1) {
        int p, req[m];
        printf("\nEnter process number to make a resource request (-1 to exit): ");
        scanf("%d", &p);

        if (p < 0 || p >= n) {
            printf("Exiting resource request section.\n");
            break;
        }

        printf("Enter request vector for P%d: ", p);
        for (i = 0; i < m; i++)
            scanf("%d", &req[i]);

        // Step 1: Check if request <= need
        int valid = 1;
        for (i = 0; i < m; i++) {
            if (req[i] > need[p][i]) {
                printf("Error: Request exceeds maximum need.\n");
                valid = 0;
                break;
            }
        }
        if (!valid) continue;

        // Step 2: Check if request <= available
        for (i = 0; i < m; i++) {
            if (req[i] > avail[i]) {
                printf("Resources not available. Process must wait.\n");
                valid = 0;
                break;
            }
        }
        if (!valid) continue;

        // Step 3: Pretend to allocate temporarily
        for (i = 0; i < m; i++) {
            avail[i] -= req[i];
            alloc[p][i] += req[i];
            need[p][i] -= req[i];
        }

        // Step 4: Run Safety Algorithm again
        for (i = 0; i < m; i++) work[i] = avail[i];
        for (i = 0; i < n; i++) finish[i] = 0;
        count = 0;

        while (count < n) {
            int found = 0;
            for (i = 0; i < n; i++) {
                if (!finish[i]) {
                    int can_run = 1;
                    for (j = 0; j < m; j++)
                        if (need[i][j] > work[j]) {
                            can_run = 0;
                            break;
                        }
                    if (can_run) {
                        for (k = 0; k < m; k++)
                            work[k] += alloc[i][k];
                        safeSeq[count++] = i;
                        finish[i] = 1;
                        found = 1;
                    }
                }
            }
            if (!found) break;
        }

        // Step 5: Check safe state after allocation
        if (count == n) {
            printf("\nRequest can be granted. System remains SAFE.\n");
            printf("New Safe Sequence: ");
            for (i = 0; i < n; i++) {
                printf("P%d", safeSeq[i]);
                if (i != n - 1) printf(" -> ");
            }
            printf("\n");
        } else {
            printf("\nRequest CANNOT be granted. System would become unsafe.\n");
            // Rollback
            for (i = 0; i < m; i++) {
                avail[i] += req[i];
                alloc[p][i] -= req[i];
                need[p][i] += req[i];
            }
        }
    }

    return 0;
}


//CODE WITH FUNCTIONS
#include <stdio.h>
#include <stdlib.h>

// Function to check if system is safe and return safe sequence
int checkSafety(int n, int m, int alloc[][m], int need[][m], int avail[], int safeSeq[]) {
    int work[m], finish[n];
    int i, j, k, count = 0;

    // Initialize work and finish arrays
    for (i = 0; i < m; i++)
        work[i] = avail[i];
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Find safe sequence
    while (count < n) {
        int found = 0;

        for (i = 0; i < n; i++) {
            if (finish[i])
                continue; // Skip finished processes

            // Check if process can run
            int canRun = 1;
            for (j = 0; j < m; j++) {
                if (need[i][j] > work[j]) {
                    canRun = 0;
                    break;
                }
            }

            if (canRun) {
                // Release resources
                for (k = 0; k < m; k++)
                    work[k] += alloc[i][k];
                safeSeq[count++] = i;
                finish[i] = 1;
                found = 1;
            }
        }

        if (!found)
            return 0; // Unsafe state
    }

    return 1; // Safe state
}

// Function to print safe sequence
void printSafeSeq(int safeSeq[], int n) {
    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("P%d", safeSeq[i]);
        if (i < n - 1)
            printf(" -> ");
    }
    printf("\n");
}

int main() {
    int n, m, i, j;

    // Input
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m], safeSeq[n];

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Input Max Matrix
    printf("\nEnter Max Matrix (%d x %d):\n", n, m);
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    // Input Available Resources
    printf("\nEnter Available Resources: ");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need Matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    // Print Need Matrix
    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    // Initial Safety Check
    if (checkSafety(n, m, alloc, need, avail, safeSeq)) {
        printf("\nSystem is SAFE.\n");
        printSafeSeq(safeSeq, n);
    } else {
        printf("\nSystem is UNSAFE.\n");
        return 0;
    }

    // Resource Request Loop
    while (1) {
        int p, req[m];

        printf("\nEnter process number (-1 to exit): ");
        scanf("%d", &p);

        if (p < 0 || p >= n)
            break;

        printf("Enter request for P%d: ", p);
        for (i = 0; i < m; i++)
            scanf("%d", &req[i]);

        // Validate request
        int valid = 1;
        for (i = 0; i < m; i++) {
            if (req[i] > need[p][i]) {
                printf("Error: Request exceeds need.\n");
                valid = 0;
                break;
            }
            if (req[i] > avail[i]) {
                printf("Resources unavailable. Wait.\n");
                valid = 0;
                break;
            }
        }

        if (!valid)
            continue;

        // Tentatively allocate
        for (i = 0; i < m; i++) {
            avail[i] -= req[i];
            alloc[p][i] += req[i];
            need[p][i] -= req[i];
        }

        // Check safety
        if (checkSafety(n, m, alloc, need, avail, safeSeq)) {
            printf("\nRequest GRANTED. System remains SAFE.\n");
            printSafeSeq(safeSeq, n);
        } else {
            printf("\nRequest DENIED. Would cause unsafe state.\n");

            // Rollback
            for (i = 0; i < m; i++) {
                avail[i] += req[i];
                alloc[p][i] -= req[i];
                need[p][i] += req[i];
            }
        }
    }

    return 0;
}
