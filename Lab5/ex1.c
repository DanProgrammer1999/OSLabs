#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *run(void *args)
{
    int *id = (int *)args;
    printf("Message from thread %d\n", *id);
    pthread_exit(0);
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        pthread_t thread;
        int id = i;
        if (!pthread_create(&thread, NULL, run, &id))
        {
            pthread_join(thread, NULL);
            printf("Thread %i completed.\n", i);
        }
    }
    exit(0);
}