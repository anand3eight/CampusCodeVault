/* To find Duplicate Elements In An Array */

#include<stdio.h>

void main()
{
  int size;
  printf("Enter The Array Size : ");
  scanf("%d", &size);
  int arr[size], i, j;
  //Input of Array Elements
  printf("Enter The Array :\n");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
  printf("Duplicate Elements ");
  for(i = 0; i < size; i++)
  {
      for(j = i+1 ; j < size; j++)
      {
          if(arr[j] == arr[i])
          {
              printf("%d ", arr[i]);
              break;
          }
      }
  }
}
