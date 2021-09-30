#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>

int readcnt = 0;
sem_t wrt;
pthread_mutex_t mutex;

void *reader(void *args)
{
    pthread_mutex_lock(&mutex);
    readcnt++;
    if (readcnt == 1)
    {
        sem_wait(&wrt);
    }
    pthread_mutex_unlock(&mutex);
    printf("Reader reading the file here..!!\n");
    pthread_mutex_lock(&mutex);
    readcnt--;
    if (readcnt == 0)
    {
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}

void *writer(void *args)
{
    sem_wait(&wrt);
    printf("\nWriter is writing in the file..!!\n");
    sem_post(&wrt);
}

int main()
{
    pthread_t wrt[3], read[3];
    sem_init(&wrt, 0, 1);
    pthread_mutex_init(&mutex, NULL);
    int a[3] = {1, 2, 3}; //Just used for numbering the producer and consumer

    for (int i = 0; i < 3; i++)
    {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&wrt[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        pthread_join(wrt[i], NULL);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_join(read[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}