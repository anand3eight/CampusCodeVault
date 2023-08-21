/* Pell number Function */

#include<stdio.h>

int pellnum(int n)
{
    if(n == 0)      return 0;
    else if(n == 1) return 1;
    else            return (2 * pellnum(n-1)) + pellnum(n-2);
}
void main()
{
  int num;
  printf("Enter the Term : ");
  scanf("%d", &num);
  printf("Pell Term %d is %d", num, pellnum(num));
}
