/* Run Length encoding Problem */
#include<stdio.h>

void runLengthEncoding(char arr[])
{
    int i = 1, count = 1;
    for(i = 1; i <= 8; i++)
    {
        if(arr[i] == arr[i-1])  count++;
        else
        {
            printf("%c%d", arr[i-1], count);
            count = 1;
        }
    }
}
void main()
{
    char arr[8] = "aaaggcdd";
    runLengthEncoding(arr);
}
