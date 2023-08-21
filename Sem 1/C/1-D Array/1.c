/* Reverse An Array */

#include<stdio.h>

void main()
{
  int size;
  printf("Enter The Array Size : ");
  scanf("%d", &size);
  int arr[size], i;
  //Input of Array Elements
  printf("Enter The Array :\n");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
  int tempArr[size], j = 0;
  for(i = size-1; i >= 0; i--, j++)
  {
      tempArr[j] = arr[i];
  }
  for(i = 0; i < size; i++)
  {
    printf("%d ", tempArr[i]);
  }
}
