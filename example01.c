#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Shared variable
int shared_data = 0;

// Thread function to increase shared data
void* increment(void* arg) {
    for (int i = 0; i < 10000; ++i) {
        shared_data++;
    }
    return NULL;
}

// Thread function to decrease shared data
void* decrement(void* arg) {
    for (int i = 0; i < 10000; ++i) {
        shared_data--;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create threads
    if (pthread_create(&thread1, NULL, &increment, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, &decrement, NULL)) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Print the shared data
    printf("Final shared data value: %d\n", shared_data);

    return 0;
}
