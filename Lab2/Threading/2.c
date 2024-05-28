#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 5
#define NUM_PRINTS 5

void *print_numbers(void *threadid) {
    long tid = (long)threadid;
    int start = tid * NUM_PRINTS + 1;
    for (int i = 0; i < NUM_PRINTS; i++) {
        printf("Thread %ld prints %d\n", tid, start + i);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, print_numbers, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            return -1;
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    return 0;
}