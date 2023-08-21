/* 1. Write a program to compute the sum of two numbers.
The addition operation should be carried
out only when both the number are non-negative. */

#include<stdio.h>

void main()   {
  int n1, n2 ;
  printf("Enter Two Numbers : ");
  scanf("%d%d", &n1, &n2);
  if(n1 > 0 && n2 > 0)
    {
      int add = n1 + n2 ;
      printf("\nThe Sum = %d", add);
    }
}
