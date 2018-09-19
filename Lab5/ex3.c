#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFF_SIZE 10

FILE *log_file;
int buffer[10];
int N;
bool producer_sleep, consumer_sleep;

void *producer(void *args)
{
    for (int i = 0; i < BUFF_SIZE * 2; i++)
    {
        if (N >= BUFF_SIZE)
        {
            printf("Producer goes to sleep.\n");
            producer_sleep = true;
        }
        if (N > 0 && consumer_sleep)
        {
            printf("Consumer is awaken.\n");
            consumer_sleep = false;
        }
        while (producer_sleep);

        buffer[N] = i;
        N++;
    }
    pthread_exit(0);
}

void *consumer(void *args)
{
    for (int i = 0; i < BUFF_SIZE * 3; i++)
    {
        if (N <= 0)
        {
            printf("Consumer goes to sleep.\n");
            consumer_sleep = true;
        }
        if (N < BUFF_SIZE && producer_sleep)
        {
            printf("Producer is awaken.\n");
            producer_sleep = false;
        }
        while (consumer_sleep);

        int result = buffer[N];
        N--;
    }
    pthread_exit(0);
}

int main()
{
    log_file = fopen("log.txt", "w");
    pthread_t producer_thread, consumer_thread;
    printf("Launching threads\n");
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    exit(0);
}