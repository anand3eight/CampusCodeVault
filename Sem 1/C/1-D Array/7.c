/* To find a Pair Of Numbers That Give the Desired Sum */
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
  int sum = 0;
  printf("Enter the Desired Sum : ");
  scanf("%d", &sum);
  for(i = 0; i < size; i++)
  {
      for(j = i+1 ; j < size; j++)
        {
            if(arr[i]+arr[j] == sum)
            {
                printf("%d,%d\n", arr[i], arr[j]);
                break;
            }
        }
  }
}
