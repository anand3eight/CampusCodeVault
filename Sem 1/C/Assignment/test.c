#include<stdio.h>

void main()
{
    int a = 5, *p;
    p = &a;
    (*p)++;
    printf("%d", a);
}
