/* Fibonacci Series */

#include<stdio.h>

int Fibonacci(int n)
{
    if(n == 0)  return 1;
    else if(n == 1)  return 0;
    else  return Fibonacci(n-1) + Fibonacci(n-2);
}
void main()
{
    int num;
    printf("Enter the Term : ");
    scanf("%d", &num);
    printf("Fibonacci Term %d is %d", num, Fibonacci(num));
}
