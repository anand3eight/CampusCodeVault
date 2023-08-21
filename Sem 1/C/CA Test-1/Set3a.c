/* Hamming Distances Problem */

#include<stdio.h>
void main()
{
    int num1, num2;
    printf("Enter Two Numbers : ");
    scanf("%d%d", &num1, &num2);
    int i, mask = 1;
    int count = 0;
    int ch1, ch2;
    mask = 1<<4;
    for(i = 1; i <= 5; i++)
    {
        ch1 = num1 & mask ? 1 : 0 ;
        ch2 = num2 & mask ? 1 : 0 ;
        if(ch1 != ch2)  count++;
        num1 <<= 1;
        num2 <<= 1;

    }
    printf("%d", count);


}
