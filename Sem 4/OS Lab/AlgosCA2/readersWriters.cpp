// Readers Writers Problem using Semaphores
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex, write;
int rc = 0; // readercount
void *reader(void *arg)
{
    sem_wait(&mutex);
    printf("\nReader Enters");
    rc++;
    if (rc == 1)
        sem_wait(&write);
    sem_post(&mutex);
    printf("\nReader is Reading");
    sem_wait(&mutex);
    rc--;
    if (rc == 0)
        sem_post(&write);
    printf("\nReader is Leaving");
    sem_post(&mutex);
}

void *writer(void *arg)
{
    printf("\nWriter is Waiting");
    sem_wait(&write);
    printf("\nWriter is Writing");
    sem_post(&write);
    printf("\nWriter is leaving");
}
int main()
{
    int i, n;
    printf("Enter Number of Readers : ");
    scanf("%d", &n);
    pthread_t readers[n], writers[n];
    sem_init(&mutex, 0, 1);
    sem_init(&write, 0, 1);
    for (i = 0; i < n; i++)
    {
        pthread_create(&writers[i], NULL, &writer, NULL);
        pthread_create(&readers[i], NULL, &reader, NULL);
    }
    for (i = 0; i < n; i++)
    {
        pthread_join(writers[i], NULL);
        pthread_join(readers[i], NULL);
    }
    return 0;
}
