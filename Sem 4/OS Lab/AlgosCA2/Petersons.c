#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int flag[2] = {0, 0};
int turn = 0;

void *fun(int *num)
{
    int i = *num;
    printf("\nProcess %d Comes", i);
    flag[i] = 1;
    turn = 1 - i;
    while (turn == 0 && flag[1 - i])
        ;
    printf("\nProcess %d in Critical Section", i);
    sleep(5);
    flag[i] = 0;
    printf("\nProcess %d leaves", i);
}

int main()
{
    pthread_t t1, t2;
    int zero = 0, one = 1;
    pthread_create(&t1, NULL, &fun, &zero);
    pthread_create(&t2, NULL, &fun, &one);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}