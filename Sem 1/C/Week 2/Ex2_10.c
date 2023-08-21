/* 10. We want to calculate the bill of a customer
staying at our hotel. The price of a single room is
200 $ and the price of a double room is 250 $.
You get a discount of 5% if you stay more than
10 nights. You also get an extra 2% discount if you pay cash.
The bill should include 12% VAT. */

#include<stdio.h>

void main()
{
    int stay_days, s = 200, d = 250;
    float vat, total;
    char ch1;
    int ch2 ;
    printf("Which Room Did You stay ? (s-Single/d-Double)");
    scanf("%c", &ch1);
    printf("Enter The Number Of Days You Stayed : ");
    scanf("%d", &stay_days);
    if(ch1 == 's')
    {
        total = s * stay_days;
    }
    else if(ch1 == 'd')
    {
        total = d * stay_days;
    }
    else
    {
        printf("Enter A Valid Choice");
    }
    if(stay_days >= 10)
    {
        total -= 0.05*total;
    }
    printf("Do You Pay With Cash now? - (1-yes)/(2-no) : ");
    scanf("%d", &ch2);
    if(ch2 == 1)
    {
        total -= 0.02*total;
    }
    vat = 0.12*total;
    total += vat;
    printf("Pay %f", total);
}
