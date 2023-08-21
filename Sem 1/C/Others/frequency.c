#include<stdio.h>
void main()
{
    int a[5];
    int b, i;
    int count = 0;
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &b);
    for(i = 0; i < 5; i++)
    {
        if(b == a[i])
            count++;
    }
    printf("%d", count);
}
