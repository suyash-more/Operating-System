#include <stdio.h>
#include <pthread.h>

int full = 0;
int mutex = 1;
int empty = 1;

void wait(int *s)
{
    while ((*s) <= 0)
        (*s)--;
}

void signal(int *s)
{
    (*s)++;
}

void *consumer(void *args)
{
    wait(&full);
    wait(&mutex);
    printf("Consumer\n");
    signal(&mutex);
    signal(&empty);
    return NULL;
}

void *producer(void *args)
{
    wait(&empty);
    wait(&mutex);
    printf("Producer\n");
    signal(&mutex);
    signal(&full);
    return NULL;
}

int main()
{
    pthread_t p, c;
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    (void)pthread_join(c, NULL);
    (void)pthread_join(p, NULL);
}