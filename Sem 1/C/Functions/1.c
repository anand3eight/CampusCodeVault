/* Palindrome Discount Problem */

#include<stdio.h>

int length(char arr[])
{
    int count = 0;
    for(count = 0; arr[count] != '\0'; count++);
    return count;
}
int palindrome(char arr[])
{
    int count = length(arr);
    int i;
    char rev[count];
    for(i = 0; i < count; i++)
    {
        rev[i] = arr[count-i-1];
    }
    int check = 0;
    for(i = 0; i < count; i++)
    {
        if(rev[i] == arr[i])   check = 1;
        else
        {
            check = 0;
            break;
        }
    }
    return check;
}
float getDetails()
{
    int contactno, totalCost;
    char address[50], name[20];
    printf("Enter Name without caps : ");
    scanf("%s", name);
    printf("Enter Address : ");
    scanf("%s", address);
    printf("Enter Contact Number : ");
    scanf("%d", &contactno);
    printf("Enter Total : ");
    scanf("%d", &totalCost);
    int check = palindrome(name);
    if(check == 1)  return 0.90 * totalCost;
    else  return totalCost;
}
void main()
{
    printf("Total = %.2f", getDetails());
}
