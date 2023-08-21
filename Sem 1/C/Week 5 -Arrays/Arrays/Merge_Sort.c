/* Merge Sort - To sort a merged array */

#include<stdio.h>

void main()
{
    int i = 0, a[5] = {2, 5, 7, 16, 21};
    int j = 0, b[5] = {3, 8, 10, 13, 15};
    int k, merged[10];
    for(k = 0; k < 10; k++ )
    {
      if(i < 5 && j < 5)
      {
        if(a[i] <= b[j])
        {
            merged[k] = a[i];
            i++;
        }
        else
        {
            merged[k] = b[j];
            j++;
        }
      }
      else
      {
        if(i < 5)
        {
          merged[k] = a[i];
          i++;
        }
        else
        {
          merged[k] = b[j];
          j++;
        }
      }
    }
    printf("ARRAY ");
    for(k = 0; k < 10; k++)
    {
      printf("%d ", merged[k]);
    }
}
