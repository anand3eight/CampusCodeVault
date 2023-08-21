/* Amicable Numbers Checker */

#include<stdio.h>

void main()
{
    int num1, num2, sum1 = 0, sum2 = 0;
    printf("Enter Two Numbers : ");
    scanf("%d%d", &num1, &num2);
    int div1, div2;
    for(div1 = 1; div1 < num1 ; div1++)
    {
        if(num1 % div1 == 0)   sum1 += div1;
    }
    for(div2 = 1; div2 < num2 ; div2++)
    {
        if(num2 % div2 == 0)  sum2 += div2;
    }
    if((sum1 == num2)  &&  (sum2 == num1))    printf("Amicable Numbers");
    else    printf("Not Amicable Numbers");
}
