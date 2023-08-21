/* Sum of Two using Pointers */

#include<stdio.h>

void sum(int *a, int *b, int *c)
{
    *c = *a + *b;
}

void main()
{
   int n1, n2, n3;
   printf("Enter Two Numbers :\n");
   scanf("%d %d", &n1, &n2);
   sum(&n1, &n2, &n3);
   printf("Sum = %d", n3);
}
