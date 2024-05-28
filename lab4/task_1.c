#include <pthread.h>   
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10 
#define BUFLEN 6
#define NUMTHREAD 2      

void * consumer(void *id); //Function prototypes for the producer and consumer functions are declared
void * producer(void *id);

char buffer[BUFLEN];
char source[BUFLEN+1]; 
int pCount = 0;
int cCount = 0;
int count = 0;      
int buflen;

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t nonEmpty  = PTHREAD_COND_INITIALIZER;
pthread_cond_t full  = PTHREAD_COND_INITIALIZER;
int thread_id[NUMTHREAD]  = {0,1};

int main() {
    pthread_t thread[NUMTHREAD];

    strcpy(source,"abcdef");
    buflen = strlen(source);

    int i = 0;
    while (i < NUMTHREAD) {
        if (i != 0) {
            pthread_create(&thread[i], NULL, consumer, (void *) &thread_id[i]); //array of threads is created, and the source data is initialized threads are then created and assigned either the producer or consumer
        }            
        else {
            pthread_create(&thread[i], NULL, producer, (void *) &thread_id[i]);
        }    
        i++;
    }
    i = 0;
    while (i < NUMTHREAD) {  // main function waits for all threads to finish using pthread_join, and then destroys the mutex and condition variables
        pthread_join(thread[i], NULL);
        i++;
    }
    pthread_mutex_destroy(&count_mutex);
    pthread_cond_destroy(&nonEmpty);
    pthread_cond_destroy(&full);
    return 0;
}

void * producer(void *id) { //producer function starts here, taking an ID as an argument and producing items for the shared buffer
    int i = 0;
    while (i < MAX) {
        pthread_mutex_lock(&count_mutex);

        while (count == BUFLEN) {
            pthread_cond_wait(&nonEmpty, &count_mutex);
        }
        buffer[pCount] = source[pCount % buflen];
        int f = buffer[pCount];
        int r = *((int *) id)
        printf("%d produced %c by Thread %d\n", i, f,);
        pCount = (pCount + 1) % BUFLEN;
        count++;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&count_mutex);
        i++;
    }
    return NULL;
}

void * consumer(void *id) { //consumer function starts here, taking an ID as an argument and consuming items from the shared buffer
    int k = 0;
    while (k < MAX) {
        pthread_mutex_lock(&count_mutex);

        while (count == 0) {
            pthread_cond_wait(&full, &count_mutex);
        }
        printf("%d consumed %c by Thread %d\n", k, buffer[cCount], *((int *) id));
        cCount = (cCount + 1) % BUFLEN;
        count--;
        pthread_cond_signal(&nonEmpty);
        pthread_mutex_unlock(&count_mutex);
        k++;
    }
    return NULL;
}