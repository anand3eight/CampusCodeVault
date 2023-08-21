/* question 3 */

#include<stdio.h>

void main()
{
    char strList[5][5];
    int row, col ;
    printf("Enter 3 Characters : ");
    char a, b, c;
    scanf("%c\n%c\n%c", &a, &b, &c);
    for(row = 0; row < 5; row++)
    {
        for(col = 0; col < 5; col++)
        {
            if((row == 0 || row == 4) && (col == 0 || col == 4))
                strList[row][col] = a;
            else if((row == 0 || row == 4) || (col == 0 || col == 4))
                strList[row][col] = b;
            else
                strList[row][col] = c;
        }
    }
    for(row = 0; row < 5; row++)
    {
      for(col = 0; col < 5; col++)
      {
        printf("%c\t", strList[row][col]);
      }
      printf("\n");
    }

}
