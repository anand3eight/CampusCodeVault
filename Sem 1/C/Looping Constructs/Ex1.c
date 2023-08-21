/* Given a three digit number, write a program
to find the reverse of the given number. */

#include<stdio.h>

void main()
{
    int num, check, rev = 0, rem = 0;
    printf("\nEnter A Number : ");
    scanf("%d", &num);
    check = num;
    for(rem = 0; num > 0; num /= 10)
    {
        rem = num%10;
        rev = rev*10 + rem;
    }
    printf("Reverse of %d is %d", check, rev);
}
