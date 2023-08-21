#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *input()
{
    char *arr = (char *)malloc(sizeof(char) * 20);
    printf("Enter : ");
    scanf("%s", arr);
    pthread_exit(arr);
}

int main()
{
    pthread_t t1, t2;
    char *s1, *s2;
    pthread_create(&t1, NULL, &input, NULL);
    pthread_join(t1, (void **)&s1);
    pthread_create(&t2, NULL, &input, NULL);
    pthread_join(t2, (void **)&s2);
    printf("%s %s", s1, s2);
    return 0;
}