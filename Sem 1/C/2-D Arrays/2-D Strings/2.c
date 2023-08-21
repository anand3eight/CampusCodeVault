/* Print Strings That starts with S */

#include<stdio.h>

void main()
{
    char strList[5][30];
    int row;
    printf("Enter 5 Strings : ");
    for(row = 0; row < 5; row++)
     {
        scanf("%s", strList[row]);
     }
    printf("Strings Starting with S :\n");
    for(row = 0; row < 5; row++)
    {
        if(strList[row][0] == 's' || strList[row][0] == 'S')
            printf("%s\n", strList[row]);
    }
}
