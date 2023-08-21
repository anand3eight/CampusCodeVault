// Dining Philosophers - Using Semaphoress
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define THINKING 0
#define HUNGRY 1
#define EATING 2
sem_t mutex, s[5];
int state[5];

void test(int i)
{
    if ((state[i] == HUNGRY) && (state[(i + 4) % 5] != EATING) && (state[(i + 1) % 5] != EATING))
    {
        state[i] = EATING;
        printf("\nPhilosopher %d is Eating with Forks with %d and %d", (i + 1), ((i + 4) % 5) + 1, (i + 1));
        sleep(2);
        sem_post(&s[i]); // Signal() Function
    }
}

void pickUp(int i)
{
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("\nPhilosopher %d is Hungry", (i + 1));
    test(i);
    sem_post(&mutex);
    if (state[i] != EATING)
        sem_wait(&s[i]);
    sleep(1);
}

void putDown(int i)
{
    sem_wait(&mutex);
    state[i] = THINKING;
    test((i + 4) % 5);
    test((i + 1) % 5);
    sem_post(&mutex);
}

void *philosopher(int *num)
{
    while (1)
    {
        int i = *num;
        sleep(1);
        pickUp(i);
        sleep(2);
        putDown(i);
        printf("\nPhilosopher %d is Thinking and puts Down Forks %d and %d", (i + 1), ((i + 4) % 5) + 1, (i + 1));
    }
}

int main()
{
    int i, phil[5] = {0, 1, 2, 3, 4};
    pthread_t threadID[5];
    sem_init(&mutex, 0, 1);
    for (i = 0; i < 5; i++)
    {
        sem_init(&s[i], 0, 0); // 0 - THINKING
    }
    for (i = 0; i < 5; i++)
    {
        pthread_create(&threadID[i], NULL, &philosopher, &phil[i]);
        printf("\nPhilosopher %d is Thinking", (i + 1));
    }
    for (i = 0; i < 5; i++)
        pthread_join(threadID[i], NULL);
    return 0;
}