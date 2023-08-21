/* Perfect number is a positive number
whose sum of positive divisors excluding the number itself,
are equal to the number itself.
Example:
Number: 6
Divisors: 1,2,3
Sum of Divisors: 1+2+3 = 6
Hence, the given number is a perfect number */

#include<stdio.h>

void main()
{
    int num, i, sum = 0;
    printf("Enter A Number = ");
    scanf("%d", &num);
    for(i = 1; i < num; i++)
    {
        if(num%i == 0)
            sum += i;
    }
    if(sum == num)  printf("Perfect Number");
    else printf("Not A Perfect Number");
  }
