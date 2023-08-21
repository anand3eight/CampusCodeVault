/* Longest Increasing Subsquence */

#include<stdio.h>

void main()
{
    int arr[7] = {1, 8, 5, 3, 6, 7, 2};
    int lis[7];
    int i, j;
    lis[0] = 1;
    for(i = 1; i < 7; i++)
    {
        lis[i] = 1;
        for(j = 0; j < i; j++)
        {
          if(arr[j] < arr[i]  &&  lis[i] < lis[j] + 1)
              lis[i] = lis[j] + 1;
        }
    }
    int max = lis[0];
    for(i = 0; i < 7; i++)
    {
        if(lis[i] > max)
          max = lis[i];
          printf("%d ", lis[i]);
    }
    printf("\nMax = %d", max);
}
