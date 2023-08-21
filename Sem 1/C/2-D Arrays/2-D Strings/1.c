/* Print Number Of a's in a string */

#include<stdio.h>

void main()
{
    char strList[5][30];
    int row, col, aCount;
    printf("Enter 5 Strings : ");
    for(row = 0; row < 5; row++)
     {
        scanf("%s", strList[row]);
     }
    for(row = 0; row < 5; row++)
    {
        aCount = 0;
        for(col = 0; strList[row][col] != '\0'; col++)
        {
            if(strList[row][col] == 'a' || strList[row][col] == 'A')
                aCount++;
        }
        printf("%s has %d (A)s\n", strList[row], aCount);
    }
}
