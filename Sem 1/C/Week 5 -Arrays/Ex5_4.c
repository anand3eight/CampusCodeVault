/* Bitonic Sequence Problem */

#include<stdio.h>

void main()
{
  int size;
  printf("Enter The Array Size : ");
  scanf("%d", &size);
  int arr[size], i, j;
  //Input of Array Elements
  printf("Enter Array : ");
  for(i = 0; i < size; i++)
      {
        scanf("%d", &arr[i]);
      }
//Calculating Bitonic Length Values using Arrays
int lis[size], lds[size], bitonic[size];
lis[0] = 1;
lds[0] = 1;
bitonic[0] = 1;
for(i = 1; i < size; i++)
    {
      lis[i] = 1;
      lds[i] = 1;
      for(j = 0; j < i; j++)
        {
          if(arr[j] < arr[i]  &&  lis[i] < lis[j] + 1)
              lis[i] = lis[j] + 1;
          if(arr[i] < arr[j]  &&  lds[i] < lds[j] + 1)
              lds[i] = lds[j] + 1;
          bitonic[i] = (lis[i] + lds[i]) - 1;
        }
    }
//Calculating Maximum Of Bitonic Length Array
int max = bitonic[0];
for(i = 0; i < size; i++)
    {
        if(bitonic[i] > max)
          max = bitonic[i];
    }
printf("\nMax = %d", max);
}
