#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *input()
{
    int *num = (int *)malloc(sizeof(int));
    printf("Enter : ");
    scanf("%d", num);
    pthread_exit(num);
}

void *fact(void *n)
{
    int *res = (int *)malloc(sizeof(int));
    res[0] = 1;
    int num = (int *)n;
    for (int i = 1; i <= num; i++)
    {
        res[0] *= i;
    }
    pthread_exit(res);
}

int main()
{
    pthread_t t1, t2;
    int *n1, *n2;
    pthread_create(&t1, NULL, &input, NULL);
    pthread_join(t1, (void **)&n1);
    pthread_create(&t2, NULL, &fact, *n1);
    pthread_join(t2, (void **)&n2);
    printf("Fact : %d ", *n2);
    return 0;
}