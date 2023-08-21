#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t br, wr, cr;
int seats, cust = 0;

void *barber()
{
    while (1)
    {
        printf("\nBarber is Sleeping");
        sem_wait(&cr);
        if (cust > 0)
        {
            printf("\nBarber Wakes Up");
            sem_wait(&wr);
            seats++;
            sem_post(&br);
            printf("\nBarber is Cutting Hair");
            sem_post(&wr);
            sleep(5);
        }
        else
        {
            sleep(5);
        }
    }
}

void *customer()
{
    sem_wait(&wr);
    if (seats > 0)
    {
        cust++;
        seats--;
        printf("\nCustomer Enters");
        sem_post(&cr);
        printf("\nCustomer is Waiting");
        sleep(5);
        sem_post(&wr);
        sem_wait(&br);
        sleep(5);
        cust--;
        printf("\nCustomer Leaves");
    }
    else
    {
        printf("\nNo Seats Available, Customer Leaves");
        sem_post(&wr);
    }
}

int main()
{
    int i, n;
    printf("Enter Number of Seats : ");
    scanf("%d", &seats);
    printf("Enter Number of Customers : ");
    scanf("%d", &n);
    printf("\nBarber is Sleeping");
    sem_init(br, 0, 0); // Barber - Sleeping
    sem_init(wr, 0, 1);
    sem_init(cr, 0, 0); // No Customers
    pthread_t b, c[n];
    pthread_create(&b, NULL, &barber, NULL);
    for (i = 0; i < n; i++)
        pthread_create(&c[i], NULL, &customer, NULL);
    for (i = 0; i < n; i++)
        pthread_join(c[i], NULL);
    pthread_join(b, NULL);
    printf("\nBarber is Sleeping");
}