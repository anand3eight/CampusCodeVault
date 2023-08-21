/* Tiplets Problem */

#include<stdio.h>
void tripletSum(int arr[], int size)
{
  int i, j, k;
    for(i = 0; i < size; i++)
    {
      for(j = i+1; j < size; j++)
      {
        for(k = j+1; k < size; k++)
        {
          if(arr[i] + arr[j] + arr[k] == 0)
          {
            printf("[%d, %d, %d]", arr[i], arr[j], arr[k]);
            arr[j] = 1000;
            arr[k] = 1000;
          }
        }
      }
    }
}
void main()
{
  int size;
  printf("Enter The Array Size : ");
  scanf("%d", &size);
  int arr[size], i;
  //Input of Array Elements
  printf("Enter Array : ");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
  tripletSum(arr, size);
}
