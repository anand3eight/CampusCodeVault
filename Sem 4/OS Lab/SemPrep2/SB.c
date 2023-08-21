#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
sem_t br, cr, wr;
int cust, seats;
void *barber()
{
    printf("\nBarber is Sleeping");
    sem_wait(&cr);
    if (cust > 0)
    {
        sem_post(&br);
        printf("\nBarber Wakes Up");
        sem_wait(&wr);
        seats++;
        sem_post(&wr);
        printf("\nBarber is Cutting Hair");
        sleep(5);
    }
    else
        sleep(5);
}

void *customer()
{
    sem_wait(&wr);
    if (seats > 0)
    {
        printf("\nCustomer Ready");
        sem_post(&cr);
        seats--;
        sleep(5);
        sem_post(&wr);
        sem_wait(&br);
        cust--;
        printf("\nCustomer Leaves");
    }
    else
    {
        sem_post(&wr);
        printf("\nNo Seats Available, Customer Leaves");
    }
}

int main()
{
    printf("\nEnter Cust and Seat Count : ");
    scanf("%d %d", &cust, &seats);
    pthread_t b, cu[cust];
    sem_init(&br, 0, 0);
    sem_init(&wr, 0, 1);
    sem_init(&cr, 0, 0);
    pthread_create(&b, NULL, &barber, NULL);
    for (int i = 0; i < cust; i++)
        pthread_create(&cu[i], NULL, &customer, NULL);
    for (int i = 0; i < cust; i++)
        pthread_join(cu[i], NULL);
    pthread_join(b, NULL);
    return 0;
}
