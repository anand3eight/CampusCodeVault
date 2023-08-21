/* Selection Sort - Smallest to First*/

#include<stdio.h>

void main()
{
    int a[5] = {9, 6, 8, 4, 5};
    int i, j, temp;
    for(i = 0; i < 5; i++)
    {
      for(j = i+1; j < 5; j++)
      {
          temp = a[j];
          if(a[j] <= a[i])
              {
                  a[j] = a[i];
                  a[i] = temp;
              }
      }
    }
    printf("ARRAY ");
    for(i = 0; i < 5; i++)
    {
      printf("%d ", a[i]);
    }
}
