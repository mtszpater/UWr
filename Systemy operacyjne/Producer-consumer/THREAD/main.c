#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>
 
pthread_mutex_t mutex;              
sem_t isEmpty, isFull;        
int count = 0;      

void *producer() {
    while (1) {
        sem_wait(&isEmpty);
        pthread_mutex_lock(&mutex);
        printf("Wyprodukowalem, aktualna wielkosc magazynu: %d\n", ++count);
        pthread_mutex_unlock(&mutex);
        sem_post(&isFull);
	sleep(2);
    }
}

void *consumer() {
    while (1) {
        sem_wait(&isFull);
        pthread_mutex_lock(&mutex);
        printf("Pobralem, aktualna wielkosc magazynu: %d\n", --count);
        pthread_mutex_unlock(&mutex);
        sem_post(&isEmpty);
	sleep(2);
    }
}

int main() {

    pthread_mutex_init(&mutex, NULL);
    sem_init(&isEmpty, 0, 10);
    sem_init(&isFull, 0, 0);

    pthread_t threads[2];
    pthread_create(&threads[0], NULL, producer, NULL);
    pthread_create(&threads[1], NULL, consumer, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);


    return 0;
}
