#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int flag[2] = {0, 0}, turn = 0;

void *ps(void *n)
{
    int i = *(int *)n;
    flag[i] = 1;
    turn = 1 - i;
    printf("\nP%d Enters", i);
    while (turn == 1 - i && flag[1 - i])
        ;
    printf("\nP%d in CS", i);
    sleep(5);
    flag[i] = 0;
    printf("\nP%d Leaves", i);
}
int main()
{
    pthread_t a, b;
    int i = 0, j = 1;
    pthread_create(&a, NULL, &ps, &i);
    pthread_create(&a, NULL, &ps, &j);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    return 0;
}