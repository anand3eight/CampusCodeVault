/* Print Negative Numbers In An Array */

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
  for(i = 0; i < size; i++)
  {
      if(arr[i] < 0)    printf("%d ", arr[i]);
  }
}
