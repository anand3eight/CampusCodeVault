#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t w, m;
int rc = 0;
void *reader()
{
    printf("\nReader Enters");
    sem_wait(&m);
    if (++rc == 1)
        sem_wait(&w);
    sem_post(&m);
    printf("\nReader Reads");
    sem_wait(&m);
    if (--rc == 0)
        sem_post(&w);
    sem_post(&m);
    printf("\nReader Leaves");
}

void *writer()
{
    printf("\nWriter Waits");
    sem_wait(&w);
    printf("\nWriting");
    sem_post(&w);
    printf("\nWriter leaves");
}

int main()
{
    int c;
    sem_init(w, 0, 1);
    sem_init(m, 0, 1);
    printf("Enter Count : ");
    scanf("%d", &c);
    pthread_t re[c], wr[c];
    for (int i = 0; i < c; i++)
    {
        pthread_create(&wr[i], NULL, &writer, NULL);
        pthread_create(&re[i], NULL, &reader, NULL);
    }
    for (int i = 0; i < c; i++)
    {
        pthread_join(wr[i], NULL);
        pthread_join(re[i], NULL);
    }
    return 0;
}