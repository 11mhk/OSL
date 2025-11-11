#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process - descending sort
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (arr[i] < arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }

        printf("\n[Child PID %d] Descending order: ", getpid());
    } else {
        // Parent process - ascending sort
        wait(NULL);
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }

        printf("\n[Parent PID %d] Ascending order: ", getpid());
    }

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

PART2
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if(pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if(pid > 0) {
        printf("Parent (PID: %d) exiting now...\n", getpid());
        exit(0);
    } else {
        sleep(3); // Give parent time to die
        printf("Child (PID: %d) now adopted by init (new PPID: %d)\n", getpid(), getppid());
    }

    return 0;
}

PART 3 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if(pid < 0) {
        perror("fork failed");
        exit(1);
    }

    if(pid == 0) {
        printf("Child (PID: %d) exiting...\n", getpid());
        exit(0);
    } else {
        printf("Parent (PID: %d) sleeping... Check 'ps' to see zombie child.\n", getpid());
        sleep(10); // parent sleeps, child already exited
        printf("Parent now calling wait() to clean up.\n");
        wait(NULL);
    }

    return 0;
}
