/* Reverse a String with Return */

#include<stdio.h>
#include<string.h>

const char* reverse(char arr[], char rev[], int len, int i)
{
    if(len > 0)
    {
        rev[i] = arr[len -1];
        reverse(arr, rev, len -1, i+1);
    }
    else
        return rev;

}
void main()
{
    char arr[30], rev[30] = "0";
    printf("Enter a String : ");
    scanf("%s", arr);
    printf("Reversed String is %s", reverse(arr, rev, strlen(arr), 0));
}
