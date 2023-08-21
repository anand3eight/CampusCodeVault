/* Power of a number */

#include<stdio.h>

int power(int a, int n)
{
    if(n > 0) return a * power(a, n-1);
    else  return 1;
}
void main()
{
    int a, n;
    printf("Enter values for a and n :");
    scanf("%d%*c%d", &a, &n);
    printf("%d raised to power %d is %d", a, n, power(a, n));
}
