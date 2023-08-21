/* Replace Spaces with Minus signs */

#include<stdio.h>
char arr[30];
int replace()
{
    int spaceCount = 0;
    for(int i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == ' ')
        {
            arr[i] = '-';
            spaceCount++;
        }
    }
    return spaceCount;
}

void main()
{
    printf("Enter a string : ");
    scanf("%[^\n]s", &arr);
    printf("String : %s\nSpaces : %d", arr, replace(arr));
}
