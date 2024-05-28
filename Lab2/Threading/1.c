#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5

void run_thread(voidarg) {
    int num = (int)arg;
    printf("Thread- %d running\n", num);
    free(num);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];

    for (int index = 0; index < THREAD_COUNT; index++) {
        intarg = malloc(sizeof(*arg));
        if (arg == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        *arg = index;
        pthread_create(&threads[index], NULL, run_thread, arg);
        pthread_join(threads[index], NULL);
        printf("Thread- %d closed\n", index + 1);
    }

    return 0;
}