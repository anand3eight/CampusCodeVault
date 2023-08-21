/* Partitioning An Array */

#include<stdio.h>
#include<stdlib.h>

void main()
{
  int size;
  printf("Enter The Array Size : ");
  scanf("%d", &size);
  int arr[size], i, j, k;
  int diff[size], before_sum = 0, after_sum = 0;
  //Array Input
  printf("Enter Array :\n");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
  //Calculating Absolute Difference and Storing in an Array
  for(i = 0; i < size; i++)
  {
      before_sum = 0;
      after_sum = 0;
      for(j = 0; j < i+1 ; j++)
      {
          before_sum += arr[j];
      }
      for(k = i+1; k < size; k++)
      {
          after_sum += arr[k];
      }
      diff[i] = abs(before_sum - after_sum);
  }
  //Finding Min Value
  int min = diff[0];
  for(i = 0; i < size; i++)
  {
      if(diff[i] <= min)
          min = diff[i];
  }
  //Finding Min value Index
  for(i = 0; i < size; i++)
  {
      if(min == diff[i])
      {
          printf("\nAnswer = %d", i);
          break;
      }
  }


}
