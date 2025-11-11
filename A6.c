#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, wrt;          // Semaphores
int shared_var = 99;       // Shared variable
int reader_count = 0;      // Number of readers
int n;                     // Number of readers and writers

// ---------------- Reader Function ----------------
void reader() {
    sem_wait(&mutex);           // Lock mutex before updating count
    reader_count++;

    if (reader_count == 1)
        sem_wait(&wrt);         // First reader blocks writers

    sem_post(&mutex);           // Unlock mutex

    printf("\nReader is reading shared_var = %d", shared_var);
    sleep(1);
    printf("\nReader finished reading");

    sem_wait(&mutex);
    reader_count--;

    if (reader_count == 0)
        sem_post(&wrt);         // Last reader allows writers

    sem_post(&mutex);
}

// ---------------- Writer Function ----------------
void writer() {
    printf("\nWriter is trying to enter");
    sem_wait(&wrt);             // Wait for exclusive access

    shared_var++;
    printf("\nWriter entered CS and changed shared_var to %d", shared_var);
    sleep(1);
    printf("\nWriter leaving CS");

    sem_post(&wrt);             // Release access
}

// ---------------- Main Function ----------------
int main() {
    int i;
    pthread_t rthread[100], wthread[100];

    printf("Enter number of readers and writers: ");
    scanf("%d", &n);

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (i = 0; i < n; i++) {
        pthread_create(&rthread[i], NULL, (void*)reader, NULL);
        pthread_create(&wthread[i], NULL, (void*)writer, NULL);
    }

    for (i = 0; i < n; i++) {
        pthread_join(rthread[i], NULL);
        pthread_join(wthread[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    printf("\nAll readers and writers have finished.\n");
    return 0;
}






#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5   // Maximum size of the buffer

int buffer[BUFFER_SIZE];
int in = 0, out = 0;   // Indexes for producer and consumer

sem_t mutex;   // Controls access to buffer
sem_t empty;   // Counts empty slots
sem_t full;    // Counts filled slots

// ---------------- PRODUCER FUNCTION ----------------
void* producer() {
    int item;
    for (int i = 1; i <= 5; i++) {       // Produce 5 items
        item = i;                        // Simple item (just a number)

        sem_wait(&empty);                // Wait if buffer is full
        sem_wait(&mutex);                // Lock the buffer

        buffer[in] = item;
        printf("Producer produced item %d\n", item);
        in = (in + 1) % BUFFER_SIZE;     // Circular buffer

        sem_post(&mutex);                // Unlock buffer
        sem_post(&full);                 // Increase count of full slots

        sleep(1);                        // Simulate time delay
    }
    return NULL;
}

// ---------------- CONSUMER FUNCTION ----------------
void* consumer() {
    int item;
    for (int i = 1; i <= 5; i++) {       // Consume 5 items
        sem_wait(&full);                 // Wait if buffer is empty
        sem_wait(&mutex);                // Lock the buffer

        item = buffer[out];
        printf("Consumer consumed item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;   // Circular buffer

        sem_post(&mutex);                // Unlock buffer
        sem_post(&empty);                // Increase count of empty slots

        sleep(2);                        // Simulate time delay
    }
    return NULL;
}

// ---------------- MAIN FUNCTION ----------------
int main() {
    pthread_t prod, cons;

    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Create one producer and one consumer
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    printf("\nAll items produced and consumed successfully.\n");
    return 0;
}
