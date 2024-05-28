#include <stdio.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREAD_COUNT 3

void ascii_sum(voidarg) {
    char str = (char)arg;
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }
    int *result = malloc(sizeof(int));
    result = sum;
    return (void)result;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    char user_names[THREAD_COUNT] = {"cai00en", "eniac00", "altair00"};
    int sums[THREAD_COUNT];
    intret;

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, ascii_sum, (void )user_names[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], (void **)&ret);
        sums[i] =ret;
        free(ret);
    }

    int max_freq = 0;
    for (int i = 0; i < THREAD_COUNT; i++) {
        int count = 0;
        for (int j = 0; j < THREAD_COUNT; j++) {
            if (sums[i] == sums[j]) {
                count++;
            }
        }
        if (count > max_freq) {
            max_freq = count;
        }
    }
    switch (max_freq) {
        case 3:
            printf("Youreka\n");
            break;
        case 2:
            printf("Miracle\n");
            break;
        case 1:
            printf("Hasta la vista\n");
            break;
        default:
            printf("Error\n");
            break;
    }

    return 0;
}