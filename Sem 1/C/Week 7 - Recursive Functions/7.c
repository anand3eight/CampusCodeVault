/* Reversing a Sring */
#include<stdio.h>
#include<string.h>
char rev[30];
void reverse(char arr[], int len, int i)
{
    if(len > 0)
    {
        rev[i] = arr[len-1];
        reverse(arr, len-1, i+1);
    }
    else
    {
      printf("Reversed String is %s", rev);
    }
}
void main()
{
    char arr[30];
    printf("Enter a String : ");
    scanf("%s", arr);
    reverse(arr, strlen(arr), 0);
}
