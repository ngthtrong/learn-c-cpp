#include <stdio.h>
#include <pthread.h>
#include "queuelib.h"

#define MAX_CAPACITY 10 // S?c ch?a t?i ða c?a kho
#define NUM_PRODUCERS 3 // S? lý?ng producers
#define NUM_CONSUMERS 2 // S? lý?ng consumers

CircularQueue warehouse; // Kho d?a trên hàng ð?i
pthread_mutex_t warehouseLock; // Mutex ð? b?o v? kho
pthread_cond_t notFull, notEmpty; // Bi?n ði?u ki?n

// Hàm producer (ngý?i s?n xu?t)
void* producer(void* arg) {
    int item = 1;

    while (1) {
        pthread_mutex_lock(&warehouseLock);
        if (isFull(warehouse)) {
            printf("Producer waits. Warehouse is full.\n");
            pthread_cond_wait(&notFull, &warehouseLock);
        }
        enQueue(item, &warehouse);
        printf("Produced item: %d\n", item);
        item++;
        pthread_cond_signal(&notEmpty);
        pthread_mutex_unlock(&warehouseLock);
    }
}

// Hàm consumer (ngý?i tiêu dùng)
void* consumer(void* arg) {
    while (1) {
        pthread_mutex_lock(&warehouseLock);
        if (isEmpty(warehouse)) {
            printf("Consumer waits. Warehouse is empty.\n");
            pthread_cond_wait(&notEmpty, &warehouseLock);
        }
        int item = deQueue(&warehouse);
        printf("Consumed item: %d\n", item);
        pthread_cond_signal(&notFull);
        pthread_mutex_unlock(&warehouseLock);
    }
}

int main() {
	int i; 
    makeNull(&warehouse);
    pthread_mutex_init(&warehouseLock, NULL);
    pthread_cond_init(&notFull, NULL);
    pthread_cond_init(&notEmpty, NULL);

    pthread_t producerThreads[NUM_PRODUCERS];
    pthread_t consumerThreads[NUM_CONSUMERS];

    for (i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&producerThreads[i], NULL, producer, NULL);
    }

    for (i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumerThreads[i], NULL, consumer, NULL);
    }

    for (i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producerThreads[i], NULL);
    }

    for (i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumerThreads[i], NULL);
    }

    pthread_mutex_destroy(&warehouseLock);
    pthread_cond_destroy(&notFull);
    pthread_cond_destroy(&notEmpty);

    return 0;
}

