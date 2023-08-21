#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *input()
{
    char *num = (char *)malloc(sizeof(char) * 20);
    printf("Enter : ");
    scanf("%d", num);
    pthread_exit(num);
}

int main()
{
    pthread_t t1, t2;
    int *n1, *n2;
    pthread_create(&t1, NULL, &input, NULL);
    pthread_join(t1, (void **)&n1);
    pthread_create(&t2, NULL, &input, NULL);
    pthread_join(t2, (void **)&n2);
    printf("Sum = %d", *n1 + *n2);
    return 0;
}