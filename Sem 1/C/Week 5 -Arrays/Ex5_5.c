/* The police training academy wants to survey the
reports of new joiners of n men. The different parameters
used to select the best men
are height, weight, age and chest in cms.
Write a program to find the men who are eligible to be selected.
1. Age should be greater than 18 and less than 25
2. Height should be greater than 5.7 and less than 6.0 inches
3. Weight should be greater than 45 and less than 60 kg.
4. Chest should be greater than 45 cms.

Input Format
The first line of the input consists of the number of entries n.
Next n lines has space separated integers age height weight
and chest measurements of ith person.  */

#include<stdio.h>

void main()
{
  int size;
  printf("Enter The Number Of Entries: ");
  scanf("%d", &size);
  int arr[size][4], i, j;
  float height_arr[size];
  int sum = 0;
  printf("Enter the Details Of : ");
  for(i = 0; i < size; i++)
      {
        printf("\n%d : Enter Age, Height, Weight, Chest : \n", i);
        for(j = 0; j < 4; j++)
        {
            if(j == 1) scanf("%f", &height_arr[i]);
            else scanf("%d", &arr[i][j]);
        }

      }
printf("Selected Entries : ");
for(i = 0; i < size; i++)
{
  if((arr[i][0] > 18 && arr[i][0] < 25) && ((double)height_arr[i] > 5.7 && (double)height_arr[i] < 6.0) && (arr[i][2] >= 45 && arr[i][2] <= 60) && (arr[i][3] > 45))
  		printf("%d ", i);
}


}
