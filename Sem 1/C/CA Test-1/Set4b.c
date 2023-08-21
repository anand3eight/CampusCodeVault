/* Income Tax Problem */

#include<stdio.h>

void main()
{
    double income, tax, multiplier, subValue;
    printf("Enter Your Income : ");
    scanf("%lf", &income);
    if((income >= 100000.00) && (income < 117250.00))
    {
        multiplier = 0.25;
        subValue = 6525.00;
    }
    else if((income >= 117250.00) && (income < 178650.00))
    {
        multiplier = 0.28;
        subValue = 10042.50;
    }
    else if((income >= 178650.00) && (income < 319100.00))
    {
        multiplier = 0.33;
        subValue = 18975.00;
    }
    else
    {
        multiplier = 0.35;
        subValue = 25357.00;
    }
    tax = (income * multiplier) - subValue;
    printf("Tax = %.2lf", tax);
}
