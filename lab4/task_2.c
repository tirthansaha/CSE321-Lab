#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define MaxCrops 5 // Maximum crops a Farmer can produce or a Shopowner can take
#define warehouseSize 5 // Size of the warehouse
sem_t empty;
sem_t full;
char crops[warehouseSize] = {'R', 'W', 'P', 'S', 'M'}; 
char warehouse[warehouseSize] = {'N', 'N', 'N', 'N', 'N'}; 
pthread_mutex_t mutex; //A mutex (mutex) is declared to protect critical sections of code where shared resources are accessed

void *Farmer(void *far) {
    int id = *((int *) far) - 1; // Farmer's id to index (subtracts 1 to convert it to a zero-based index)
    sem_wait(&empty); //Waits on the empty semaphore. If the warehouse has available space, the farmer can proceed
    pthread_mutex_lock(&mutex);

    // Farmer puts a specific crop in its designated room
    warehouse[id] = crops[id];
    printf("Farmer %d: Insert crops %c at %d\n", id + 1, warehouse[id], id);

    pthread_mutex_unlock(&mutex);
    sem_post(&full);

    pthread_mutex_lock(&mutex);
    printf("Farmer%d: ", id + 1);
    for (int j = 0; j < warehouseSize; j++) {
        printf("%c", warehouse[j]);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *ShopOwner(void *sho) {
    int id = *((int *) sho) - 1; // ShopOwner's id to index
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    // Shop owner takes a crop from the specific room
    if (warehouse[id] != 'N') {
        printf("Shop Owner %d: Remove crops %c from %d\n", id + 1, warehouse[id], id);
        warehouse[id] = 'N';
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);

    pthread_mutex_lock(&mutex);
    printf("ShopOwner%d: ", id + 1);
    for (int j = 0; j < warehouseSize; j++) {
        printf("%c", warehouse[j]);
    }
    printf("\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {  //arrays of thread identifiers (Far and Sho) are declared. Mutex and semaphores are initialized
    pthread_t Far[5], Sho[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, warehouseSize);
    sem_init(&full, 0, 0);

    int a[5] = {1, 2, 3, 4, 5}; //a is initialized with values 1 to 5, representing Farmer and ShopOwner IDs

    for (int i = 0; i < 5; i++) {
        pthread_create(&Far[i], NULL, Farmer, (void *) &a[i]); //Threads for Farmers and ShopOwners are created using pthread_create
        pthread_create(&Sho[i], NULL, ShopOwner, (void *) &a[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(Far[i], NULL); //The main function waits for all threads to finish using pthread_join
        pthread_join(Sho[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}