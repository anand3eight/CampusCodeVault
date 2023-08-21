//Array of Pointers

#include<stdio.h>
#include<stdlib.h>

void main()
{
    int *p[5];
    int a = 1, b = 2, c = 3, d = 4, e = 5;
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    p[3] = &d;
    p[4] = &e;
    for(int i = 0; i < 5; i++)
    {
        printf("Address is %d and Value is %d\n", (p+i), *p[i]);
    }
}
