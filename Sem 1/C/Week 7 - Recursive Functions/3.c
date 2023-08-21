/* Find Sum of first n Natural Numbers */

#include<stdio.h>

int sumUptoN(int n)
{
    if(n > 0) return n + sumUptoN(n-1);
}
void main()
{
    int n;
    printf("Enter a Number : ");
    scanf("%d", &n);
    printf("Sum Upto %d is %d", n, sumUptoN(n));
}
