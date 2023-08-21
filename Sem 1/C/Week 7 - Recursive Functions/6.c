/* Decimal to Binary */
#include<stdio.h>

int dTob(int n, int count)
{
    if(count > 0)
    {
       int mask = 1<<6;
       n & mask ? printf("1") : printf("0");
       return dTob(n<<1, count-1);
    }
}
void main()
{
  int num;
  printf("Enter the Number : ");
  scanf("%d", &num);
  printf("Binary Equivalent of %d is ", num);
  dTob(num, 7);
}
