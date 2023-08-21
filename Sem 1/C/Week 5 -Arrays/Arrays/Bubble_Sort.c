/* Bubble Sort - Largest to Last */

#include<stdio.h>

void main()
{
    int a[5] = {9, 8, 7, 6, 5};
    int i, j, temp;
    for(j = 0; j < 5; j++)
    {
      for(i = 0; i < 5-j; i++)
      {
        temp = a[i+1];
        if(a[i] > a[i+1])
        {
            a[i+1] = a[i];
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
