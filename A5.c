#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];               // fd[0] - read end, fd[1] - write end
    pid_t pid;
    char write_msg[100];
    char read_msg[100];

    // Create pipe
    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        exit(1);
    }

    // Create child process
    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        exit(1);
    }

    // ------------------ Parent Process ------------------
    if (pid > 0) {
        close(fd[0]);  // Close read end (parent only writes)

        printf("Parent: Enter a message to send to child: ");
        scanf(" %[^\n]", write_msg);  // Read message with spaces

        write(fd[1], write_msg, strlen(write_msg) + 1);  // Send to pipe
        close(fd[1]);  // Close write end

        wait(NULL);  // Wait for child
        printf("Parent: Child process completed.\n");
    }

    // ------------------ Child Process -------------------
    else {
        close(fd[1]);  // Close write end (child only reads)

        read(fd[0], read_msg, sizeof(read_msg));  // Read from pipe
        printf("Child: Received message from parent: %s\n", read_msg);

        close(fd[0]);  // Close read end
    }

    return 0;
}

