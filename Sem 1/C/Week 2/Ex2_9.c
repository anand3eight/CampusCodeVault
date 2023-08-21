/* 9. In a certain insurance agency,
you get a 30% discount on your yearly premium if you had no
accidents last year. Women drivers also get
a 5% extra discount on their yearly premium. Write
a program to input the normal premium and
output the premium the customer must pay, making
necessary discounts if any. */

#include<stdio.h>

void main()
{
    float premium = 0.0;
    int ch1, ch2 ;
    printf("Enter Your Premium : ");
    scanf("%f", &premium);
    printf("Have You Met with any Accident Last year? - (1 - yes/2 - no) : ");
    scanf("%d", &ch1);
    if(ch1 == 2)
    {
        premium -= 0.30 * premium ;
    }
    printf("\nAre you A Woman? - (1 - yes/2 - no) : ");
    scanf("%d", &ch2);
    if(ch2 == 1 )
    {
        premium -= 0.05 * premium ;
    }
    printf("Your Premium = %f ", premium);

}
