/* student Average Problem */

#include<stdio.h>

void main()
{
    char names[5][25];
    int marks[5][4];
    float avg[5];
    char grade[5];
    int i, j, sum;
    printf("Enter Names : ");
    for(i = 0; i < 5; i++)
        {
          scanf("%s", names[i]);
        }
    printf("Enter Marks : ");
    for(i = 0; i < 5; i++)
            {
              sum = 0;
              for(j = 0; j < 4; j++)
              {
                  scanf("%d", &marks[i][j]);
                  sum += marks[i][j];
              }
              avg[i] = sum/4;
              if(avg[i] >= 90  &&  avg[i] <= 100)   grade[i] = 'A';
              else if(avg[i] >= 80  &&  avg[i] <= 89)   grade[i] = 'B';
              else if(avg[i] >= 70  &&  avg[i] <= 79)   grade[i] = 'C';
              else if(avg[i] >= 60  &&  avg[i] <= 69)   grade[i] = 'D';
              else if(avg[i] >= 0  &&  avg[i] <= 59)   grade[i] = 'E';
              printf("\n");
            }

    for(i = 0; i < 5; i++)
    {
        printf("\n%-8s\t%.2f\t%c", names[i], avg[i], grade[i]);
    }
}
