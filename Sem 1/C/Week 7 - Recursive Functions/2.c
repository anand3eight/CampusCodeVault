/* Sum of Digits of a Number */

#include<stdio.h>

int sod(int num)
{
    if(num > 0) return (num % 10) + sod(num/10);
}
void main()
{
    int num;
    printf("Enter a Number : ");
    scanf("%d", &num);
    printf("SOD of %d is %d", num, sod(num));
}
