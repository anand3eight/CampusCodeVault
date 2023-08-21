/* Selection Sort - Decending Order*/

#include<stdio.h>

void main()
{
    int size;
    printf("Enter The Array Size : ");
    scanf("%d", &size);
    int arr[size];
    int i, j, temp;
    //Input of Array Elements
    printf("Enter The Array :\n");
    for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
    for(i = 0; i < size; i++)
    {
      for(j = i+1; j < size; j++)
      {
          if(arr[j] >= arr[i])
              {
                  temp = arr[j];
                  arr[j] = arr[i];
                  arr[i] = temp;
              }
      }
    }
    printf("ARRAY ");
    for(i = 0; i < size; i++)
    {
      printf("%d ", arr[i]);
    }
}
